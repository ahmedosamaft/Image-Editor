//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_HELPER_H
#define IMAGE_EDITOR_HELPER_H

#include "../Constants.h"
#include <string>
#include <vector>


class Helper {
public:
    static int runMenu(const std::vector<std::string> &menu, bool exit = 0);
    static void resetFilters(bool isRGB);
    static bool valid(int i, int j);
    static int getFlip();
    static int getRotationDegree();
    static int getNumberInRange(int l, int r);
    static int getScale(int maxScale);
    static int getQuarter();
    static int getRatio();
    static int getMirroringDimension();
    static void getShufflingorder(int order[]);
    static void getRectangle(int &x1, int &y1, int &x2, int &y2);
    static int getSkewDegree();
    static void copyGSImage(unsigned char temp[][Constant::SIZE], unsigned char img[][Constant::SIZE]);
    static void copyRGBImage(unsigned char temp[][Constant::SIZE][Constant::RGB], unsigned char img[][Constant::SIZE][Constant::RGB]);
    static void copyRGBToGS(int k);
    static void copyGSToRGB(int k);
};


#endif//IMAGE_EDITOR_HELPER_H
