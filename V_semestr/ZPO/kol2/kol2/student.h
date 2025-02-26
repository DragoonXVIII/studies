#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    public:
        std::string imie;
        std::string numer_indeksu;
        Student(const std::string& imie, const std::string& numer_indeksu): imie(imie), numer_indeksu(numer_indeksu) {}
};

#endif // STUDENT_H
