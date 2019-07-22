//
// Created by Marc Haubenstock on 2019-07-07.
//

#ifndef IMAGELIB_IMAGE_H
#define IMAGELIB_IMAGE_H

#include <assert.h>
#include <Eigen/Dense>
#include "types.h"
#include "CImg.h"

using namespace Eigen;
using namespace cimg_library;
using namespace image_types;

class Image {
public:
    ImageEncoding original_encoding;
    ImageFilter image_filter;
    bool is_standardized;
    Matrix<image_types::image_data, Dynamic, Dynamic> image_matrix;

    static unsigned char normalize_pixel_to_display(image_data min, image_data max, image_data value);
    template <typename T> static Image from_CImg(bool standardize, ImageFilter imageFilter, const CImg<T>& c_image);
    static CImg<unsigned char> to_CImg_U8(const Image &image);
    template <typename T> static CImg<T> CImg_RGB_to_Gray(float r_coef, float g_coeff, float b_coeff, const CImg<T>& c_image);
    template <typename T> static CImg<image_data> filter(ImageFilter image_filter, const CImg<T>& c_image);
    template <typename T> static CImg<T> blur_downsample(const CImg<T>& prev, float sigma);

    Image(ImageEncoding image_encoding, bool is_standardized, ImageFilter imageFilter, const Matrix<image_data, Dynamic, Dynamic>& image_matrix);
    Image(const Image &image);
};

#include "image.inl"

#endif //IMAGELIB_IMAGE_H