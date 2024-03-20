#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class fileReader {

private:
    std::ifstream file;
    std::string delimiter = ",";
public:
    fileReader(const std::string& filename, char delimiter);
    void readCities();
    void readPipes();
    void readReservoirs();
    void readStations();
};
