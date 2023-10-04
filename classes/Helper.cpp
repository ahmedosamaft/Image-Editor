//
// Created by andro on 10/4/2023.
//

#include "Helper.h"
#include <iostream>

char Helper::runMenu(const std::vector<std::string> &menu) {
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
            return char(inp + 48);
    }
}
