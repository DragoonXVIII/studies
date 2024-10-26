#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
public:
    string firstName;
    string lastName;
    char gender; // 'K', 'M' = kobieta/mezczyzna
    double grade;
    string email;

    Student(const string& fName, const string& lName, char gen, double grd, const string& mail)
        : firstName(fName), lastName(lName), gender(gen), grade(grd), email(mail) {};
};

#endif // STUDENT_H
