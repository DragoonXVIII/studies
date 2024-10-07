#include<iostream>
#include"Person.h"
using namespace std;
Person::Person(string name1, string surname1, int age1)
{
    name=name1;
    surname=surname1;
    age=age1;
    cout<<"Konstruktor klasy bazowej - Person"<<endl;
}
Person::Person()
{
    cout<<"Konstruktor bez. klasy bazowej – Person"<<endl;
}
void Person::setAge(int age1)

{
    age=age1;
}
string Person::getSurname()
{
    return surname;
}
bool Person::is_18()
{
    if(age>=18)
        return true;
    else
        return false;
}
void Person::showInfoPerson()
{
    cout<<"Imie: "<<name<<" nazwisko: "<<surname<<
        " wiek: "<<age<<endl;
}
void Person::init(string name1, string surname1, int age1)
{
    name=name1;
    surname=surname1;
    age=age1;
}
