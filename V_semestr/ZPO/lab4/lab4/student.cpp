#include "Student.h"
Student::Student(int mark, string name)
{
    this->mark=mark;
    this->name=name;
}
int Student::getMark()
{
    return mark;
}
