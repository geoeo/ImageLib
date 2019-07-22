#include <iostream>
#include <string>
#include <sstream>
#include <string_view>
#include "image.h"
#include "CImg.h"

using namespace cimg_library;

constexpr std::string_view get_data_path() {return "/Users/marchaubenstock/Workspace/C++/ImageLib/data/";}

int main() {
    std::string lena = "lena.png";
    std::string depth = "depth.png";

    std::stringstream ss_lena;
    ss_lena << get_data_path() << lena;
    auto image_path_lena = ss_lena.str();
    auto image_path_lena_c_str = image_path_lena.c_str();

    std::stringstream ss_depth;
    ss_depth << get_data_path() << depth;
    auto image_path_depth = ss_depth.str();
    auto image_path_depth_c_str = image_path_depth.c_str();

    CImg<unsigned char> image(image_path_lena_c_str);
    CImg<short> image_depth(image_path_depth_c_str);
    CImg<unsigned char> gray = Image::CImg_RGB_to_Gray(0.33, 0.33, 0.33, image);

    CImg<unsigned char> gray_blurred = Image::blur_downsample(gray,5.0);

    auto my_image = Image::from_CImg(true,ImageFilter::SobelY, gray);
    auto my_depth_image = Image::from_CImg(true,ImageFilter::NoFilter, image_depth);

    auto disp_image = Image::to_CImg_U8(my_image);
    auto disp_depth_image = Image::to_CImg_U8(my_depth_image);

    //CImgDisplay main_disp(image_depth,"Original"),draw_disp(disp_depth_image,"Converted");
    CImgDisplay main_disp(gray,"Original"),draw_disp(gray_blurred,"Blurred");


    while (!main_disp.is_closed() && !draw_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}