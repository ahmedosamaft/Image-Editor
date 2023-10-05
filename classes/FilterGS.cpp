//
// Created by andro on 10/4/2023.
//

#include "FilterGS.h"

void FilterGS::BW() {
    long long avg = 0;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            avg += View::imgGS[i][j];
    avg /= (Constant::SIZE * Constant::SIZE);
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            if (View::imgGS[i][j] < avg) View::imgGS[i][j] = 0;
            else
                View::imgGS[i][j] = 255;
}

void FilterGS::invert() {
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j)
            View::imgGS[i][j] = 255 - View::imgGS[i][j];
}

void FilterGS::mergeImages() {
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

void FilterGS::flip() {
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

void FilterGS::rotateImage() {
    std::vector<std::string> munu{"90 Degree", "180 Degree", "270 Degree"};
    int Degree = Helper::runMenu(munu);
    unsigned char temp[Constant::SIZE][Constant::SIZE];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (Degree == 1)
                temp[i][j] = View::imgGS[j][255 - i];
            else if (Degree == 2)
                temp[i][j] = View::imgGS[255 - i][255 - j];
            else
                temp[i][j] = View::imgGS[255 - j][i];

    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void FilterGS::darken() {
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
            View::imgGS[i][j] = View::imgGS[i][j] / scale;
}

void FilterGS::lighten() {
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
            View::imgGS[i][j] = View::imgGS[i][j] + (255 - View::imgGS[i][j]) / scale;
}

int dirx[]{1, -1, 0, 0};
int diry[]{0, 0, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < Constant::SIZE && j < Constant::SIZE;
}

void FilterGS::detectImageEdges() {
    unsigned char temp[Constant::SIZE][Constant::SIZE];
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

void FilterGS::enlargeImage() {
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

void FilterGS::shrinkImage() {
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

void FilterGS::mirrorImage() {
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

void FilterGS::shuffleImage() {
    unsigned char quarters[4][Constant::SIZE / 2][Constant::SIZE / 2];
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                quarters[0][i][j] = View::imgGS[i][j];
            else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                quarters[1][i][j - Constant::SIZE / 2] = View::imgGS[i][j];
            else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                quarters[2][i - Constant::SIZE / 2][j] = View::imgGS[i][j];
            else
                quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2] = View::imgGS[i][j];
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
            if (i < Constant::SIZE / 2 && j < Constant::SIZE / 2)
                View::imgGS[i][j] = quarters[0][i][j];
            else if (i < Constant::SIZE / 2 && j >= Constant::SIZE / 2)
                View::imgGS[i][j] = quarters[1][i][j - Constant::SIZE / 2];
            else if (i >= Constant::SIZE / 2 && j < Constant::SIZE / 2)
                View::imgGS[i][j] = quarters[2][i - Constant::SIZE / 2][j];
            else
                View::imgGS[i][j] = quarters[3][i - Constant::SIZE / 2][j - Constant::SIZE / 2];
}


void FilterGS::blur() {
    int scale = 0;
    while (true) {
        std::cout << "Enter a scale [1-15].\n";
        std::cin >> scale;
        if (scale >= 1 && scale <= 15)
            break;
        std::cout << "Invalid input.\n";
    }
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    int vis[Constant::SIZE][Constant::SIZE]{}, vid = 0;
    for (int i = 0; i < Constant::SIZE; ++i)
        for (int j = 0; j < Constant::SIZE; ++j) {
            vid++;
            std::queue<std::pair<int, int>> q;
            q.emplace(i, j);
            vis[i][j] = vid;
            int total = View::imgGS[i][j], distance = scale, curI, curJ, pixels = 1;
            while (distance--) {
                int sz = q.size();
                for (int k = 0; k < sz; k++) {
                    std::tie(curI, curJ) = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int x = curI + dirx[dir];
                        int y = curJ + diry[dir];
                        if (valid(x, y) && vis[x][y] != vid) {
                            q.emplace(x, y);
                            vis[x][y] = vid;
                            pixels++;
                            total += View::imgGS[x][y];
                        }
                    }
                }
            }
            total /= pixels;
            temp[i][j] = total;
        }
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void FilterGS::crop() {
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
                View::imgGS[i][j] = 0;
}

void FilterGS::skewHorizontally() {
    int degree;
    while (true) {
        std::cout << "Enter the skew degree [0-45].\n";
        std::cin >> degree;
        if (degree >= 0 && degree <= 45)
            break;
        std::cout << "Invalid degree.\n";
    }
    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
    double scale = tan(degree * 3.14 / 180) * 256.0;
    double toTake = 256 / (256 - scale);
    double minus = scale / 256, cur = 0, here = 0;
    for (int row = 0; row < Constant::SIZE; row++) {
        here += minus, cur = 0;
        for (int col = scale - here; col < Constant::SIZE - here; col++) {
            int avg = 0, pixels = 0;
            for (int k = std::max(0, (int) ceil(cur - toTake)); k < std::min(Constant::SIZE, (int) ceil(cur + toTake)); k++)
                pixels++, avg += View::imgGS[row][k];
            avg /= std::max(1, pixels);
            temp[row][col] = avg;
            cur += toTake;
        }
    }
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}

void FilterGS::skewVertically() {

    unsigned char temp[Constant::SIZE][Constant::SIZE]{};
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
    for (int row = 0; row < Constant::SIZE; row++) {
        here += minus, cur = 0;
        for (int col = scale - here; col < Constant::SIZE - here; col++) {
            int avg = 0, pixels = 0;
            for (int k = std::max(0, (int) ceil(cur - toTake)); k < std::min(Constant::SIZE, (int) ceil(cur + toTake)); k++)
                pixels++, avg += View::imgGS[k][row];
            avg /= std::max(1, pixels);
            temp[col][row] = avg;
            cur += toTake;
        }
    }
    for (int i = 0; i < Constant::SIZE; i++)
        for (int j = 0; j < Constant::SIZE; j++)
            View::imgGS[i][j] = temp[i][j];
}