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

/*void show(); //metodę show wyświetlającą informację o mieszkańcu;

std::string getName();
std::string getSurname();
int getAge();
char getSex();
std::string getPostalCode();*/

