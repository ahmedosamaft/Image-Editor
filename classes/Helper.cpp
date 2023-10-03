//
// Created by andro on 10/4/2023.
//

#include "Helper.h"
#include <iostream>

char Helper::runMenu(const std::vector<std::string> &menu) {
    for (int i = 0; i < menu.size(); ++i) {
        printf("%d - %s\n",i + 1,menu[i].c_str());
    }
    printf("0 - Exit\n");
    printf("Choice >> ");
    char inp;
    std::cin >> inp;
    return inp;
}
