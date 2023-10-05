//
// Created by mohamed tamer on 05-Oct-23.
//

#include "FilterRGB.h"


void FilterRGB::BW() {
    long long avg = 0;
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j) {
            long long avg2 = 0;
            for (int k = 0; k < Constant::RGB; k++)
                avg += View::imgRGB[i][j][k], avg2 += View::imgRGB[i][j][k];
            temp[i][j] = avg2 / 3;
        }
    avg /= (Constant::SIZE * Constant::SIZE * Constant::RGB);
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            for (int k = 0; k < Constant::RGB; k++)
                if (temp[i][j] < avg)
                    View::imgRGB[i][j][k] = 0;
                else
                    View::imgRGB[i][j][k] = 255;
}

void FilterRGB::invert() {
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; ++i)
            for (int j = 0; j < Constant::SIZE; ++j)
                View::imgRGB[i][j][rgb] = 255 - View::imgRGB[i][j][rgb];
}

void FilterRGB::mergeImages() {
    std::cout << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    std::string imgName;
    std::cin >> imgName;
    imgName = "\\imgs\\" + imgName;
    unsigned char secondImgRGB[Constant::SIZE][Constant::SIZE][Constant::RGB] = {};
    char cwd[PATH_MAX];
    Reader::readRGB(strcat(getcwd(cwd, sizeof(cwd)), imgName.c_str()), secondImgRGB);
    for (int k = 0; k < Constant::RGB; k++)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][k] = (View::imgRGB[i][j][k] + secondImgRGB[i][j][k]) / 2;
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
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                if (Degree == 1)
                    temp[i][j][rgb] = View::imgRGB[j][255 - i][rgb];
                else if (Degree == 2)
                    temp[i][j][rgb] = View::imgRGB[255 - i][255 - j][rgb];
                else
                    temp[i][j][rgb] = View::imgRGB[255 - j][i][rgb];
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}

void FilterRGB::darken() {
    int scale;
    while (true) {
        std::cout << "Enter a scale [1-5].\n";
        std::cin >> scale;
        if (scale >= 1 && scale <= 5)
            break;
        std::cout << "Invalid input\n";
    }
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            for (int k = 0; k < Constant::RGB; k++)
                View::imgRGB[i][j][k] = View::imgRGB[i][j][k] / scale;
}

void FilterRGB::lighten() {
    int scale;
    while (true) {
        std::cout << "Enter a scale [1-5].\n";
        std::cin >> scale;
        if (scale >= 1 && scale <= 5)
            break;
        std::cout << "Invalid input\n";
    }
    scale = 7 - scale;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            for (int k = 0; k < Constant::RGB; k++)
                View::imgRGB[i][j][k] = View::imgRGB[i][j][k] + (255 - View::imgRGB[i][j][k]) / scale;
}

bool FilterRGB::valid(int i, int j) {
    return i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE;
}

void FilterRGB::detectImageEdges() {
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    bool vis[Constant::SIZE][Constant::SIZE]{};
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
                for (int k = 0; k < Constant::RGB; k++)
                    if ((int) View::imgRGB[i][j][k] - (int) View::imgRGB[x][y][k] > 30)
                        isEdge = 1;
            }
        }
        for (int k = 0; k < Constant::RGB; k++)
            if (isEdge)
                temp[i][j][k] = 0;
            else
                temp[i][j][k] = 255;
    }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            for (int k = 0; k < Constant::RGB; k++)
                View::imgRGB[i][j][k] = temp[i][j][k];
}

void FilterRGB::enlargeImage() {
    std::vector<std::string> menu{"First quarter", "Second quarter", "Third quarter", "Fourth quarter"};
    int quarter = Helper::runMenu(menu);
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    int startI = 0, startJ = 0, endI = Constant::SIZE / 2, endJ = Constant::SIZE / 2;
    if (quarter == 3 || quarter == 4)
        startI = Constant::SIZE / 2, endI *= 2;
    if (quarter == 4 || quarter == 2)
        startJ = Constant::SIZE / 2, endJ *= 2;
    for (int i = startI; i < endI; i++)
        for (int j = startJ; j < endJ; j++)
            for (int rgb = 0; rgb < Constant::RGB; ++rgb)
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2; y++)
                        temp[2 * (i - startI) + x][2 * (j - startJ) + y][rgb] = View::imgRGB[i][j][rgb];
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}

