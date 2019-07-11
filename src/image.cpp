//
// Created by Marc Haubenstock on 2019-07-07.
//

#include "image.h"
#include "numerics.h"

// https://en.wikipedia.org/wiki/Normalization_(image_processing)
unsigned char Image::normalize_pixel_to_display(image_data min, image_data max, image_data value){

    //TODO: add more ranges
    auto range = 255.0;

    auto display_value = (value - min) * (range / (max - min));

    return (unsigned char)display_value;
}



CImg<unsigned char> Image::to_CImg(const Image &image) {
    auto image_matrix = &image.image_matrix;
    auto width = image_matrix->cols();
    auto height = image_matrix->rows();
    auto max = image_matrix->maxCoeff();
    auto min = image_matrix->minCoeff();

    CImg<unsigned char> c_img(width,height);

    cimg_forXY(c_img,x,y) {
        auto val = image_matrix->operator()(y,x);
        c_img(x,y) = normalize_pixel_to_display(min, max, val);
    }

    return c_img;
}

Image::Image(const Image &image) {
    original_encoding = image.original_encoding;
    image_matrix = image.image_matrix;
    is_standardized = image.is_standardized;
    image_filter = image.image_filter;
}

Image::Image(ImageEncoding image_encoding, bool is_standardized, ImageFilter imageFilter, const Matrix<image_data, Dynamic, Dynamic>& image_matrix) {
    this->original_encoding = image_encoding;
    this->is_standardized = is_standardized;
    this->image_filter = imageFilter;
    this->image_matrix = image_matrix;
}






