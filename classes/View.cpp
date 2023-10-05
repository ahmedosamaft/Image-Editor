//
// Created by andro on 10/4/2023.
//

#include "View.h"

std::string View::imgName = std::string();
unsigned char View::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char View::initialGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char View::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};
unsigned char View::initialRGB[Constant::SIZE][Constant::SIZE][3] = {};

std::vector<std::string> View::menu = {
        "Black & White FilterGS",
        "Invert Image",
        "Merge Image",
        "Flip Image",
        "Rotate Image",
        "Darken Image",
        "Lighten Image",
        "Detect Image Edges",
        "Enlarge Image",
        "Shrink Image",
        "Mirror 1/2 Image",
        "Shuffle Image",
        "Blur Image",
        "Crop Image",
        "Skew Image Horizontally",
        "Skew Image Vertically",
        "Back to Initial Image",
        "Save the image to a file"};

void View::mainMenu() {
    using namespace std;
    int choice = Helper::runMenu({"Grayscale", "RGB"});
    cout << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    cin >> imgName;
    imgName = "\\imgs\\" + imgName;
    char cwd[PATH_MAX];
    if (choice == 1)
        Reader::readGS(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), initialGS);
    else
        Reader::readRGB(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), initialRGB);
    Helper::getInitialImage(choice);

    while (true) {
        cout << "Please select a filter to apply or 0 to exit:\n";
        int inp = Helper::runMenu(menu);
        if (inp == 0) break;
        else if (inp == 1)
            (choice == 1) ? FilterGS::BW() : FilterRGB::BW();
        else if (inp == 2)
            (choice == 1) ? FilterGS::invert() : FilterRGB::invert();
        else if (inp == 3)
            (choice == 1) ? FilterGS::mergeImages() : FilterRGB::mergeImages();
        else if (inp == 4)
            (choice == 1) ? FilterGS::flip() : FilterRGB::flip();
        else if (inp == 5)
            (choice == 1) ? FilterGS::rotateImage() : FilterRGB::rotateImage();
        else if (inp == 6)
            (choice == 1) ? FilterGS::darken() : FilterRGB::darken();
        else if (inp == 7)
            (choice == 1) ? FilterGS::lighten() : FilterRGB::lighten();
        else if (inp == 8)
            (choice == 1) ? FilterGS::detectImageEdges() : FilterRGB::detectImageEdges();
        else if (inp == 9)
            (choice == 1) ? FilterGS::enlargeImage() : FilterRGB::enlargeImage();
        else if (inp == 10)
            (choice == 1) ? FilterGS::shrinkImage() : FilterRGB::shrinkImage();
        else if (inp == 11)
            (choice == 1) ? FilterGS::mirrorImage() : FilterRGB::mirrorImage();
        else if (inp == 12)
            (choice == 1) ? FilterGS::shuffleImage() : FilterRGB::shuffleImage();
        else if (inp == 13)
            (choice == 1) ? FilterGS::blur() : FilterRGB::blur();
        else if (inp == 14)
            (choice == 1) ? FilterGS::crop() : FilterRGB::crop();
        else if (inp == 15)
            (choice == 1) ? FilterGS::skewHorizontally() : FilterRGB::skewHorizontally();
        else if (inp == 16)
            (choice == 1) ? FilterGS::skewVertically() : FilterRGB::skewVertically();
        else if (inp == 17)
            Helper::getInitialImage(choice);
        (choice == 1) ? Reader::showGS(imgGS) : Reader::showRGB(imgRGB);
    }
    string path = "\\tmp\\final.bmp";
    if (choice == 1)
        Reader::writeGS(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGS);
    else
        Reader::writeRGB(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgRGB);
}
