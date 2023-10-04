#ifndef IMAGE_EDITOR_READER_H
#define IMAGE_EDITOR_READER_H

#include "../Constants.h"
#include <string>
struct Reader {
   static int readRGB(std::string filename, unsigned char inputImage[][Constant::SIZE][Constant::RGB]);
   static int writeRGB(std::string filename, unsigned char outputImage[][Constant::SIZE][Constant::RGB]);
   static void showRGB(unsigned char inputImage[][Constant::SIZE][Constant::RGB]);
   static int readGS(std::string filename, unsigned char image[][Constant::SIZE]);
   static int writeGS(std::string filename, unsigned char image[][Constant::SIZE]);
   static void showGS(unsigned char inputImage[][Constant::SIZE]);
};

#endif//IMAGE_EDITOR_READER_H
