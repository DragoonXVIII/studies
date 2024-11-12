#include "citizen.h"

Citizen::Citizen()
{

}

void Citizen::show() const
{
    std::cout << "Name: " << name
              << " Surname: " << surname
              << " Age: " << age
              << " Sex: " << sex
              << " Postal: " << postalCode
              << std::endl;
}

std::string Citizen::getName() const
{
    return this->name;
}

std::string Citizen::getSurname() const
{
    return this->surname;
}
int Citizen::getAge() const
{
    return this->age;
}
char Citizen::getSex() const
{
    return this->sex;
}
std::string Citizen::getPostalCode() const
{
    return this->postalCode;
}

