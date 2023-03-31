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

        virtual void wyswietl();
        virtual void wczytaj();

    protected:
        string imie;
        string nazwisko;
        int wiek;

};

#endif // OSOBA_H
