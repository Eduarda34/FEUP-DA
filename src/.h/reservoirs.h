#ifndef FEUP_DA_RESERVOIRS_H
#define FEUP_DA_RESERVOIRS_H

#include <iostream>

using namespace std;

class reservoirs {

    std::string name;
    std::string municipality;
    int id;
    std::string code;
    double maxDelivery;

public:

    reservoirs(std::string name, std::string municipality, int id, std::string code, double maxDelivery);
    std::string getName();
    std::string getMunicipality();
    int getId();
    std::string getCode();
    double getMaxDel();

};


#endif //FEUP_DA_RESERVOIRS_H
