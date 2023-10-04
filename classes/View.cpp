//
// Created by andro on 10/4/2023.
//

#include "View.h"


std::string View::imgName = std::string();
unsigned char View::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char View::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};

std::vector<std::string> View::menu = {
        "Black & White Filter",
        "Invert Filter",
        "Merge Filter",
        "Flip Image",
        "Darken and Lighten Image",
        "Rotate Image",
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
        if (inp == '1') Filter::BWFilter();
        if (inp == '2') Filter::invertFilter();
        if (inp == '3')Filter::mergeImages();
        if (inp == '5')Filter::rotateImage();
        if (inp == '7')Filter::detectImageEdges();

        Reader::showGS((imgGS));

    }
    string path = "\\tmp\\final.bmp";
    Reader::writeGS(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGS);
}
