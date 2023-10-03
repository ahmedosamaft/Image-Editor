#ifndef IMAGE_EDITOR_READER_H
#define IMAGE_EDITOR_READER_H

#include <string>
struct Reader {
   static const int SIZE = 256;
   static const int RGB = 3;
   static int readRGB(std::string filename, unsigned char inputImage[][SIZE][RGB]);
   static int writeRGB(std::string filename, unsigned char outputImage[][SIZE][RGB]);
   static void showRGB(unsigned char inputImage[][SIZE][RGB]);
   static int readGS(std::string filename, unsigned char image[][SIZE]);
   static int writeGS(std::string filename, unsigned char image[][SIZE]);
   static void showGS(unsigned char inputImage[][SIZE]);
};

#endif//IMAGE_EDITOR_READER_H
