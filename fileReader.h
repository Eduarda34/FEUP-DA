//
// Created by ricar on 06/03/2024.
//

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class fileReader {

private:
    std::string filename;
    std::string delimiter = ",";
public:

    fileReader();

    readFile(const std::string& filename, const std::string& delimiter);

    std::vector<std::vector<std::string>> getData();

};
