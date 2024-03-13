//
// Created by ricar on 13/03/2024.
//

#include "pipes.h"

pipes::pipes(std::string spA, std::string spB, int capacity, bool direction)
    : spA(spA), spB(spB), capacity(capacity), direction(direction) {}

    std::string pipes::getSpA() {return spA;}
    std::string pipes::getSpB() {return spB;}
    int pipes::getCapacity() {return capacity;}
    bool pipes::getDirection() {return direction;}