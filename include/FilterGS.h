//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_FILTERGS_H
#define IMAGE_EDITOR_FILTERGS_H

#include "Controller.h"

class FilterGS {
public:
    inline static int dirx[] = {1, -1, 0, 0};
    inline static int diry[] = {0, 0, 1, -1};
    static void BW();
    static void invert();
    static void mergeImages();
    static void flip();
    static void applyFlipping(bool isVertically);
    static void rotateImage();
    static void applyRotation(int degree);
    static void darken();
    static void applyDarkness(int scale);
    static void lighten();
    static void applyLightness(int scale);
    static void detectImageEdges();
    static void enlargeImage();
    static void applyEnlarging(int quarter);
    static void shrinkImage();
    static void applyShrinking(int ratio);
    static void mirrorImage();
    static void applyMirroring(int dimention);
    static void shuffleImage();
    static void applyShuffling(int order[]);
    static void blur();
    static void applyBluring(int scale);
    static void crop();
    static void skewHorizontally();
    static void applySkewHorizzantally(int degree);
    static void skewVertically();
    static void applySkewVertically(int degree);

};


#endif//IMAGE_EDITOR_FILTERGS_H
