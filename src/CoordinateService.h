#include "PhotoRepository.h"
#include "FlightDataLoader.h"
#include "PhotoWriter.h"

#ifndef CoordinateService_H_
#define CoordinateService_H_

class CoordinateService
{
private:
    PhotoRepository *_photoRepo;
    FlightDataLoader *_dataLoader;
    PhotoWriter *_photoWriter;

public:
    CoordinateService(PhotoRepository *photoRepo, FlightDataLoader *dataLoader, PhotoWriter *photoWriter) {
        _photoRepo = photoRepo;
        _dataLoader = dataLoader;
        _photoWriter = photoWriter;
    }

    void writeCoordinatesToPhotos(string dataFilePath, vector<tuple<time_t, string>> photos);
};
#endif