#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "csvreader.h"
#include <vector>

class csvwriter
{
    std::ofstream fout;

public:
    csvwriter(const QString &filename);
    ~csvwriter();

    bool is_open() const {return fout.is_open();};
    void writeAll(std::vector<Vehicle> vehicle);

    csvwriter(const CSVReader&) = delete;
    csvwriter operator=(const CSVReader&) = delete;
    csvwriter(csvwriter &&c) : fout(std::move(c.fout)) {};
    csvwriter operator =(csvwriter &&c) { return std::move(c);};

};

#endif // CSVWRITER_H
