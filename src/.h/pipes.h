#ifndef FEUP_DA_PIPES_H
#define FEUP_DA_PIPES_H

#include <iostream>

using namespace std;

class pipes {

    std::string spA;
    std::string spB;
    double capacity;
    bool direction;

public:

    /**
     * @brief constructor is used to initialize the members of the 'pipes' with the values passed to
     * the constructor when creating a 'pipes' object
     * @param spA
     * @param spB
     * @param capacity
     * @param direction
     */
    pipes(std::string spA, std::string spB, double capacity, bool direction);

    /**
     * @return spA
     */
    std::string getSpA();

    /**
     * @return spB
     */
    std::string getSpB();

    /**
     * @return capacity
     */
    double getCapacity();

    /**
     * @return direction
     */
    bool getDirection();

};


#endif //FEUP_DA_PIPES_H
