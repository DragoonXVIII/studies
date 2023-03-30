#ifndef STUDENT_H
#define STUDENT_H

#include "osoba.h"
#include <string>



using namespace std;



struct oceny
{
    int przedmiot1;
    int przedmiot2;
    int przedmiot3;
};



class student : public osoba
{
    public:
        student();
        student(string imie, string nazwisko, int wiek, string uczelnia, struct oceny oceny);
        ~student();

        void wyswietl_s();
        float srednia();
        bool czy_zaliczyl();

    private:
        string uczelnia;
        oceny oceny;


};

#endif // STUDENT_H
