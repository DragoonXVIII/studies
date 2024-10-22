#ifndef CAR_H
#define CAR_H

#include <QString>

class Car
{
    private:
        QString brand;
        QString model;
        int yearOfProduction;
        QString vin;

    public:
        Car(QString brand, QString model, int yearOfProduction, QString vin): brand(brand), model(model), yearOfProduction(yearOfProduction), vin(vin){};
        QString getBrand() const;
        QString getModel() const;
        int getYearOfProduction() const;
        QString getVin() const;
        QString getInfo() const;
};

#endif // CAR_H
