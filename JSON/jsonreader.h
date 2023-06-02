#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include "json.hpp"
#include "films.h"

#include <QString>

class JSONReader : public AbstractReader
{
public:
    JSONReader(const QString &fileName);

    virtual bool is_open() override { return fin.is_open(); }
    virtual std::vector<Films> readAll() override;

};

#endif // JSONREADER_H
