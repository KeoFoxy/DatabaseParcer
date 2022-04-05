#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include "vehicle.h"
#include "json.hpp"

class JSONReader : public AbstractReader
{
public:
    JSONReader(const QString &filename);
    ~JSONReader();

   virtual bool is_open() override
    {
        return fin.is_open();
    }

    std::vector<Vehicle> readAll() override;
};

#endif // JSONREADER_H
