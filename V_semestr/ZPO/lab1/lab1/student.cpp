#include "Student.h"


Student::Student(string name1, string surname1, int age1, string index1) : Person(name1, surname1, age1), index(index1)
{
    cout << "Constructor of class Student" << endl;
}

void Student::setIndex(string newIndex)
{
    index = newIndex;
}

string Student::getIndex()
{
    return index;
}

void Student::showInfoStudent()
{
    showInfoPerson();
    cout << "Index: " << index << endl;
}
