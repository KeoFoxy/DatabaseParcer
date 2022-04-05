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
    Vehicle getVehicle(const std::vector<QString> &vehicleLine);
    
};



#endif // CSVREADER_H
