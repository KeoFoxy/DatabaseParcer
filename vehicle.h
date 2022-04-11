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
    QString to_string() const;

    Vehicle(int _ID, QString _brand_and_model, Color _color, int _year);
    ~Vehicle();

    bool operator<(const Vehicle& vehicles)
    {
        return this->year > vehicles.year;
    }
};

#endif // VEHICLE_H

