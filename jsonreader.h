#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include "vehicle.h"
#include "json.hpp"

class JSONReader : public AbstractReader
{
private:
    int index = 0;
    nlohmann::json json;
    nlohmann::json::iterator j_start;

public:
    JSONReader(const QString &filename);
    ~JSONReader();

   virtual bool is_open() override
    {
        return fin.is_open();
    }

    virtual AbstractReader& operator>>(Vehicle& vehicles) override
    {
        //vehicles.ID = 0;
        std::string temp_model;

        if(j_start != json.end())
        {

        vehicles.ID = j_start.value()["id"];
        temp_model = j_start.value()["model"];
        vehicles.color = j_start.value()["color"];
        vehicles.year = j_start.value()["year"];
        vehicles.brand_and_model = QString::fromStdString(temp_model);

        }
        j_start++;

        return *this;
    }

    virtual operator bool() const override
    {
        return j_start - 1 != json.end();
    }




    std::vector<Vehicle> readAll() override;
};

#endif // JSONREADER_H
