//
// Created by mohamed tamer on 05-Oct-23.
//

#include "FilterRGB.h"

//
// Created by andro on 10/4/2023.
//

#include "FilterGS.h"



void FilterRGB::invert() {
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE; ++j)
                View::imgRGB[i][j][rgb] = 255 - View::imgRGB[i][j][rgb];
}



void FilterRGB::flip() {
    std::vector<std::string> menu{"Horizontal Flip", "Vertical Flip"};
    int choice = Helper::runMenu(menu);
    if (choice == 1)
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgRGB[j][i], View::imgRGB[Constant::SIZE - j - 1][i]);
    else
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE / 2; ++j)
                std::swap(View::imgRGB[i][j], View::imgRGB[i][Constant::SIZE - j - 1]);
}

void FilterRGB::rotateImage() {
    std::vector<std::string> munu{"90 Degree", "180 Degree", "270 Degree"};
    int Degree = Helper::runMenu(munu);
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB];
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                if (Degree == 1)
                    temp[i][j][rgb] = View::imgRGB[j][255 - i][rgb];
                else if (Degree == 2)
                    temp[i][j][rgb] = View::imgRGB[255 - i][255 - j][rgb];
                else
                    temp[i][j][rgb] = View::imgRGB[255 - j][i][rgb];
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}





int dirx[]{1, -1, 0, 0};
int diry[]{0, 0, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE;
}



void FilterRGB::enlargeImage() {
    std::vector<std::string> menu{"First quarter", "Second quarter", "Third quarter", "Fourth quarter"};
    int quarter = Helper::runMenu(menu);
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB];
    int startI = 0, startJ = 0, endI = Constant::SIZE / 2, endJ = Constant::SIZE / 2;
    if (quarter == 3 || quarter == 4)
        startI = Constant::SIZE / 2, endI *= 2;
    if (quarter == 4 || quarter == 2)
        startJ = Constant::SIZE / 2, endJ *= 2;
    for (int i = startI; i < endI; i++)
        for (int j = startJ; j < endJ; j++)
            for (int rgb = 0; rgb < 3; ++rgb)
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2; y++)
                        temp[2 * (i - startI) + x][2 * (j - startJ) + y][rgb] = View::imgRGB[i][j][rgb];
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}



void FilterRGB::mirrorImage() {
    std::vector<std::string> menu{"Left", "Right", "Upper", "Lower"};
    int option = Helper::runMenu(menu);
    if (option == 1)
        for (int rgb = 0; rgb < 3; ++rgb)
            for (int i = 0; i < Constant::SIZE; i++)
                for (int j = Constant::SIZE / 2; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[i][Constant::SIZE - j + 1][rgb];

    else if (option == 2)
        for (int rgb = 0; rgb < 3; ++rgb)
            for (int i = 0; i < Constant::SIZE; i++)
                for (int j = 0; j < Constant::SIZE / 2; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[i][Constant::SIZE - j + 1][rgb];

    else if (option == 3)
        for (int rgb = 0; rgb < 3; ++rgb)
            for (int i = Constant::SIZE / 2; i < Constant::SIZE; i++)
                for (int j = 0; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[Constant::SIZE - i + 1][j][rgb];
    else
        for (int rgb = 0; rgb < 3; ++rgb)
            for (int i = 0; i < Constant::SIZE / 2; i++)
                for (int j = 0; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[Constant::SIZE - i + 1][j][rgb];
}




void FilterRGB::blur() {
    int scale = 0;
    while (true) {
        std::cout << "Enter a scale [1-15].\n";
        std::cin >> scale;
        if (scale >= 1 && scale <= 15)
            break;
        std::cout << "Invalid input.\n";
    }
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB];
    int vis[Constant::SIZE][Constant::SIZE][Constant::RGB], vid = 0;
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE; ++j) {
                vid++;
                std::queue<std::pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j][rgb] = vid;
                int total = View::imgRGB[i][j][rgb], distance = scale, curI, curJ, pixels = 1;
                while (distance--) {
                    int sz = q.size();
                    for (int k = 0; k < sz; k++) {
                        std::tie(curI, curJ) = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int x = curI + dirx[dir];
                            int y = curJ + diry[dir];
                            if (valid(x, y) && vis[x][y][rgb] != vid) {
                                q.emplace(x, y);
                                vis[x][y][rgb] = vid;
                                pixels++;
                                total += View::imgRGB[x][y][rgb];
                            }
                        }
                    }
                }
                total /= pixels;
                temp[i][j][rgb] = total;
            }
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}

void FilterRGB::crop() {
    int x1, y1, x2, y2;
    while (true) {
        printf("Please enter x1 y1 x2 y2 (top left & bottom right): ");
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (!valid(x1, y1) || !valid(x2, y2) || x2 < x1 || y2 < y1)
            std::cout << "Invalid input.\n";
        else
            break;
    }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < x1 || i > x2 || j < y1 || j > y2)
                for (int rgb = 0; rgb < 3; ++rgb)
                    View::imgRGB[i][j][rgb] = 0;
}

void FilterRGB::skewHorizontally() {
    int degree;
    while (true) {
        std::cout << "Enter the skew degree [0-45].\n";
        std::cin >> degree;
        if (degree >= 0 && degree <= 45)
            break;
        std::cout << "Invalid degree.\n";
    }
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB];
    double scale = tan(degree * 3.14 / 180) * 256.0;
    double toTake = 256 / (256 - scale);
    double minus = scale / 256, cur = 0, here = 0;
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int row = 0; row < Constant::SIZE; row++) {
            here += minus, cur = 0;
            for (int col = scale - here; col < Constant::SIZE - here; col++) {
                int avg = 0, pixels = 0;
                for (int k = std::max(0, (int) ceil(cur - toTake)); k < std::min(Constant::SIZE, (int) ceil(cur + toTake)); k++)
                    pixels++, avg += View::imgRGB[row][k][rgb];
                avg /= std::max(1, pixels);
                temp[row][col][rgb] = avg;
                cur += toTake;
            }
        }
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}

void FilterRGB::skewVertically() {
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB];
    int degree;
    while (true) {
        std::cout << "Enter the skew degree [0-45].\n";
        std::cin >> degree;
        if (degree >= 0 && degree <= 45)
            break;
        std::cout << "Invalid degree.\n";
    }
    double scale = tan(degree * 3.14 / 180) * 256.0;
    double toTake = 256 / (256 - scale);
    double minus = scale / 256, cur = 0, here = 0;
    for (int rgb = 0; rgb < 3; ++rgb)
        for (int row = 0; row < Constant::SIZE; row++) {
            here += minus, cur = 0;
            for (int col = scale - here; col < Constant::SIZE - here; col++) {
                int avg = 0, pixels = 0;
                for (int k = std::max(0, (int) ceil(cur - toTake)); k < std::min(Constant::SIZE, (int) ceil(cur + toTake)); k++)
                    pixels++, avg += View::imgRGB[k][row][rgb];
                avg /= std::max(1, pixels);
                temp[col][row][rgb] = avg;
                cur += toTake;
            }
        }

    for (int rgb = 0; rgb < 3; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}