#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Car
{
private:
    string model;
    int productionYear;
    double engineCapacity;

public:

    Car(const string& model, int productionYear, double engineCapacity);

    string getModel() const;
    int getProductionYear() const;
    double getEngineCapacity() const;

    void setModel(const string& model);
    void setProductionYear(int year);
    void setEngineCapacity(double capacity);
    void display() const;
};

#endif // CAR_H
