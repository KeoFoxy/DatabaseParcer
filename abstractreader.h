#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <fstream>
#include "vehicle.h"
#include <vector>

class AbstractReader
{
public:
    std::ifstream fin;
public:
    virtual bool is_open() = 0;
    virtual std::vector<Vehicle> readAll() = 0;
};

#endif // ABSTRACTREADER_H
