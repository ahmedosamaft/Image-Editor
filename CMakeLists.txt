cmake_minimum_required(VERSION 3.25)
project(image_editor)

set(CMAKE_CXX_STANDARD 17)

add_executable(image_editor main.cpp dependency/Reader.cpp dependency/Reader.h dependency/bmplib.h dependency/bmplib.cpp src/ZDriver.cpp include/ZDriver.h src/Helper.cpp include/Helper.h src/FilterGS.cpp include/FilterGS.h Constants.h src/FilterRGB.cpp include/FilterRGB.h)
