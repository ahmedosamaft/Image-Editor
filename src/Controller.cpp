#include "../include/Controller.h"

unsigned char Controller::imgGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char Controller::initialGS[Constant::SIZE][Constant::SIZE] = {};
unsigned char Controller::imgRGB[Constant::SIZE][Constant::SIZE][3] = {};
unsigned char Controller::initialRGB[Constant::SIZE][Constant::SIZE][3] = {};
bool isRGB;
std::vector<std::string> Controller::menu = {
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
        "Clear Filters applied on current Image",
        "Save the Image to a File",
        "Change current Image"};

void Controller::mainMenu() {
    using namespace std;
    cout << "Welcome to Image Editor Program.\n";
    readImage();

    while (true) {
        cout << "Please select a filter to apply or 0 to exit:\n";
        int inp = Helper::runMenu(menu, 1);
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
        else if (inp == 18)
            saveImage();
        else
            readImage();

        (!isRGB) ? Reader::showGS(imgGS) : Reader::showRGB(imgRGB);
    }
}

void Controller::readImage() {
    using namespace std;
    int choice = 0;
    while (!choice) {
        cout << "Please enter image type.\n";
        choice = Helper::runMenu({"Grayscale", "RGB"}, 0);
    }
    isRGB = (choice == 2);
    if (isRGB) {
        readRGBImage(initialRGB);
        Helper::copyRGBImage(initialRGB, imgRGB);
    } else {
        readGSImage(initialGS);
        Helper::copyGSImage(initialGS, imgGS);
    }
}

void Controller::readGSImage(unsigned char image[][Constant::SIZE]) {
    std::string imgName;
    while (true) {
        std::cout << "Please enter file name of the image to process (MUST BE IN GS imgs FOLDER):";
        std::cin >> imgName;
        imgName = ".\\imgs\\GS imgs\\" + imgName + ".bmp";
        if (Reader::readGS(imgName, image))
            continue;
        else
            break;
    }
}

void Controller::readRGBImage(unsigned char image[][Constant::SIZE][Constant::RGB]) {
    std::string imgName;
    while (true) {
        std::cout << "Please enter file name of the image to process (MUST BE IN RGB imgs FOLDER):";
        std::cin >> imgName;
        imgName = ".\\imgs\\RGB imgs\\" + imgName + ".bmp";
        if (Reader::readRGB(imgName, image))
            continue;
        else
            break;
    }
}


void Controller::saveImage() {
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
