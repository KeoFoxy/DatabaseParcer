#ifndef CSVREADER_H
#define CSVREADER_H
#include <QString>
#include <fstream>
#include <iostream>
#include <string>
#include "vehicle.h"
#include <vector>
#include <sstream>
#include <QFile>
#include <QString>

class CSVReader
{
    std::ifstream fin;
public:
    CSVReader(const QString &filename);
    ~CSVReader();

    bool is_open() const{ return fin.is_open(); };

    std::vector<Vehicle> readAll();

    CSVReader(const CSVReader&) = delete;
    CSVReader operator=(const CSVReader&) = delete;
    CSVReader(CSVReader &&c) : fin(std::move(c.fin)) {};
    CSVReader operator =(CSVReader &&c) { return std::move(c);};
};



#endif // CSVREADER_H
