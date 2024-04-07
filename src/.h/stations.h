#ifndef FEUP_DA_STATIONS_H
#define FEUP_DA_STATIONS_H

#include <iostream>

using namespace std;

class stations {

    int id;
    std::string code;

public:

    stations(int id, std::string code);

    /**
     * @return id
     */
    int getId();

    /**
     * @return code
     */
    std::string getCode();

};


#endif //FEUP_DA_STATIONS_H
