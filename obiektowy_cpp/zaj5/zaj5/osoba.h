#ifndef OSOBA_H
#define OSOBA_H

#include <string>



using namespace std;



class osoba
{
    public:
        osoba();
        osoba(string imie, string nazwisko, int wiek);
        ~osoba();

        string imie;
        string nazwisko;
        int wiek;

        void wyswietl_o();

};

#endif // OSOBA_H
