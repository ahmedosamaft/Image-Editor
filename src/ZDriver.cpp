#include "../include/ZDriver.h"

std::string ZDriver::imgName = std::string();
unsigned char ZDriver::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char ZDriver::initialGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char ZDriver::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};
unsigned char ZDriver::initialRGB[Constant::SIZE][Constant::SIZE][3] = {};

std::vector<std::string> ZDriver::menu = {
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

void ZDriver::mainMenu() {
    using namespace std;
    bool isRGB = Helper::runMenu({"Grayscale", "RGB"}) == 2;
    while (readImg(isRGB)){
        cout << "Try Again!\n";
    }
    while (true) {
        cout << "Please select a filter to apply or 0 to exit:\n";
        int inp = Helper::runMenu(menu);
        if (inp == 0) break;
        else if (inp == 1)
            (!isRGB) ? FilterGS::BW() : FilterRGB::BW();
        else if (inp == 2)
            (!isRGB) ? FilterGS::invert() : FilterRGB::invert();
        else if (inp == 3)
            (!isRGB) ? FilterGS::mergeImages() : FilterRGB::mergeImages();
        else if (inp == 4)
            (!isRGB) ? FilterGS::flip() : FilterRGB::flip();
        else if (inp == 5)
            (!isRGB) ? FilterGS::rotateImage() : FilterRGB::rotateImage();
        else if (inp == 6)
            (!isRGB) ? FilterGS::darken() : FilterRGB::darken();
        else if (inp == 7)
            (!isRGB) ? FilterGS::lighten() : FilterRGB::lighten();
        else if (inp == 8)
            (!isRGB) ? FilterGS::detectImageEdges() : FilterRGB::detectImageEdges();
        else if (inp == 9)
            (!isRGB) ? FilterGS::enlargeImage() : FilterRGB::enlargeImage();
        else if (inp == 10)
            (!isRGB) ? FilterGS::shrinkImage() : FilterRGB::shrinkImage();
        else if (inp == 11)
            (!isRGB) ? FilterGS::mirrorImage() : FilterRGB::mirrorImage();
        else if (inp == 12)
            (!isRGB) ? FilterGS::shuffleImage() : FilterRGB::shuffleImage();
        else if (inp == 13)
            (!isRGB) ? FilterGS::blur() : FilterRGB::blur();
        else if (inp == 14)
            (!isRGB) ? FilterGS::crop() : FilterRGB::crop();
        else if (inp == 15)
            (!isRGB) ? FilterGS::skewHorizontally() : FilterRGB::skewHorizontally();
        else if (inp == 16)
            (!isRGB) ? FilterGS::skewVertically() : FilterRGB::skewVertically();
        else if (inp == 17)
            Helper::resetFilters(isRGB);
        (!isRGB) ? Reader::showGS(imgGS) : Reader::showRGB(imgRGB);
    }
    saveImage(isRGB);
}

int ZDriver::readImg(bool isRGB) {
    using namespace std;
    cout << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    cin >> imgName;
    imgName = ".\\imgs\\" + imgName + ".bmp";;
    if (!isRGB) {
        Reader::readGS(imgName, initialGS);
        return Reader::readGS(imgName, imgGS);
    } else {
        Reader::readRGB(imgName, initialRGB);
        return Reader::readRGB(imgName, imgRGB);
    }
}

void ZDriver::saveImage(bool isRGB) {
    std::string path;
    printf("Enter output image name >> ");
    std::cin >> path;
    path += ".bmp";
    path = ".\\output\\" + path;
    if (isRGB)
        Reader::writeRGB(path, imgRGB);
    else
        Reader::writeGS(path, imgGS);
}
