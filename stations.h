//
// Created by ricar on 13/03/2024.
//

#ifndef FEUP_DA_STATIONS_H
#define FEUP_DA_STATIONS_H

#include <iostream>

using namespace std;

class stations {

    int id;
    std::string code;

public:

    stations(int id, std::string code);
    int getId();
    std::string getCode();

};


#endif //FEUP_DA_STATIONS_H
