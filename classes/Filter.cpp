//
// Created by andro on 10/4/2023.
//

#include "Filter.h"
#include "../Constants.h"
#include "View.h"
void Filter::BWFilter() {
    long long avg = 0;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            avg += View::imgGS[i][j];
    avg /= (Constant::SIZE * Constant::SIZE);
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            if (View::imgGS[i][j] < 128) View::imgGS[i][j] = 0;
            else
                View::imgGS[i][j] = 255;
}

void Filter::invertFilter() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            View::imgGS[i][j] = 255 - View::imgGS[i][j];
}
