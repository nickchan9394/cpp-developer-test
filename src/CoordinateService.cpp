#include <iostream>
#include "CoordinateService.h"

void CoordinateService::writeCoordinatesToPhotos(string dataFilePath, vector<tuple<time_t, string>> photos)
{
    _photoRepo->clear();

    for(vector<tuple<time_t, string>>::iterator ptr = photos.begin(); ptr < photos.end(); ptr++ ) {
        _photoRepo->add(std::get<0>(*ptr), std::get<1>(*ptr));
    }

    FlightDataLoader loader = FlightDataLoader();
    loader.load(dataFilePath);
    
    vector<tuple<string,Coordinate>> matches = _photoRepo->match(loader.getCoordinates());
    
    for(vector<tuple<string,Coordinate>>::iterator match = matches.begin(); match < matches.end(); match++) {
        _photoWriter->write(std::get<0>(*match), std::get<1>(*match));
    }
}