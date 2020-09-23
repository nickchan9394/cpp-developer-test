#include <string>
#include <vector>
#include "Coordinate.h"

using namespace std;

#ifndef FlightDataLoader_H_
#define FlightDataLoader_H_

class FlightDataLoader
{
private:
    vector<Coordinate> _coordinates;

public:
    FlightDataLoader() {
        _coordinates = vector<Coordinate> {};
    }
    void load(string filePath);
    vector<Coordinate> getCoordinates();
};

#endif