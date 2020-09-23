#include <vector>
#include "../src/PhotoWriter.h"

using namespace std;

class MockPhotoWriter : public PhotoWriter {

public:
    vector<tuple<string,Coordinate>> actual;
    
    MockPhotoWriter() {
        actual = vector<tuple<string,Coordinate>>();
    }

    void write(string picPath, Coordinate coordinate) {
        actual.push_back(make_tuple(picPath,coordinate));
    }
};