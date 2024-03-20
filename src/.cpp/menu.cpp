#include "src/.h/menu.h"
#include <chrono>
#include <iostream>

Menu::Menu() = default;

void Menu::start() {
    int option;
    cout << endl
        << "Welcome!" << endl
        << "1. Basic Service Metries" << endl
        << "2. Reliability and sensitivity to failures" << endl;

    cin >> option;

    switch (option) {
        case 1:
            //--
            break;

        case 2:
            //--
            break;

        default:
            break;
    }
}