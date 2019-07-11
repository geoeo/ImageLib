#include <iostream>
#include <string>
#include <sstream>
#include <string_view>
#include "image.h"
#include "CImg.h"

using namespace cimg_library;

constexpr std::string_view get_data_path() {return "/Users/marchaubenstock/Workspace/C++/ImageLib/data/";}

int main() {
    std::stringstream ss;
    ss << get_data_path() << "lena.png";
    auto image_path = ss.str();
    auto image_path_c_str = image_path.c_str();

    CImg<unsigned char> image(image_path_c_str);
    CImg<unsigned char> gray = Image::CImg_RGB_to_Gray(0.33, 0.33, 0.33, image);

    auto my_image = Image::from_CImg(true,ImageFilter::SobelY, gray);
    auto disp_image = Image::to_CImg(my_image);

    CImgDisplay main_disp(image,"Original"),draw_disp(disp_image,"Gray");


    while (!main_disp.is_closed() && !draw_disp.is_closed()) {
        main_disp.wait();
    }

    return 0;
}