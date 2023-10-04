//
// Created by andro on 10/4/2023.
//

#include "Filter.h"


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

void Filter::rotateImage() {
    std::vector<std::string> munu{"90 Degree", "180 Degree", "270 Degree"};
    char Degree = Helper::runMenu(munu);
    char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (Degree == '1')
                temp[i][j] = View::imgGS[j][255 - i];
            else if (Degree == '2')
                temp[i][j] = View::imgGS[255 - i][255 - j];
            else if (Degree == '3')
                temp[i][j] = View::imgGS[255 - j][i];
            else
                return;

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

int dirx[]{1, -1, 0, 0};
int diry[]{0, 0, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE;
}

void dfs(int i, int j, std::vector<std::vector<char>> &temp, std::vector<std::vector<bool>> &vis) {
    bool edge = 0;
    vis[i][j] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int newI = i + dirx[dir], newJ = j + diry[dir];
        if (valid(newI, newJ)) {
            if (!vis[newI][newJ])
                dfs(newI, newJ, temp, vis);
            if (abs(View::imgGS[i][j] - View::imgGS[newI][newJ]) > 5)
                edge = 1;
        }
    }
    if (edge)
        temp[i][j] = 0;
    else
        temp[i][j] = 255;
}

void Filter::detectImageEdges() {
    std::vector<std::vector<char>> temp(Constant::SIZE, std::vector<char>(Constant::SIZE));
    std::vector<std::vector<bool>> vis(Constant::SIZE, std::vector<bool>(Constant::SIZE));
    dfs(0, 0, temp, vis);
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