void FilterRGB::shrinkImage() {
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    std::vector<std::string> menu{"1/2", "1/3", "1/4"};
    int dimension = Helper::runMenu(menu);
    int endI = Constant::SIZE, endJ = Constant::SIZE;
    int endX = 1, endY = 1;
    int num = dimension + 1;
    endI /= num, endJ /= num, endX *= num, endY *= num;

    for (int i = 0; i < endI; i++)
        for (int j = 0; j < endJ; j++)
            for (int k = 0; k < Constant::RGB; k++) {
                int avg = 0;
                for (int x = 0; x < endX; x++)
                    for (int y = 0; y < endY; y++)
                        avg += View::imgRGB[endX * i + x][endY * j + y][k];

                avg /= endX * endX;
                temp[i][j][k] = avg;
            }

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            for (int k = 0; k < Constant::RGB; k++)
                View::imgRGB[i][j][k] = temp[i][j][k];
}

void FilterRGB::mirrorImage() {
    std::vector<std::string> menu{"Left", "Right", "Upper", "Lower"};
    int option = Helper::runMenu(menu);
    if (option == 1)
        for (int rgb = 0; rgb < Constant::RGB; ++rgb)
            for (int i = 0; i < Constant::SIZE; i++)
                for (int j = Constant::SIZE / 2; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[i][Constant::SIZE - j + 1][rgb];

    else if (option == 2)
        for (int rgb = 0; rgb < Constant::RGB; ++rgb)
            for (int i = 0; i < Constant::SIZE; i++)
                for (int j = 0; j < Constant::SIZE / 2; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[i][Constant::SIZE - j + 1][rgb];

    else if (option == 3)
        for (int rgb = 0; rgb < Constant::RGB; ++rgb)
            for (int i = Constant::SIZE / 2; i < Constant::SIZE; i++)
                for (int j = 0; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[Constant::SIZE - i + 1][j][rgb];
    else
        for (int rgb = 0; rgb < Constant::RGB; ++rgb)
            for (int i = 0; i < Constant::SIZE / 2; i++)
                for (int j = 0; j < Constant::SIZE; j++)
                    View::imgRGB[i][j][rgb] = View::imgRGB[Constant::SIZE - i + 1][j][rgb];
}

void FilterRGB::shuffleImage() {
    unsigned char quarters[4][Constant::SIZE / 2][Constant::SIZE / 2][3];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            for (int k = 0; k < Constant::RGB; k++)
                if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                    quarters[0][i][j][k] = View::imgRGB[i][j][k];
                else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                    quarters[1][i][j - Constant::SIZE / 2][k] = View::imgRGB[i][j][k];
                else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                    quarters[2][i - Constant::SIZE / 2][j][k] = View::imgRGB[i][j][k];
                else
                    quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2][k] = View::imgRGB[i][j][k];
    int order[4];
    while (true) {
        std::cout << "Enter the order of the quarters.\n";
        std::set<int> s;
        int input;
        for (int i = 0; i < 4; i++)
            std::cin >> input, s.insert(input), order[i] = input - 1;
        bool valid = 1;
        int nxt = 1;
        for (auto i: s)
            if (i != nxt)
                valid = 0;
            else
                nxt++;
        if (!valid || s.size() != 4)
            std::cout << "Invalid order.\n";
        else
            break;
    }
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (j == order[i])
                std::swap(quarters[i], quarters[j]);
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            for (int k = 0; k < Constant::RGB; k++)
                if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                    View::imgRGB[i][j][k] = quarters[0][i][j][k];
                else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                    View::imgRGB[i][j][k] = quarters[1][i][j - Constant::SIZE / 2][k];
                else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                    View::imgRGB[i][j][k] = quarters[2][i - Constant::SIZE / 2][j][k];
                else
                    View::imgRGB[i][j][k] = quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2][k];
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
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    int vis[Constant::SIZE][Constant::SIZE][Constant::RGB], vid = 0;
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
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
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
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
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    for (int rgb = 0; rgb < Constant::RGB; ++rgb) {
        double scale = tan(degree * 3.14 / 180) * 256.0;
        double toTake = 256 / (256 - scale);
        double minus = scale / 256, cur = 0, here = 0;
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
    }
    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}

void FilterRGB::skewVertically() {
    unsigned char temp[Constant::SIZE][Constant::SIZE][Constant::RGB]{};
    int degree;
    while (true) {
        std::cout << "Enter the skew degree [0-45].\n";
        std::cin >> degree;
        if (degree >= 0 && degree <= 45)
            break;
        std::cout << "Invalid degree.\n";
    }
    for (int rgb = 0; rgb < Constant::RGB; ++rgb) {
        double scale = tan(degree * 3.14 / 180) * 256.0;
        double toTake = 256 / (256 - scale);
        double minus = scale / 256, cur = 0, here = 0;
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
    }

    for (int rgb = 0; rgb < Constant::RGB; ++rgb)
        for (int i = 0; i < Constant::SIZE; i++)
            for (int j = 0; j < Constant::SIZE; j++)
                View::imgRGB[i][j][rgb] = temp[i][j][rgb];
}