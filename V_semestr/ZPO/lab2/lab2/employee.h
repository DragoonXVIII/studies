#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee
{
protected:
    std::string surname;
    int age;
    int experience;
    double salary;

public:

    Employee(std::string s, int a, int e, double sal)
        : surname(s), age(a), experience(e), salary(sal) {}
    Employee() : surname(""), age(0), experience(0), salary(0.0) {}
    virtual ~Employee();

    virtual void show() const;
    virtual int calculateSalary(int value) = 0;
    int ageEmployment() const;

    std::string getSurname() const;
    int getAge() const;
    int getExperience() const;

};
#endif // EMPLOYEE_H
