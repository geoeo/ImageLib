//
// Created by Marc Haubenstock on 2019-07-07.
//

#ifndef IMAGELIB_TYPES_H
#define IMAGELIB_TYPES_H

#include <cstdint>

enum ImageFilter : uint8_t {
    NoFilter,
    SobelX,
    SobelY,
    RotInvX,
    RotInvY
};

enum ImageEncoding : uint8_t {
    NotSupported,
    U8,
    U16,
    S16,
    F32,
    F64
};

typedef double image_data;

// CImage typedefs

//-1 = Backward finite differences
//0 = Centered finite differences
//1 = Forward finite differences
//2 = Using Sobel kernels
//3 = Using rotation invariant kernels
//4 = Using Deriche recusrsive filter.
//5 = Using Van Vliet recusrsive filter.

// 0: Second moment,
//1: Best unbiased estimator
//2: Least median of squares.
//3: Least trimmed of squares.

#endif //IMAGELIB_TYPES_H