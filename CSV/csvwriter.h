#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "films.h"

//#include <iostream>
#include <vector>
#include <fstream>

#include <QString>
#include <QDir>

class CSVWriter
{
public:
    CSVWriter() { fout.open((QDir::currentPath() + "//DataBaseOutput.csv").toLatin1().data()); }
    CSVWriter(const QString &fileName);

    bool is_open() const { return fout.is_open(); };

    void writeAll(const std::vector<Films> &films);

private:
    std::ofstream fout;
};

#endif // CSVWRITER_H
