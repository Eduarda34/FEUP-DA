//
// Created by ricar on 13/03/2024.
//

#ifndef FEUP_DA_PIPES_H
#define FEUP_DA_PIPES_H

#include <iostream>

using namespace std;

class pipes {

    std::string spA;
    std::string spB;
    int capacity;
    bool direction;

public:

    pipes(std::string spA, std::string spB, int capacity, bool direction);
    std::string getSpA();
    std::string getSpB();
    int getCapacity();
    bool getDirection();

};


#endif //FEUP_DA_PIPES_H
