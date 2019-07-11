//
// Created by Marc Haubenstock on 2019-07-10.
//

#ifndef IMAGELIB_NUMERICS_H
#define IMAGELIB_NUMERICS_H

#include <Eigen/Dense>
#include "CImg.h"
#include "types.h"

using namespace Eigen;
using namespace cimg_library;

namespace numerics {
    void z_standardize(Matrix<image_data, Dynamic, Dynamic>& matrix);
    template <typename T> CImg<image_data> z_standardize(const CImg<T>& c_image);

    //@GPU
    // https://en.wikipedia.org/wiki/Kernel_(image_processing)
    // Actually the kernel has to be flipped accross x and y? But kernels seem to work as is
    Matrix<image_data, Dynamic, Dynamic> filter3x3(const Matrix<image_data, 3, 3>& kernel, const Matrix<image_data , Dynamic, Dynamic>& matrix);

}

#include "numerics.inl"

#endif //IMAGELIB_NUMERICS_H
