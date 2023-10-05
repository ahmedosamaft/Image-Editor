cmake_minimum_required(VERSION 3.25)
project(image_editor)

set(CMAKE_CXX_STANDARD 17)

add_executable(image_editor main.cpp dependency/Reader.cpp dependency/Reader.h dependency/bmplib.h dependency/bmplib.cpp classes/View.cpp classes/View.h classes/Helper.cpp classes/Helper.h classes/FilterGS.cpp classes/FilterGS.h Constants.h classes/FilterRGB.cpp classes/FilterRGB.h)
