#include "jsonreader.h"

JSONReader::JSONReader(const QString &filename)
{
    fin.open(filename.toLatin1().data());
    fin >> json;
    j_start = json.begin();

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

    for(const auto& j: json)
       {
            Vehicle result;
            result.ID = j["id"];
            result.brand_and_model = QString::fromStdString(j["model"]);
            result.color = static_cast<Color>(j["color"]);
            result.year = j["year"];

            vehicles.push_back(result);
      }

      return vehicles;


}
