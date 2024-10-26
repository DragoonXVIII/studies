#include "car.h"

Car::Car(const string& model, int productionYear, double engineCapacity)
    : model(model), productionYear(productionYear), engineCapacity(engineCapacity) {}

string Car::getModel() const
{
    return model;
}

int Car::getProductionYear() const
{
    return productionYear;
}

double Car::getEngineCapacity() const
{
    return engineCapacity;
}

void Car::setModel(const string& model)
{
    this->model = model;
}

void Car::setProductionYear(int year)
{
    productionYear = year;
}

void Car::setEngineCapacity(double capacity)
{
    engineCapacity = capacity;
}

void Car::display() const
{
    cout << "Model: " << model
         << ", Rok produkcji: " << productionYear
         << ", Pojemnosc silnika: " << engineCapacity << " L" << endl;
}
