#include <string>
#include <tuple>
#include <vector>
#include <iterator>
#include "Coordinate.h"

using namespace std;

#ifndef PhotoRepository_H_
#define PhotoRepository_H_

class PhotoRepository
{
private:
    vector<tuple<time_t, string>> _images;

public:
    PhotoRepository() {
        _images = vector<tuple<time_t, string>>();
    }
    void add(time_t timestamp, string picPath);
    void clear();
    vector<tuple<string,Coordinate>> match(vector<Coordinate> coordinates);
    vector<tuple<time_t, string>>::iterator begin();
    vector<tuple<time_t, string>>::iterator end();
};
#endif