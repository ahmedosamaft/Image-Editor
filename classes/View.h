//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_VIEW_H
#define IMAGE_EDITOR_VIEW_H


#include "../Constants.h"
#include "../dependency/Reader.h"
#include <string>
#include <vector>
#include "Filter.h"
#include "Helper.h"
#include <direct.h>
#include <iostream>

class View {
public:
    static std::string imgName;
    static std::vector<std::string> menu;
    static unsigned char imgGS[Constant::SIZE][Constant::SIZE];
    static unsigned char imgRGB[Constant::SIZE][Constant::SIZE][3];
    static void mainMenu();
};


#endif//IMAGE_EDITOR_VIEW_H
