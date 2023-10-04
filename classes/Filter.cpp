//
// Created by andro on 10/4/2023.
//

#include "Filter.h"
#include "../Constants.h"
#include "View.h"
#include <queue>
#include <tuple>
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

void Filter::mergeImages() {
    std::cout << "Hey Boy!\n"
              << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    std::string imgName;
    std::cin >> imgName;
    imgName = "\\imgs\\" + imgName;
    unsigned char secondImgGS[Constant::SIZE][Constant::SIZE] = {};
    char cwd[PATH_MAX];
    Reader::readGS(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), secondImgGS);
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = (View::imgGS[i][j] + secondImgGS[i][j]) / 2;
}

void Filter::flip() {
    std::vector<std::string> menu{"Horizontal Flip", "Vertical Flip"};
    int choice = Helper::runMenu(menu);
    if (choice == 1)
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgGS[j][i], View::imgGS[Constant::SIZE - j - 1][i]);
    else
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgGS[i][j], View::imgGS[i][Constant::SIZE - j - 1]);
}

void Filter::rotateImage() {
    std::vector<std::string> munu{"90 Degree", "180 Degree", "270 Degree"};
    int Degree = Helper::runMenu(munu);
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (Degree == 1)
                temp[i][j] = View::imgGS[j][255 - i];
            else if (Degree == 2)
                temp[i][j] = View::imgGS[255 - i][255 - j];
            else if (Degree == 3)
                temp[i][j] = View::imgGS[255 - j][i];
            else
                return;

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
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

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE;
}

void Filter::detectImageEdges() {
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    bool vis[Constant::SIZE][Constant::SIZE]{};
    int dirx[]{1, -1, 0, 0};
    int diry[]{0, 0, 1, -1};
    std::queue<std::pair<int, int>> q;
    int i, j;
    vis[0][0] = 1;
    q.emplace(0, 0);
    while (q.size()) {
        std::tie(i, j) = q.front();
        q.pop();
        bool isEdge = 0;
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dirx[dir];
            int y = j + diry[dir];
            if (valid(x, y)) {
                if (!vis[x][y])
                    vis[x][y] = 1, q.emplace(x, y);
                if ((int) View::imgGS[i][j] - (int) View::imgGS[x][y] > 30)
                    isEdge = 1;
            }
        }
        if (isEdge)
            temp[i][j] = 0;
        else
            temp[i][j] = 255;
    }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void Filter::enlargeImage() {
    std::vector<std::string> menu{"First quarter", "Second quarter", "Third quarter", "Fourth quarter"};
    int quarter = Helper::runMenu(menu);
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    int startI = 0, startJ = 0, endI = Constant::SIZE / 2, endJ = Constant::SIZE / 2;
    if (quarter == 3 || quarter == 4)
        startI = Constant::SIZE / 2, endI *= 2;
    if (quarter == 4 || quarter == 2)
        startJ = Constant::SIZE / 2, endJ *= 2;
    for (int i = startI; i < endI; i++)
        for (int j = startJ; j < endJ; j++)
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    temp[2 * (i - startI) + x][2 * (j - startJ) + y] = View::imgGS[i][j];

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void Filter::shrinkImage() {
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    std::vector<std::string> menu{"1/2", "1/3", "1/4"};
    int dimension = Helper::runMenu(menu);
    int endI = Constant::SIZE, endJ = Constant::SIZE;
    int endX = 1, endY = 1;
    int num = dimension + 1;
    endI /= num, endJ /= num, endX *= num, endY *= num;

    for (int i = 0; i < endI; i++)
        for (int j = 0; j < endJ; j++) {
            int avg = 0;
            for (int x = 0; x < endX; x++)
                for (int y = 0; y < endY; y++)
                    avg += View::imgGS[endX * i + x][endY * j + y];
            avg /= endX * endX;
            temp[i][j] = avg;
        }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void Filter::mirrorImage() {
    std::vector<std::string> menu{"Left", "Right", "Upper", "Lower"};
    int option = Helper::runMenu(menu);
    if (option == 1)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = Constant::SIZE / 2; j < Constant::SIZE; j++)
                View::imgGS[i][j] = View::imgGS[i][Constant::SIZE - j + 1];
    else if (option == 2)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                View::imgGS[i][j] = View::imgGS[i][Constant::SIZE - j + 1];
    else if (option == 3)
        for (int i = Constant::SIZE / 2; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgGS[i][j] = View::imgGS[Constant::SIZE - i + 1][j];
    else
        for (int i = 0; i < Constant::SIZE / 2; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgGS[i][j] = View::imgGS[Constant::SIZE - i + 1][j];
}

void Filter::shuffleImage() {

}