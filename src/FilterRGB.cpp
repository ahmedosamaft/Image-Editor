//
// Created by mohamed tamer on 05-Oct-23.
//

#include "../include/FilterRGB.h"


void FilterRGB::BW() {
    long long avg = 0;
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j) {
            long long avg2 = 0;
            for (int k = 0; k < Constant::RGB; k++)
                avg += Controller::imgRGB[i][j][k], avg2 += Controller::imgRGB[i][j][k];
            temp[i][j] = avg2 / 3;
        }
    avg /= (Constant::SIZE * Constant::SIZE * Constant::RGB);
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            for (int k = 0; k < Constant::RGB; k++)
                if (temp[i][j] < avg)
                    Controller::imgRGB[i][j][k] = 0;
                else
                    Controller::imgRGB[i][j][k] = 255;
}

void FilterRGB::invert() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            for (int k = 0; k < Constant::RGB; k++)
                Controller::imgRGB[i][j][k] = 255 - Controller::imgRGB[i][j][k];
}

void FilterRGB::mergeImages() {
    unsigned char secondImgRGB[Constant::SIZE][Constant::SIZE][Constant::RGB] = {};
    Controller::readRGBImage(secondImgRGB);
    for (int k = 0; k < Constant::RGB; k++)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                Controller::imgRGB[i][j][k] = (Controller::imgRGB[i][j][k] + secondImgRGB[i][j][k]) / 2;
}

void FilterRGB::flip() {
    int choice = Helper::getFlip();
    if (choice == 1)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                std::swap(Controller::imgRGB[j][i], Controller::imgRGB[Constant::SIZE - j - 1][i]);
    else
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                std::swap(Controller::imgRGB[i][j], Controller::imgRGB[i][Constant::SIZE - j - 1]);
}

void FilterRGB::rotateImage() {
    int degree = Helper::getRotationDegree();
    for (int k = 0; k < Constant::RGB; ++k) {
        Helper::copyRGBToGS(k);
        FilterGS::applyRotation(degree);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::darken() {
    int scale = Helper::getScale(5);

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyDarkness(scale);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::lighten() {
    int scale = Helper::getScale(5);

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyLightness(scale);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::detectImageEdges() {
    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::detectImageEdges();
        Helper::copyGSToRGB(k);
    }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++) {
            bool isEdge = 0;
            for (int k = 0; k < Constant::RGB; k++)
                if (Controller::imgRGB[i][j][k] == 0)
                    isEdge = 1;
            if (isEdge)
                for (int k = 0; k < Constant::RGB; k++)
                    Controller::imgRGB[i][j][k] = 0;
        }
}

void FilterRGB::enlargeImage() {
    int quarter = Helper::getQuarter();

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyEnlarging(quarter);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::shrinkImage() {
    int ratio = Helper::getRatio();

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyShrinking(ratio);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::mirrorImage() {
    int dimension = Helper::getMirroringDimension();

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyMirroring(dimension);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::shuffleImage() {
    int order[4];
    Helper::getShufflingorder(order);

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyShuffling(order);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::blur() {
    int scale = Helper::getScale(15);

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applyBluring(scale);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::crop() {
    int x1, y1, x2, y2;
    Helper::getRectangle(x1, y1, x2, y2);

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < x1 || i > x2 || j < y1 || j > y2)
                for (int k = 0; k < Constant::RGB; k++)
                    Controller::imgRGB[i][j][k] = 0;
}

void FilterRGB::skewHorizontally() {
    int degree = Helper::getSkewDegree();

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applySkewHorizzantally(degree);
        Helper::copyGSToRGB(k);
    }
}

void FilterRGB::skewVertically() {
    int degree = Helper::getSkewDegree();

    for (int k = 0; k < Constant::RGB; k++) {
        Helper::copyRGBToGS(k);
        FilterGS::applySkewVertically(degree);
        Helper::copyGSToRGB(k);
    }
}