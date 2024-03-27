#ifndef FEUP_DA_CITIES_H
#define FEUP_DA_CITIES_H

#include <iostream>

using namespace std;

class cities {

    std::string city;
    int id;
    std::string code;
    float demand;
    std::string population;

public:

    cities(std::string city, int id, std::string code, float demand, std::string population);
    std::string getCity();
    int getId();
    std::string getCode();
    float getDemand();
    std::string getPopulation();

};


#endif //FEUP_DA_CITIES_H
