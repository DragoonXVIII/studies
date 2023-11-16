#ifndef PRACOWNIKFIZYCZNY_H
#define PRACOWNIKFIZYCZNY_H

#include "pracownik.h"

#include <string>



using namespace std;



class pracownikFizyczny : private pracownik
{
    public:
        pracownikFizyczny();
        pracownikFizyczny(string imie, string nazwisko, int wiek,
                          string firma,
                          int stawka_h, int premia); //premia podawana w %
        ~pracownikFizyczny();

        virtual void wyswietl();
        void zarobki();

    protected:
        int stawka_h;


};

#endif // PRACOWNIKFIZYCZNY_H
