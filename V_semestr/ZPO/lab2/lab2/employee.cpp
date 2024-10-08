#include "Employee.h"
void Employee::show() const
{
    std::cout << "Employee: " << surname << ", Age: " << age
              << ", Experience: " << experience << " years, Salary: " << salary << " PLN\n";
}

int Employee::ageEmployment() const
{
    return age - experience;
}

std::string Employee::getSurname() const
{
    return surname;
}

int Employee::getAge() const
{
    return age;
}

int Employee::getExperience() const
{
    return experience;
}

Employee::~Employee() {}
