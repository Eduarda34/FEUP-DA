//
// Created by Tomás Rodrigues on 27/03/2024.
//

#include "../.h/Data.h"
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;


//Adders
void Data::addCity(cities acity){Cities.push_back(acity);}
void Data::addPipes(pipes apipe){Pipes.push_back(apipe);}
void Data::addReservoirs(reservoirs areservoir){Reservoirs.push_back(areservoir);}
void Data::addStations(stations astation){Stations.push_back(astation);}

//Constructor
Data::Data(){
    readCities();
    readPipes();
    readReservoirs();
    readStations();
}


//Getters
vector<cities> Data::getCities(){
    return this->Cities;
}
vector<pipes> Data::getPipes(){
    return this->Pipes;
}
vector<reservoirs> Data::getReservoirs(){
    return this->Reservoirs;
}
vector<stations> Data::getStations(){
    return this->Stations;
}


//Readers
void Data::readCities(){
    ifstream file;
    file.open("../dataset/Project1DataSetSmall/Cities_Madeira.csv"); // Adjust file path here
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Skip the header line
    getline(file, line);

    std::vector<std::string> row; // Declare row as a vector of strings
    std::string word;
    while (getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        if (line[line.size()-1] == '\r') {
            line.resize(line.size()-1);
        }

        row.clear();
        std::stringstream str(line);

        while (getline(str, word, ',')) {
            row.push_back(word);
        }

        try {
            if (row.size() >= 5) {
                string city = row[0];
                int id = std::stoi(row[1]);
                string code = row[2];
                float demand = std::stof(row[3]);
                string population = row[4];

                // Create city object and add to the vector
                cities aCity(city, id, code, demand, population);
                Cities.push_back(aCity);
            } else {
                cerr << "Error: Insufficient data in line: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error parsing line: " << line << ", " << e.what() << endl;
        }
    }

    file.close();
}

void Data::readPipes(){
    ifstream file;
    file.open("../dataset/Project1DataSetSmall/Pipes_Madeira.csv"); // Adjust file path here
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Skip the header line
    getline(file, line);

    std::vector<std::string> row; // Declare row as a vector of strings
    std::string word;
    while (getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        if (line[line.size()-1] == '\r') {
            line.resize(line.size()-1);
        }

        row.clear();
        std::stringstream str(line);

        while (getline(str, word, ',')) {
            row.push_back(word);
        }

        try {
            if (row.size() >= 4) {
                string spA = row[0];
                string spB = row[1];
                int capacity = std::stoi(row[2]);
                bool direction = (row[3] == "true");

                // Create pipe object and add to the vector
                pipes aPipe(spA, spB, capacity, direction);
                Pipes.push_back(aPipe);
            } else {
                cerr << "Error: Insufficient data in line: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error parsing line: " << line << ", " << e.what() << endl;
        }
    }

    file.close();
}

void Data::readReservoirs(){
    ifstream file;
    file.open("../dataset/Project1DataSetSmall/Reservoirs_Madeira.csv"); // Adjust file path here
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Skip the header line
    getline(file, line);


    std::vector<std::string> row; // Declare row as a vector of strings
    std::string word;
    while (getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        if (line[line.size()-1] == '\r') {
            line.resize(line.size()-1);
        }

        row.clear();
        std::stringstream str(line);


        while (getline(str, word, ',')) {
            row.push_back(word);
        }

        try {
            if (row.size() >= 5) {
                string reservoir = row[0];
                string municipality = row[1];
                int id = std::stoi(row[2]);
                string code = row[3];
                int maxDelivery = std::stoi(row[4]);

                // Create reservoir object and add to the vector
                reservoirs areservoir(reservoir, municipality, id, code, maxDelivery);
                Reservoirs.push_back(areservoir);
            } else {
                cerr << "Error: Insufficient data in line: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error parsing line: " << line << ", " << e.what() << endl;
        }
    }

    file.close();
}

void Data::readStations(){
    ifstream file;
    file.open("../dataset/Project1DataSetSmall/Stations_Madeira.csv"); // Adjust file path here
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Skip the header line
    getline(file, line);

    std::vector<std::string> row; // Declare row as a vector of strings
    std::string word;
    while (getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        if (line[line.size()-1] == '\r') {
            line.resize(line.size()-1);
        }

        row.clear();
        std::stringstream str(line);

        while (getline(str, word, ',')) {
            row.push_back(word);
        }

        try {
            if (row.size() >= 2) {
                int id = std::stoi(row[0]);
                string code = row[1];

                // Create station object and add to the vector
                stations aStation(id, code);
                Stations.push_back(aStation);
            } else {
                cerr << "Error: Insufficient data in line: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error parsing line: " << line << ", " << e.what() << endl;
        }
    }

    file.close();
}