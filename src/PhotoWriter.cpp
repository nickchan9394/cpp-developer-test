#include <iostream>
#include "PhotoWriter.h"

void PhotoWriter::write(string picPath, Coordinate coordinate) {
    cout << "Writing (latitude " << coordinate.latitude << ", longitude " << coordinate.longitude << ", altitude " << coordinate.altitude << ") to \"" << picPath << "\"" << endl;
}