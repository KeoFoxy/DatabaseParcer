#include "vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(int _ID, QString _brand_and_model, Color _color, int _year)
{
    this->ID = _ID;
    this->brand_and_model = _brand_and_model;
    this->color = _color;
    this->year = _year;
}

Vehicle::~Vehicle()
{

}

QString Vehicle::to_string() const
{
    return QString::number(ID) + ";" + brand_and_model + ";" + QString::number(color) + ";" + QString::number(year);
}
