cmake_minimum_required(VERSION 3.14)
project(ImageLib)

set(CMAKE_CXX_STANDARD 17)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

set(CIMG_H_PATH ~/Workspace/C++/CImg-2.6.7)
#set(CIMG_H_PATH ${PROJECT_SOURCE_DIR}/../CImg-2.6.7)
include_directories( ${CIMG_H_PATH} )

include_directories(include)
include_directories(inline)
# CImg specific stuff taken from the example CMake

FIND_PACKAGE(X11)
FIND_PACKAGE(Threads REQUIRED)

link_directories(${X11_LIB_DIRS})
include_directories(${X11_INCLUDE_DIR})
SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${X11_LIBRARIES} )


add_library(ImageLib SHARED include/types.h src/image.cpp include/image.h include/numerics.h inline/image.inl inline/numerics.inl)

target_link_libraries(ImageLib Eigen3::Eigen)
target_link_libraries(ImageLib ${SYSTEM_LIBS} )

add_executable(ImageLibTest main.cpp )

target_link_libraries(ImageLibTest ImageLib)
