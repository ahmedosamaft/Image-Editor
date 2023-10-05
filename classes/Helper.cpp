//
// Created by andro on 10/4/2023.
//

#include "Helper.h"
#include "View.h"

int Helper::runMenu(const std::vector<std::string> &menu) {
    for (int i = 0; i < menu.size(); ++i) {
        printf("%d - %s\n", i + 1, menu[i].c_str());
    }
    printf("0 - Exit\n");
    printf("Choice >> ");
    int inp;
    while (true) {
        std::cin >> inp;
        if (std::cin.fail() || inp > menu.size() || inp < 0) {
            std::cout << "ERROR please input a number in range 1 to " << menu.size() << ": ";
            std::cin.ignore();
        } else
            return inp;
    }
}

void Helper::getInitialImage(int &choice) {
    if (choice == 1) {
        for (int i = 0; i < Constant::SIZE; ++i) {
            for (int j = 0; j < Constant::SIZE; ++j) {
                View::imgGS[i][j] = View::initialGS[i][j];
            }
        }
    } else {
        for (int i = 0; i < Constant::SIZE; ++i) {
            for (int j = 0; j < Constant::SIZE; ++j) {
                for (int k = 0; k < Constant::RGB; ++k) {
                    View::imgRGB[i][j][k] = View::initialRGB[i][j][k];
                }
            }
        }
    };
}
