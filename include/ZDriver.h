#ifndef IMAGE_EDITOR_ZDRIVER_H
#define IMAGE_EDITOR_ZDRIVER_H


#include "../Constants.h"
#include "../dependency/Reader.h"
#include "FilterGS.h"
#include "FilterRGB.h"
#include "Helper.h"
#include <cmath>
#include <direct.h>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

class ZDriver {
public:
    static std::string imgName;
    static std::vector<std::string> menu;
    static unsigned char imgGS[Constant::SIZE][Constant::SIZE], initialGS[Constant::SIZE][Constant::SIZE];
    static unsigned char imgRGB[Constant::SIZE][Constant::SIZE][3], initialRGB[Constant::SIZE][Constant::SIZE][3];
    static void mainMenu();
    static int readImg(bool isRGB);
    static void saveImage(bool isRGB);
};


#endif//IMAGE_EDITOR_ZDRIVER_H
