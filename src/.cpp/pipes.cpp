#include "../.h/pipes.h"

pipes::pipes(std::string spA, std::string spB, double capacity, bool direction)
        : spA(spA), spB(spB), capacity(capacity), direction(direction) {}

std::string pipes::getSpA() {return spA;}
std::string pipes::getSpB() {return spB;}
double pipes::getCapacity() {return capacity;}
bool pipes::getDirection() {return direction;}