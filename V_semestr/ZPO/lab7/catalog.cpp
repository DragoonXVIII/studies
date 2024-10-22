#include "catalog.h"

bool Catalog::addCar(Car c)
{

    auto it = std::find_if(cars.begin(), cars.end(), [&c](const Car& existingCar)
    {
        return existingCar.getVin() == c.getVin(); // Porównanie VIN
    });

    if(it != cars.end())
    {
        return false;
    }
    this->cars.push_back(c);
    return true;
}

bool Catalog::deleteCar(QString vinNumber)
{
    auto it = std::remove_if(cars.begin(), cars.end(), [&vinNumber](const Car& car)
    {
        return car.getVin() == vinNumber;
    }); //remove jest smieszne bo przesunie na koniec element zadany i dopiero erease gu uwali, podobno szybsze niz inaczej, pewnie cos ze strukturą vectora.
    if (it != cars.end())
    {
       cars.erase(it, cars.end());
    }
    else
        return false;
    return true;
}

void Catalog::sortA()
{

    std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getBrand() < b.getBrand(); // Porównanie marek
    });
}

void Catalog::sortY()
{
    std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getYearOfProduction() > b.getYearOfProduction(); //porownywanie w odwrotnej kolejnosci oc by odwrocic
    });
}

int Catalog::countC(int yearOfProduction)
{
    int counter=0;
    for(const auto &car: cars) //&endy szybciej bez kopiowania, worth, const wiadomo coby nie poppsuc (chociaz tu u i tak nie ma co)
    {
        if(car.getYearOfProduction()<yearOfProduction)
            counter++;
    }
    return counter;
}

