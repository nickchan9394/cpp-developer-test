#include <iostream>
#include "Coordinate.h"

#ifndef PhotoWriter_H_
#define PhotoWriter_H_

using namespace std;

class PhotoWriter
{
public:
    virtual void write(string picPath, Coordinate coordinate);
};
#endif