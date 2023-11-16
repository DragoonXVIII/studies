#ifndef PRACOWNIKUMYSLOWY_H
#define PRACOWNIKUMYSLOWY_H

#include "pracownik.h"

#include <string>



using namespace std;



class pracownikUmyslowy : private pracownik
{
    public:
        pracownikUmyslowy();
        pracownikUmyslowy(string imie, string nazwisko, int wiek,
                          string firma,
                          int stawka_h, int premia); //premia podawana w %
        ~pracownikUmyslowy();

        virtual void wyswietl();

    protected:
        int wynagordzenie_m;

};

#endif // PRACOWNIKUMYSLOWY_H
