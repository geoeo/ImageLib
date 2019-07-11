//
// Created by Marc Haubenstock on 2019-07-10.
//

#include "numerics.h"

namespace numerics {

    namespace helper_numerics {

        bool is_within_kernel_bounds(int i, int j, int width, int height) {

            auto is_j_in_range = j >= 0 && j < height;
            auto is_i_in_range = i >= 0 && i < width;
            return is_j_in_range && is_i_in_range;
        }

    }

    // Not used anymore. Using CImg functions instead
    //TODO: Remove
    void z_standardize(Matrix<image_data, Dynamic, Dynamic> &matrix) {
        auto width = matrix.cols();
        auto height = matrix.rows();

        auto mean = matrix.mean();
        auto ones = Matrix<image_data, Dynamic, 1>::Ones(width*height);
        auto mean_vec = mean*ones;
        Matrix<image_data, Dynamic, 1> vec(Map<Matrix<image_data, Dynamic, 1>>(matrix.data(), width*height));
        float std_dev =  std::sqrt((vec - mean_vec).array().square().sum()/(vec.size()-1));
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++) {
                auto val = matrix(j,i);
                matrix(j,i) = (val - mean)/std_dev;
            }
        }
    }

    Matrix<image_data, Dynamic, Dynamic> filter3x3(const Matrix<image_data, 3, 3> &kernel,
                                                   const Matrix<image_data, Dynamic, Dynamic>& matrix) {
        auto width = matrix.cols();
        auto height = matrix.rows();
        auto kernel_size = 3;
        auto kernel_min = (kernel_size-1.0)/2.0;

        Matrix<image_data, Dynamic, Dynamic> filtered = Matrix<image_data, Dynamic, Dynamic>::Zero(height, width);
        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                auto acc = 0.0;
                auto out_of_range_flag = false;
                for(int i = 0; i < kernel_size; i++){
                    for(int j = 0; j < kernel_size; j++){
                        auto i_matrix = x + i - kernel_min;
                        auto j_matrix = y + j - kernel_min;
                        auto is_within_bounds = helper_numerics::is_within_kernel_bounds((int)i_matrix,(int)j_matrix,width,height);
                        if (is_within_bounds) {

                            auto kernel_value = kernel(j,i);
                            auto matrix_value = matrix((int)j_matrix ,(int)i_matrix);
                            acc += kernel_value*matrix_value;
                        }
                        else {
                            //TODO: implement different bound behaviours
                            out_of_range_flag = true;
                        }
                    }
                }

                if(out_of_range_flag)
                    filtered(y,x) = 0.0;
                else
                    filtered(y,x) = acc;
            }
        }

        return filtered;
    }


}





