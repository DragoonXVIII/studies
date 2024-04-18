#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "osoba.h"

#include <string>



using namespace std;



class pracownik : protected osoba
{
    public:
        pracownik();
        pracownik(string imie, string nazwisko, int wiek, string firma);
        ~pracownik();

        virtual void wyswietl();

        //string firma;

    protected:
        string firma;
        int premia;

};

#endif // PRACOWNIK_H
