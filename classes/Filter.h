//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_FILTER_H
#define IMAGE_EDITOR_FILTER_H

#include "../Constants.h"
#include "View.h"

class Filter {
public:
    static void BW();
    static void invert();
    static void mergeImages();
    static void flip();
    static void rotateImage();
    static void darken();
    static void lighten();
    static void detectImageEdges();
    static void enlargeImage();
    static void shrinkImage();
    static void mirrorImage();
    static void shuffleImage();
    static void blur();
    static void crop();
    static void skewHorizontally();
    static void skewVertically();

};


#endif//IMAGE_EDITOR_FILTER_H
