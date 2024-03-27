#ifndef FEUP_DA_RESERVOIRS_H
#define FEUP_DA_RESERVOIRS_H

#include <iostream>

using namespace std;

class reservoirs {

    std::string name;
    std::string municipality;
    int id;
    std::string code;
    int maxDelivery;

public:

    reservoirs(std::string name, std::string municipality, int id, std::string code, int maxDelivery);
    std::string getName();
    std::string getMunicipality();
    int getId();
    std::string getCode();
    int getMaxDel();

};


#endif //FEUP_DA_RESERVOIRS_H
