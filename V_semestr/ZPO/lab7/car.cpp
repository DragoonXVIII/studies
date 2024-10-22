#include "car.h"

QString Car::getBrand() const
{
    return this->brand;
}
QString Car::getModel() const
{
    return this->model;
}

int Car::getYearOfProduction() const
{
    return this->yearOfProduction;
}

QString Car::getVin() const
{
    return this->vin;
}

QString Car::getInfo() const
{
    return QString(this->brand+" "+this->model+" "+QString::number(this->yearOfProduction)+" "+this->vin);
}
