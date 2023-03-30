#ifndef PRACOWNIKUMYSLOWY_H
#define PRACOWNIKUMYSLOWY_H

#include "pracownik.h"

#include <string>



using namespace std;



class pracownikUmyslowy :public pracownik
{
public:
    pracownikUmyslowy();
    pracownikUmyslowy(string imie, string nazwisko, int wiek,
                      string firma,
                      int stawka_h, int premia); //premia podawana w %
    ~pracownikUmyslowy();

    void wyswietl_pu();

private:
    int wynagordzenie_m;
    int premia;
};

#endif // PRACOWNIKUMYSLOWY_H
