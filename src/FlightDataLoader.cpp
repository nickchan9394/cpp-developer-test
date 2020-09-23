#include <fstream>
#include <iostream>
#include "FlightDataLoader.h"

using namespace std;

void FlightDataLoader::load(string filePath) {
    _coordinates.clear();
    ifstream infile(filePath, ios::binary);
    if(infile.is_open()) {
        while(infile) {
            Coordinate coordinate;
            infile.read(reinterpret_cast<char*>(&coordinate.timestamp), sizeof(time_t));
            infile.read(reinterpret_cast<char*>(&coordinate.latitude), sizeof(double));
            infile.read(reinterpret_cast<char*>(&coordinate.longitude), sizeof(double));
            infile.read(reinterpret_cast<char*>(&coordinate.altitude), sizeof(double));
            _coordinates.push_back(coordinate);
        }
        infile.close();
    }
}

vector<Coordinate> FlightDataLoader::getCoordinates() {
    return _coordinates;
}