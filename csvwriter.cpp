#include "csvwriter.h"

csvwriter::csvwriter(const QString &filename)
{
    fout.open(filename.toLatin1().data());
}

void csvwriter::writeAll(std::vector<Vehicle> vehicle)
{
    if(!fout.is_open())
    {
        std::cout<<"Error! File hasn't been opened"<< std::endl;
    }
    else
    {
        for(int i = 0; i <int(vehicle.size()); i++)
        {
            fout << (vehicle[i]).ID << ";" << ((vehicle[i]).brand_and_model).toStdString() << ";" << (vehicle[i]).color << ";" << (vehicle[i]).year << std::endl;
        }
    }
}

csvwriter::~csvwriter()
{
    fout.close();
}

std::ostream& operator<<(std::ostream& _fout, const Vehicle &vehicles)
{
    _fout << vehicles.to_string().toLatin1().data();
    return _fout;
}
