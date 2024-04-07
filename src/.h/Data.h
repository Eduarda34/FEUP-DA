#ifndef DA_PROJECT1_DATA_H
#define DA_PROJECT1_DATA_H

#include <vector>
#include "cities.h"
#include "pipes.h"
#include "reservoirs.h"
#include "stations.h"

using namespace std;

class Data {
private:
    vector<cities> Cities;
    vector<pipes> Pipes;
    vector<reservoirs> Reservoirs;
    vector<stations> Stations;

    //Adders

    /**
     * @brief adds a city to the city vector of this object
     * @param acity
     */
    void addCity(cities acity);

    /**
     * @brief adds a pipe to the pipe vector of this object
     * @param apipe
     */
    void addPipes(pipes apipe);

    /**
     * @brief adds a reservoir to the reservoir vector of this object
     * @param areservoir
     */
    void addReservoirs(reservoirs areservoir);

    /**
     * @brief adds a station to the station vector of this object
     * @param astation
     */
    void addStations(stations astation);

public:

    //Constructor
    Data();


    //Getters
    /**
     * @return vector Cities
     */
    vector<cities> getCities();

    /**
     * @return vector Pipes
     */
    vector<pipes> getPipes();

    /**
     * @return vector Reservoirs
     */
    vector<reservoirs> getReservoirs();

    /**
     * @return vector Pipes
     */
    vector<stations> getStations();


    //Readers
    void readCities();
    void readPipes();
    void readReservoirs();
    void readStations();
};


#endif //DA_PROJECT1_DATA_H
