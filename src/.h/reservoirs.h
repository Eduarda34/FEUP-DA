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

    /**
     * @brief constructor
     * @param name
     * @param municipality
     * @param id
     * @param code
     * @param maxDelivery
     */
    reservoirs(std::string name, std::string municipality, int id, std::string code, double maxDelivery);

    /**
     * @return name
     */
    std::string getName();

    /**
     * @return municipality
     */
    std::string getMunicipality();

    /**
     * @return id
     */
    int getId();

    /**
     * @return code
     */
    std::string getCode();

    /**
     * @return maxDelivery
     */
    double getMaxDel();

};


#endif //FEUP_DA_RESERVOIRS_H
