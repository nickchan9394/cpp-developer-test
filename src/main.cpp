#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "PhotoRepository.h"
#include "FlightDataLoader.h"
#include "PhotoWriter.h"
#include "CoordinateService.h"

using namespace std;

int main() {    
    cout << endl;
    
    cout << "--------------------------------------" << endl;
    cout << "Writing GPS coordinates to image files" << endl;
    cout << "--------------------------------------" << endl;

    CoordinateService coordinateService = CoordinateService(
        new PhotoRepository(), new FlightDataLoader(), new PhotoWriter());

    coordinateService.writeCoordinatesToPhotos(
        "../../resources/flight-data2.bin", 
        vector<tuple<time_t, string>> {
            make_tuple(1539096140, "C:\\MyPhotos\\photo1.jpg"),
            make_tuple(1539096146, "C:\\MyPhotos\\photo5.jpg"),
            make_tuple(1539096143, "C:\\MyPhotos\\photo2.jpg"),
            make_tuple(1539096150, "C:\\MyPhotos\\photo3.jpg"),
            make_tuple(1539096145, "C:\\MyPhotos\\photo4.jpg")
    });

    cout << endl;

    return 0;
}
