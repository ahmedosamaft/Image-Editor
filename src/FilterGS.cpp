//
// Created by andro on 10/4/2023.
//

#include "../include/FilterGS.h"

void FilterGS::BW() {
    int avg = 0;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            avg += Controller::imgGS[i][j];
    avg /= (Constant::SIZE * Constant::SIZE);
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            if (Controller::imgGS[i][j] < avg)
                Controller::imgGS[i][j] = 0;
            else
                Controller::imgGS[i][j] = 255;
}

void FilterGS::invert() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            Controller::imgGS[i][j] = 255 - Controller::imgGS[i][j];
}

void FilterGS::mergeImages() {
    unsigned char secondImgGS[Constant::SIZE][Constant::SIZE] = {};
    Controller::readGSImage(secondImgGS);
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            Controller::imgGS[i][j] = (Controller::imgGS[i][j] + secondImgGS[i][j]) / 2;
}

void FilterGS::flip() {
    int choice = Helper::getFlip();
    choice--;
    applyFlipping(choice);
}

void FilterGS::applyFlipping(bool isVertically) {
    if (!isVertically)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                std::swap(Controller::imgGS[j][i], Controller::imgGS[Constant::SIZE - j - 1][i]);
    else
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                std::swap(Controller::imgGS[i][j], Controller::imgGS[i][Constant::SIZE - j - 1]);
}

void FilterGS::rotateImage() {
    int degree = Helper::getRotationDegree();
    applyRotation(degree);
}

void FilterGS::applyRotation(int degree) {
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (degree == 1)
                temp[i][j] = Controller::imgGS[j][Constant::SIZE - i - 1];
            else if (degree == 2)
                temp[i][j] = Controller::imgGS[Constant::SIZE - i - 1][Constant::SIZE - j - 1];
            else
                temp[i][j] = Controller::imgGS[Constant::SIZE - j - 1][i];
    Helper::copyGSImage(temp, Controller::imgGS);
}

void FilterGS::darken() {
    int scale = Helper::getScale(5);
    applyDarkness(scale);
}

void FilterGS::applyDarkness(int scale) {
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            Controller::imgGS[i][j] = Controller::imgGS[i][j] / scale;
}

void FilterGS::lighten() {
    int scale = Helper::getScale(5);
    applyLightness(scale);
}

void FilterGS::applyLightness(int scale) {
    scale = 7 - scale;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            Controller::imgGS[i][j] = Controller::imgGS[i][j] + (255 - Controller::imgGS[i][j]) / scale;
}


void FilterGS::detectImageEdges() {
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++) {
            bool isEdge = 0;
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dirx[dir];
                int y = j + diry[dir];
                if (Helper::valid(x, y) && (int) Controller::imgGS[i][j] - (int) Controller::imgGS[x][y] > 30)
                    isEdge = 1;
            }
            if (isEdge)
                temp[i][j] = 0;
            else
                temp[i][j] = 255;
        }
    Helper::copyGSImage(temp, Controller::imgGS);
}

void FilterGS::enlargeImage() {
    int quarter = Helper::getQuarter();
    applyEnlarging(quarter);
}

void FilterGS::applyEnlarging(int quarter) {
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
                    temp[2 * (i - startI) + x][2 * (j - startJ) + y] = Controller::imgGS[i][j];

    Helper::copyGSImage(temp, Controller::imgGS);
}

void FilterGS::shrinkImage() {
    int ratio = Helper::getRatio();
    applyShrinking(ratio);
}

void FilterGS::applyShrinking(int ratio) {
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    int endI = Constant::SIZE, endJ = Constant::SIZE;
    int endX = 1, endY = 1;
    endI /= ratio, endJ /= ratio, endX *= ratio, endY *= ratio;

    for (int i = 0; i < endI; i++)
        for (int j = 0; j < endJ; j++) {
            int avg = 0;
            for (int x = 0; x < endX; x++)
                for (int y = 0; y < endY; y++)
                    avg += Controller::imgGS[endX * i + x][endY * j + y];
            avg /= endX * endX;
            temp[i][j] = avg;
        }

    Helper::copyGSImage(temp, Controller::imgGS);
}
void FilterGS::mirrorImage() {
    int dimension = Helper::getMirroringDimension();
    applyMirroring(dimension);
}

