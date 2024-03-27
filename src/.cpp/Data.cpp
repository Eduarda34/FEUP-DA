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
    //readCities();
    //readPipes();
    readReservoirs();
    //readStations();
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

}

void Data::readPipes(){

}


void Data::readReservoirs(){
    ifstream file;
    file.open("dataset/Project1DataSetSmall/Reservoirs_Madeira.csv"); // Adjust file path here
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
    /*ifstream file("Stations.csv");
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string code;

        if (ss >> id >> code) {
            // Create station object and add to the vector
            stations astation(id, code);
            Stations.push_back(astation);
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    file.close();*/
}