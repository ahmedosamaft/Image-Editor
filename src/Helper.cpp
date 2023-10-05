//
// Created by andro on 10/4/2023.
//

#include "../include/Helper.h"
#include "../include/ZDriver.h"

int Helper::runMenu(const std::vector<std::string> &menu) {
    for (int i = 0; i < menu.size(); ++i) {
        printf("%d - %s\n", i + 1, menu[i].c_str());
    }
    printf("0 - Exit\n");
    printf("Choice >> ");
    int inp;
    while (true) {
        std::cin >> inp;
        if (std::cin.fail() || inp > menu.size() || inp < 0) {
            std::cout << "ERROR please input a number in range 1 to " << menu.size() << ": ";
            std::cin.ignore();
        } else
            return inp;
    }
}

void Helper::resetFilters(bool isRGB) {
    if (!isRGB) {
        for (int i = 0; i < Constant::SIZE; ++i) {
            for (int j = 0; j < Constant::SIZE; ++j) {
                ZDriver::imgGS[i][j] = ZDriver::initialGS[i][j];
            }
        }
    } else {
        for (int i = 0; i < Constant::SIZE; ++i) {
            for (int j = 0; j < Constant::SIZE; ++j) {
                for (int k = 0; k < Constant::RGB; ++k) {
                    ZDriver::imgRGB[i][j][k] = ZDriver::initialRGB[i][j][k];
                }
            }
        }
    }
}

bool Helper::valid(int i, int j) {
    return (i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE);
}
