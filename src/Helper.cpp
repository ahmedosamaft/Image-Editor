//
// Created by andro on 10/4/2023.
//

#include "../include/Helper.h"
#include "../include/Controller.h"

int Helper::runMenu(const std::vector<std::string> &menu, bool exit) {
    for (int i = 0; i < menu.size(); ++i) {
        printf("%d - %s\n", i + 1, menu[i].c_str());
    }
    if (exit)
        printf("0 - Exit\n");
    printf("Choice >> ");
    int inp;
    while (true) {
        std::cin >> inp;
        if (std::cin.fail() || inp > menu.size() || inp < 0 || inp == 0 && !exit) {
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
                Controller::imgGS[i][j] = Controller::initialGS[i][j];
            }
        }
    } else {
        for (int i = 0; i < Constant::SIZE; ++i) {
            for (int j = 0; j < Constant::SIZE; ++j) {
                for (int k = 0; k < Constant::RGB; ++k) {
                    Controller::imgRGB[i][j][k] = Controller::initialRGB[i][j][k];
                }
            }
        }
    }
}

bool Helper::valid(int i, int j) {
    return (i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE);
}

int Helper::getFlip() {
    std::vector<std::string> menu{"Horizontal Flip", "Vertical Flip"};
    int flip = Helper::runMenu(menu);
    return flip;
}

int Helper::getRotationDegree() {
    std::vector<std::string> menu{"90 Degree", "180 Degree", "270 Degree"};
    int rotationDegree = Helper::runMenu(menu);
    return rotationDegree;
}

int Helper::getNumberInRange(int l, int r) {
    int input;
    while (true) {
        std::cout << "Enter a number [" << l << '-' << r << "]\n";
        std::cin >> input;
        if (input >= 0 && input <= 45)
            return input;
        std::cout << "Invalid number.\n";
    }
}

int Helper::getScale(int maxScale) {
    std::cout << "Enter a Scale.\n";
    int scale = Helper::getNumberInRange(1, maxScale);
    return scale;
}

int Helper::getQuarter() {
    std::vector<std::string> menu{"First quarter", "Second quarter", "Third quarter", "Fourth quarter"};
    int quarter = Helper::runMenu(menu);
    return quarter;
}

int Helper::getRatio() {
    std::vector<std::string> menu{"1/2", "1/3", "1/4"};
    int ratio = Helper::runMenu(menu) + 1;
    return ratio;
}

int Helper::getMirroringDimension() {
    std::vector<std::string> menu{"Left", "Right", "Upper", "Lower"};
    int dimension = Helper::runMenu(menu);
    return dimension;
}

void Helper::getShufflingorder(int order[]) {

    while (true) {
        std::cout << "Enter the order of the quarters.\n";
        std::set<int> s;
        int input;
        for (int i = 0; i < 4; i++)
            std::cin >> input, s.insert(input), order[i] = input - 1;
        bool valid = 1;
        int nxt = 1;
        for (auto i: s)
            if (i != nxt)
                valid = 0;
            else
                nxt++;
        if (!valid || s.size() != 4)
            std::cout << "Invalid order.\n";
        else
            return ;
    }

}

void Helper::getRectangle(int &x1, int &y1, int &x2, int &y2) {
    while (true) {
        printf("Please enter x1 y1 x2 y2 (top left & bottom right): ");
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (!Helper::valid(x1, y1) || !Helper::valid(x2, y2) || x2 < x1 || y2 < y1)
            std::cout << "Invalid input.\n";
        else
            return;
    }
}
int Helper::getSkewDegree() {
    std::cout << "Enter the Skew Degree.\n";
    int degree = Helper::getNumberInRange(0, 45);
    return degree;
}

void Helper::copyGSImage(unsigned char temp[][Constant::SIZE], unsigned char img[][Constant::SIZE]) {
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            img[i][j] = temp[i][j];
}

void Helper::copyRGBImage(unsigned char temp[][Constant::SIZE][Constant::RGB], unsigned char img[][Constant::SIZE][Constant::RGB]) {
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            for (int k = 0; k < Constant::RGB; k++)
                img[i][j][k] = temp[i][j][k];
}

void Helper::copyRGBToGS(int k) {
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            Controller::imgGS[i][j] = Controller::imgRGB[i][j][k];
}

void Helper::copyGSToRGB(int k) {
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            Controller::imgRGB[i][j][k] = Controller::imgGS[i][j];
}