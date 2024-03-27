#include "../.h/stations.h"

stations::stations(int id, std::string code)
        : id(id), code(code) {}

int stations::getId() {return id;}
std::string stations::getCode() {return code;}
