#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <fstream>
//#include <iostream>
#include <vector>

#include "films.h"

class AbstractReader
{
public:
    std::ifstream fin;

    virtual bool is_open() = 0;
    virtual std::vector<Films> readAll() = 0;
};

#endif // ABSTRACTREADER_H
