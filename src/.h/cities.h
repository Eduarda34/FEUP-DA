#ifndef FEUP_DA_CITIES_H
#define FEUP_DA_CITIES_H

#include <iostream>

using namespace std;

class cities {

    std::string city;
    int id;
    std::string code;
    double demand;
    std::string population;

public:

    /**
     * @brief constructor used to initialize the members of the 'cities' class with the values passed
     * to the constructor when creating a 'cities' object
     * @param city
     * @param id
     * @param code
     * @param demand
     * @param population
     */
    cities(std::string city, int id, std::string code, double demand, std::string population);

    /**
     * @return city
     */
    std::string getCity();

    /**
     * @return id
     */
    int getId();

    /**
     * @return code
     */
    std::string getCode();

    /**
     * @return demand
     */
    double getDemand();

    /**
     * @return population
     */
    std::string getPopulation();

};


#endif //FEUP_DA_CITIES_H
