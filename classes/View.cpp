//
// Created by andro on 10/4/2023.
//

#include "View.h"
#include "Filter.h"
#include "Helper.h"
#include <direct.h>
#include <iostream>

std::string View::imgName = std::string();
unsigned char View::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char View::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};

std::vector<std::string> View::menu = {
        "Black & White Filter",
        "Invert Filter",
        "Merge Filter",
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
        "Skew Image Right",
        "Skew Image Up",
        "Save the image to a file",
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
        char inp = Helper::runMenu(menu);
        if (inp == '0') break;
        else if (inp == '1') Filter::BW(), Reader::showGS(imgGS);
        else if (inp == '2') Filter::invert();
        else if (inp == '3') Filter::mergeImages();
        else if (inp == '4')
            Filter::flip(), Reader::showGS(imgGS);
        else if (inp == '6') {
            std::vector<std::string> m{"Darken", "Lighten"};
            char choice = Helper::runMenu(m);
            if (choice == '1')Filter::darken();
            else Filter::lighten();
            Reader::showGS(imgGS);
        } else if (inp == '5')Filter::rotateImage();
        else if (inp == '7')Filter::detectImageEdges();

    }
    string path = "\\tmp\\final.bmp";
    Reader::writeGS(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGS);
}
