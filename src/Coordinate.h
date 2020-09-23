#include <time.h>

#ifndef COORDINATE_H_
#define COORDINATE_H_
struct Coordinate {
    time_t timestamp;
    double latitude;
    double longitude;
    double altitude;
};
#endif