//
// Created by Tomás Rodrigues on 19/03/2024.
//

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
    void addCity(cities acity);
    void addPipes(pipes apipe);
    void addReservoirs(reservoirs areservoir);
    void addStations(stations astation);

public:

    //Constructor
    Data();


    //Getters
    vector<cities> getCities();
    vector<pipes> getPipes();
    vector<reservoirs> getReservoirs();
    vector<stations> getStations();


    //Readers
    void readCities();
    void readPipes();
    void readReservoirs();
    void readStations();
};


#endif //DA_PROJECT1_DATA_H
