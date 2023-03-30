#ifndef STUDENT_H
#define STUDENT_H

#include "osoba.h"
#include <string>



using namespace std;



class student : protected osoba
{
    public:
        student();
        student(string imie, string nazwisko, int wiek, string uczelnia, float *oceny);
        ~student();

        virtual void wyswietl();
        virtual void wczytaj();

        float srednia();
        bool czy_zaliczyl();

    private:
        string uczelnia;
        float *oceny;
        int n;
};

#endif // STUDENT_H
