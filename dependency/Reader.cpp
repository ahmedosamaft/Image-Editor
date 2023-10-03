//
// Created by andro on 10/3/2023.
//

#include "Reader.h"
#include "bmplib.h"


int Reader::readRGB(std::string filename, unsigned char inputImage[][SIZE][RGB]) {
    return readRGBBMP(filename.c_str(), inputImage);
}

int Reader::writeRGB(std::string filename, unsigned char (*outputImage)[SIZE][RGB]) {
    return writeRGBBMP(filename.c_str(), outputImage);
}

void Reader::showRGB(unsigned char (*inputImage)[SIZE][RGB]) {
    return showRGBBMP(inputImage);
}

int Reader::readGS(std::string filename, unsigned char (*image)[256]) {
    return readGSBMP(filename.c_str(), image);
}

int Reader::writeGS(std::string filename, unsigned char (*image)[256]) {
    return writeGSBMP(filename.c_str(), image);
}

void Reader::showGS(unsigned char (*inputImage)[256]) {
    showGSBMP(inputImage);
}
