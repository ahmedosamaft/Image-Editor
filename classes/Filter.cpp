//
// Created by andro on 10/4/2023.
//

#include "Filter.h"
#include "../Constants.h"
#include "View.h"
void Filter::BW() {
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

void Filter::invert() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            View::imgGS[i][j] = 255 - View::imgGS[i][j];
}

void Filter::flip() {
    std::vector<std::string> menu{"Horizontal Flip", "Vertical Flip"};
    char choice = Helper::runMenu(menu);
    if (choice == '1')
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgGS[j][i], View::imgGS[Constant::SIZE - j - 1][i]);
    else
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgGS[i][j], View::imgGS[i][Constant::SIZE - j - 1]);
}
void Filter::darken() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            View::imgGS[i][j] = View::imgGS[i][j] / 2;
}

void Filter::lighten() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            View::imgGS[i][j] = View::imgGS[i][j] + (255 - View::imgGS[i][j]) / 2;
}
