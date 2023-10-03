#include "./dependency/Reader.h"
#include "classes/View.h"
#include <direct.h>
#include <iostream>
char cwd[PATH_MAX];
unsigned char imgGS[Reader::SIZE][Reader::SIZE];
unsigned char imgRGB[Reader::SIZE][Reader::SIZE][3];

int main() {
    std::string imgName = "\\imgs\\mario.bmp";
    Reader::readRGB(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), imgRGB);
    Reader::showRGB(imgRGB);
    View::mainMenu();
    return 0;
}
