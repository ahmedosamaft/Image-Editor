//
// Created by andro on 10/4/2023.
//

#include "View.h"
#include "Helper.h"
#include <iostream>

std::string View::imgName = std::string();
std::vector<std::string> View::menu = {
        "Black & White Filter",
        "Invert Filter",
        "Merge Filter",
        "Flip Image",
        "Darken and Lighten Image",
        "Rotate Image",
        "Detect Image Edges",
        "Enlarge Image",
        "Shrink Image",
        "Mirror 1/2 Image",
        "Shuffle Image",
        "Blur Image",
        "Crop Image",
        "Skew Image Right",
        "Skew Image Up",
        "Save the image to a file",
};

void View::mainMenu() {
    using namespace std;
    cout << "Hey Boy!\n"
         << "Please enter file name of the image to process (MUST BE IN imgs FOLDER):";
    cin >> imgName;
    while (true){
        cout << "Please select a filter to apply or 0 to exit:\n";
        char inp = Helper::runMenu(menu);
        if(inp == '0') break ;
        if(inp == '1');
    }
}
