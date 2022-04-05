#ifndef VEHICLE_H
#define VEHICLE_H
#include <QString>
#include <vehicle_color.h>

class Vehicle{
public:
    int ID;
    QString brand_and_model;
    Color color;
    int year;
Vehicle();
Vehicle(int _ID, QString _brand_and_model, Color _color, int _year);
~Vehicle();
};

#endif // VEHICLE_H

