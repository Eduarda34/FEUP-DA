#include "src/.h/cities.h."

cities::cities(std::string city, int id, std::string code, float demand, std::string population)
    : city(city), id(id), code(code), demand(demand), population(population) {}

    std::string cities::getCity() {return city;}
    int cities::getId() {return id;}
    std::string cities::getCode() {return code;}
    float cities::getDemand() {return demand;}
    std::string cities::getPopulation() {return population;}