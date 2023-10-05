//
// Created by andro on 10/4/2023.
//

#include "View.h"
#include "FilterGS.h"
#include "Helper.h"
#include <direct.h>
#include <iostream>

std::string View::imgName = std::string();
unsigned char View::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char View::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};

std::vector<std::string> View::menu = {
        "Black & White FilterGS",
        "Invert Image",
        "Merge Image",
        "Flip Image",
        "Rotate Image",
        "Darken or Lighten Image",
        "Detect Image Edges",
        "Enlarge Image",
        "Shrink Image",
        "Mirror 1/2 Image",
        "Shuffle Image",
        "Blur Image",
        "Crop Image",
        "Skew Image Horizontally",
        "Skew Image Vertically",
        "Save the image to a file"
};

void View::mainMenu() {
    using namespace std;
    cout << "Hey Boy!\n"
         << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    cin >> imgName;
    imgName = "\\imgs\\" + imgName;
    char cwd[PATH_MAX];
    Reader::readGS(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), imgGS);
    while (true) {
        cout << "Please select a filter to apply or 0 to exit:\n";
        int inp = Helper::runMenu(menu);
        if (inp == 0) break;
        else if (inp == 1)
            FilterGS::BW();
        else if (inp == 2)
            FilterGS::invert();
        else if (inp == 3)
            FilterGS::mergeImages();
        else if (inp == 4)
            FilterGS::flip();
        else if (inp == 5)
            FilterGS::rotateImage();
        else if (inp == 6) {
            std::vector<std::string> m{"Darken", "Lighten"};
            int choice = Helper::runMenu(m);
            if (choice == 1) FilterGS::darken();
            else
                FilterGS::lighten();
        }
        else if (inp == 7)
            FilterGS::detectImageEdges();
        else if (inp == 8)
            FilterGS::enlargeImage();
        else if (inp == 9)
            FilterGS::shrinkImage();
        else if (inp == 10)
            FilterGS::mirrorImage();
        else if (inp == 11)
            FilterGS::shuffleImage();
        else if (inp == 12)
            FilterGS::blur();
        else if (inp == 13)
            FilterGS::crop();
        else if (inp == 14)
            FilterGS::skewHorizontally();
        else if (inp == 15)
            FilterGS::skewVertically();
        Reader::showGS(imgGS);
    }
    string path = "\\tmp\\final.bmp";
    Reader::writeGS(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGS);
}
