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
    ScharrX,
    ScharrY
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

#endif //IMAGELIB_TYPES_H