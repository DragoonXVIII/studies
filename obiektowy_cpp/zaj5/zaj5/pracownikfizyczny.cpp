#include "pracownikfizyczny.h"

#include <iostream>


using namespace std;



pracownikFizyczny::pracownikFizyczny()
{
    cout<<"Utworzono obiekt klasy <pracownikFizyczny> konstruktorem <bez parametrow>"<<endl;
}


pracownikFizyczny::pracownikFizyczny(string imie, string nazwisko, int wiek,
                  string firma,
                  int stawka_h, int premia)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;
    this->firma=firma;
    this->stawka_h=stawka_h;
    this->premia=premia;


    cout<<"Utworzono obiekt klasy <pracownikFizyczny> konstruktorem <z parametrami>"<<endl;
}


pracownikFizyczny::~pracownikFizyczny()
{
    cout<<"Usunieto obiekt klasy <pracownikFizyczny>"<<endl;
}


void pracownikFizyczny::wyswietl_pf()
{
    cout<<"+=== PRACOWNIK FIZYCZNY ===+"<<endl;
    wyswietl_p();
    cout<<"Dane szczegolowe pracownika:"<<endl;
    cout<<"Zarobki: "<<stawka_h<<"/h ";
    cout<<"Premia: "<<premia<<"%."<<endl;
}
