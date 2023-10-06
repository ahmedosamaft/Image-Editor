//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_HELPER_H
#define IMAGE_EDITOR_HELPER_H

#include <string>
#include <vector>


class Helper {
public:
    static int runMenu(const std::vector<std::string> &menu, bool exit = 0);
    static void resetFilters(bool isRGB);
    static bool valid(int i, int j);
};


#endif//IMAGE_EDITOR_HELPER_H
