#ifndef PRACOWNIKFIZYCZNY_H
#define PRACOWNIKFIZYCZNY_H

#include "pracownik.h"

#include <string>



using namespace std;



class pracownikFizyczny : public pracownik
{
    public:
        pracownikFizyczny();
        pracownikFizyczny(string imie, string nazwisko, int wiek,
                          string firma,
                          int stawka_h, int premia); //premia podawana w %
        ~pracownikFizyczny();

        void wyswietl_pf();

    private:
        int stawka_h;
        int premia;
};

#endif // PRACOWNIKFIZYCZNY_H
