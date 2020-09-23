#include "PhotoRepository.h"

using namespace std;

void PhotoRepository::add(time_t timestamp, string picPath)
{
    _images.push_back(make_tuple(timestamp, picPath));
}

void PhotoRepository::clear() {
    _images.clear();
}

vector<tuple<string,Coordinate>> PhotoRepository::match(vector<Coordinate> coordinates) {
    vector<tuple<string,Coordinate>> matches = vector<tuple<string,Coordinate>>();
    for(vector<Coordinate>::iterator coordinate = coordinates.begin(); coordinate < coordinates.end(); coordinate++) {
        for(vector<tuple<time_t,string>>::iterator pic = _images.begin(); pic < _images.end(); pic++) {
            if(std::get<0>(*pic) == (*coordinate).timestamp) {
                matches.push_back(make_tuple(std::get<1>(*pic),*coordinate));
            }
        }
    }
    return matches;
}

vector<tuple<time_t, string>>::iterator PhotoRepository::begin()
{
    return _images.begin();
}

vector<tuple<time_t, string>>::iterator PhotoRepository::end()
{
    return _images.end();
}