void FilterGS::applyMirroring(int dimension) {
    if (dimension == 1)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = Constant::SIZE / 2; j < Constant::SIZE; j++)
                Controller::imgGS[i][j] = Controller::imgGS[i][Constant::SIZE - j + 1];
    else if (dimension == 2)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE / 2; j++)
                Controller::imgGS[i][j] = Controller::imgGS[i][Constant::SIZE - j + 1];
    else if (dimension == 3)
        for (int i = Constant::SIZE / 2; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                Controller::imgGS[i][j] = Controller::imgGS[Constant::SIZE - i + 1][j];
    else
        for (int i = 0; i < Constant::SIZE / 2; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                Controller::imgGS[i][j] = Controller::imgGS[Constant::SIZE - i + 1][j];
}

void FilterGS::shuffleImage() {
    int order[4];
    Helper::getShufflingorder(order);
}

void FilterGS::applyShuffling(int order[]) {

    unsigned char quarters[4][Constant::SIZE / 2][Constant::SIZE / 2];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                quarters[0][i][j] = Controller::imgGS[i][j];
            else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                quarters[1][i][j - Constant::SIZE / 2] = Controller::imgGS[i][j];
            else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                quarters[2][i - Constant::SIZE / 2][j] = Controller::imgGS[i][j];
            else
                quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2] = Controller::imgGS[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (j == order[i])
                std::swap(quarters[i], quarters[j]);

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                Controller::imgGS[i][j] = quarters[0][i][j];
            else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                Controller::imgGS[i][j] = quarters[1][i][j - Constant::SIZE / 2];
            else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                Controller::imgGS[i][j] = quarters[2][i - Constant::SIZE / 2][j];
            else
                Controller::imgGS[i][j] = quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2];
}

void FilterGS::blur() {
    int scale = Helper::getScale(15);
    applyBluring(scale);
}

void FilterGS::applyBluring(int scale) {
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    int vis[Constant::SIZE][Constant::SIZE]{}, vid = 0;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j) {
            vid++;
            std::queue<std::pair<int, int>> q;
            q.emplace(i, j);
            vis[i][j] = vid;
            int total = Controller::imgGS[i][j], distance = scale, curI, curJ, pixels = 1;
            while (distance--) {
                int sz = q.size();
                for (int k = 0; k < sz; k++) {
                    std::tie(curI, curJ) = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int x = curI + dirx[dir];
                        int y = curJ + diry[dir];
                        if (Helper::valid(x, y) && vis[x][y] != vid) {
                            q.emplace(x, y);
                            vis[x][y] = vid;
                            pixels++;
                            total += Controller::imgGS[x][y];
                        }
                    }
                }
            }
            total /= pixels;
            temp[i][j] = total;
        }

    Helper::copyGSImage(temp, Controller::imgGS);
}

void FilterGS::crop() {
    int x1, y1, x2, y2;
    Helper::getRectangle(x1, y1, x2, y2);

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < x1 || i > x2 || j < y1 || j > y2)
                Controller::imgGS[i][j] = 0;
}

void FilterGS::skewHorizontally() {
    int degree = Helper::getSkewDegree();
    applySkewHorizzantally(degree);
}

void FilterGS::applySkewHorizzantally(int degree) {
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    double scale = tan(degree * 3.14 / 180) * Constant::SIZE;
    double toTake = Constant::SIZE / (Constant::SIZE - scale);
    double minus = scale / Constant::SIZE, cur = 0, here = 0;
    for (int row = 0; row < Constant::SIZE; row++) {
        here += minus, cur = 0;
        for (int col = scale - here; col < Constant::SIZE - here; col++) {
            int avg = 0, pixels = 0;
            for (int k = std::max(0, (int) ceil(cur - toTake)); k < std::min(Constant::SIZE, (int) ceil(cur + toTake)); k++)
                pixels++, avg += Controller::imgGS[row][k];
            avg /= std::max(1, pixels);
            temp[row][col] = avg;
            cur += toTake;
        }
    }
    Helper::copyGSImage(temp, Controller::imgGS);
}

void FilterGS::skewVertically() {
    int degree = Helper::getSkewDegree();
    applySkewVertically(degree);
}

void FilterGS::applySkewVertically(int degree) {
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            temp[i][j] = Controller::imgGS[j][i];

    Helper::copyGSImage(temp, Controller::imgGS);
    FilterGS::applySkewHorizzantally(degree);
    applyRotation(3);
    applyFlipping(1);
}
