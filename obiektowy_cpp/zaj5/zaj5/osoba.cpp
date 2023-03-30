#include "osoba.h"

#include <iostream>


using namespace std;



osoba::osoba()
{
    cout<<"Utworzono obiekt klasy <osoba> konstruktorem <bez parametrow>"<<endl;
}


osoba::osoba(string imie, string nazwisko, int wiek)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;

    cout<<"Utworzono obiekt klasy <osoba> konstruktorem <z parametrami>"<<endl;
}


osoba::~osoba()
{
    cout<<"Usunieto obiekt klasy <osoba>"<<endl;
}


void osoba::wczytaj()
{
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj wiek: ";
    cin>>wiek;

    return;
}


void osoba::wyswietl()
{
    cout<<"+=== OSOBA ===+"<<endl;
    cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
    return;
}
