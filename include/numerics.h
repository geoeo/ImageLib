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
using namespace image_types;

namespace numerics {
    template <typename T> CImg<image_types::image_data> z_standardize(const CImg<T>& c_image);
}

#include "numerics.inl"

#endif //IMAGELIB_NUMERICS_H
