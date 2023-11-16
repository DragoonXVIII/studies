#include "pracownik.h"

#include <iostream>


using namespace std;



pracownik::pracownik()
{
    cout<<"Utworzono obiekt klasy <student> konstruktorem <bez parametrow>"<<endl;
}


pracownik::pracownik(string imie, string nazwisko, int wiek, string firma)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;
    this->firma=firma;
    cout<<"Utworzono obiekt klasy <student> konstruktorem <z parametrami>"<<endl;
}


pracownik::~pracownik()
{
    cout<<"Usunieto obiekt klasy <pracownik>"<<endl;
}


void pracownik::wyswietl()
{
    cout<<"+=== PRACOWNIK ===+"<<endl;
    osoba::wyswietl();
    cout<<"Dane ogolne pracownika: ";
    cout<<"firma: "<<firma<<endl;

    return;
}
