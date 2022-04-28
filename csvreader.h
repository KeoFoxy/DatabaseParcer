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
#include <QMessageBox>

#include "abstractreader.h"
#include "csvexception.h"


class CSVReader: public AbstractReader
{
    std::ifstream fin;
    bool flag;
    int lineNum = 0;

public:
    CSVReader(const QString &filename);
    ~CSVReader();

    std::vector<std::string> split_line(const std::string &str, char delim);

    virtual bool is_open() override {return fin.is_open(); };

    virtual std::vector<Vehicle> readAll() override;

    CSVReader(const CSVReader&) = delete;
    CSVReader& operator=(const CSVReader&) = delete;

    CSVReader(CSVReader &&reader)
    {
        this->fin = std::move(reader.fin);
    };

   // CSVReader operator =(CSVReader &&c) { return std::move(c);};
    CSVReader& operator>>(Vehicle& vehicles) override
    {
        try
        {
        if(fin.eof())
         {
            flag = false;
         }

        if(!fin.eof())
        {
            flag = true;

            std::string line;
            std::getline(fin, line);

            std::vector<std::string> v = split_line(line, ';');

            //Vehicle temp;
            vehicles.ID = std::stoi(v[0]);
            vehicles.brand_and_model = QString::fromStdString(v[1]);
            vehicles.color = static_cast<Color>(stoi(v[2]));
            vehicles.year = stoi(v[3]);

            lineNum++;
        }


        return *this;
        }
        catch(std::logic_error &error)
        {
            throw CSVException("Error", lineNum);
        }
    }


    virtual operator bool() const override
    {
        return flag;
    }
};



#endif // CSVREADER_H
