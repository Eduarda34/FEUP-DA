//
// Created by ricar on 06/03/2024.
//

#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>



fileReader::fileReader(const int &filename, char delimiter)
    : delimiter(delimiter) {
    file_stream.open(filename);
}
