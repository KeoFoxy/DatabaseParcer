#include "jsonreader.h"

JSONReader::JSONReader(const QString &filename)
{
    fin.open(filename.toLatin1().data());
}

JSONReader::~JSONReader()
{
    fin.close();
}

std::vector<Vehicle> JSONReader::readAll()
{
    std::vector<Vehicle> vehicles;
    nlohmann::json json;

    fin >> json;
    int count = 7;
    //count = json["count"];

    for(int i = 0; i < count - 1; i++)
    {
        Vehicle result;
        result.ID = json[i]["id"];
        result.brand_and_model = QString::fromStdString(json[i]["model"]);
        result.color = static_cast<Color>(json[i]["color"]);
        result.year = json[i]["year"];

        vehicles.push_back(result);
    }
    return vehicles;
}
