#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "osoba.h"

#include <string>



using namespace std;



class pracownik : public osoba
{
    public:
        pracownik();
        pracownik(string imie, string nazwisko, int wiek, string firma);
        ~pracownik();
        void wyswietl_p();

        string firma;

    private:
        //string firma;

};

#endif // PRACOWNIK_H
