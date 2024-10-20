#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
#include "Student.h"
class Compare
{
    public:
        bool operator( ) (Student &s1, Student &s2);
};
#endif // COMPARE_H_INCLUDED
