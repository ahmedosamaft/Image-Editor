//
// Created by andro on 10/4/2023.
//

#ifndef IMAGE_EDITOR_FILTER_H
#define IMAGE_EDITOR_FILTER_H

#include "../Constants.h"
#include "View.h"

class Filter {
public:
    static void BWFilter();
    static void invertFilter();
    static void mergeImages();
    static void rotateImage();
    static void detectImageEdges();
};


#endif//IMAGE_EDITOR_FILTER_H
