#ifndef CATALOG_H
#define CATALOG_H

#include "car.h"
#include <QVector>

class Catalog
{
    private:
        QVector<Car> cars;
    public:
        Catalog(){};
        ~Catalog(){};
        bool addCar(Car c);
        bool deleteCar(QString vinNumber);
        void sortA();
        void sortY();
        int countC(int yearOfProduction);
        QVector<Car> getCars() const {return cars;};
};

#endif // CATALOG_H
