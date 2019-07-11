#include "numerics.h"


template <typename T> CImg<image_data> numerics::z_standardize(const CImg<T>& c_image) {


    T mean = 0;
    // 1 - best unbiased estimator
    auto var = c_image.variance_mean(1, mean);
    auto std_dev = std::sqrt(var);
    auto width = c_image.width();
    auto height = c_image.height();

    CImg<image_data> standardized_image(width, height);

    cimg_forXY(c_image,x,y) {
            auto val = c_image(x,y);
            auto standardized = (val - mean)/std_dev;
            standardized_image(x,y) = (image_data)standardized;
        }

    return standardized_image;
}