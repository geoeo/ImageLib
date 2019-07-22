#include <typeinfo>   // operator typeid
#include "types.h"
#include "image.h"
#include "numerics.h"

template <typename T> inline Image Image::from_CImg(bool standardize, ImageFilter image_filter,const CImg<T>& c_image){
    auto width = c_image.width();
    auto height = c_image.height();
    auto channels = c_image.spectrum();

    assert(channels == 1);

    //TODO: Clean this up
    CImg<image_data> standardized_image(width, height);
    if (standardize)
        standardized_image = numerics::z_standardize(c_image);

    //filter
    auto filtered_image = standardize ? Image::filter(image_filter, standardized_image) : Image::filter(image_filter, c_image);

    Matrix<image_data, Dynamic, Dynamic> image_matrix(height, width);
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++) {
            auto pixel_value = filtered_image._atXY(i,j);
            image_matrix(j,i) = pixel_value;
        }
    }

    //TODO: refactor this
    // encoding
    const std::type_info& tinfo = typeid(T);
    auto is_u8 = tinfo == typeid(u_char);
    auto is_u16 = tinfo == typeid(u_int16_t);
    auto is_s16 = tinfo == typeid(int16_t);
    auto is_f32 = tinfo == typeid(float_t);
    auto is_f64 = tinfo == typeid(double_t);

    ImageEncoding image_encoding = ImageEncoding::NotSupported;

    if(is_u8)
        image_encoding = ImageEncoding ::U8;
    else if(is_u16)
        image_encoding = ImageEncoding ::U16;
    else if(is_s16)
        image_encoding = ImageEncoding ::S16;
    else if(is_f32)
        image_encoding = ImageEncoding ::F32;
    else if(is_f64)
        image_encoding = ImageEncoding ::F64;


    return Image(image_encoding,standardize,image_filter, image_matrix);

}

template <typename T> inline CImg<image_data> Image::filter(ImageFilter image_filter, const CImg<T>& c_image) {

    auto width = c_image.width();
    auto height = c_image.height();

    CImg<float> filtered_image(width, height);
    switch(image_filter){
        case ImageFilter::NoFilter:
            filtered_image = c_image;
            break;
        case ImageFilter::SobelX:
            filtered_image = c_image.get_gradient("x",2)[0];
            break;
        case ImageFilter::SobelY:
            filtered_image = c_image.get_gradient("y",2)[0];
            break;
        case ImageFilter::RotInvX:
            filtered_image = c_image.get_gradient("x",3)[0];
            break;
        case ImageFilter::RotInvY:
            filtered_image = c_image.get_gradient("y",3)[0];
            break;
    }

    return filtered_image;

}

template <typename T> inline CImg<T> Image::CImg_RGB_to_Gray(float r_coef, float g_coeff, float b_coeff, const CImg<T>& c_image) {
    auto width = c_image.width();
    auto height = c_image.height();
    auto channels = c_image.spectrum();

    assert(channels == 3);

    CImg<T> gray(width, height);

    cimg_forXY(c_image,x,y) {
            auto R = (T)c_image(x,y,0,0);
            auto G = (T)c_image(x,y,0,1);
            auto B = (T)c_image(x,y,0,2);

            // Arithmetic addition of channels for gray
            auto grayValue = (T)(r_coef*R + g_coeff*G + b_coeff*B);
            gray(x,y) = grayValue;
    }

    return gray;
}

template <typename T> inline CImg<T> Image::blur_downsample(const CImg<T> &prev, float sigma) {
    CImg<T> blurred = prev.get_blur(sigma,0,true);
    return blurred.resize_halfXY();
}