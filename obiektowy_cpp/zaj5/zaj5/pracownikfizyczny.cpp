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


void pracownikFizyczny::wyswietl()
{
    cout<<"+=== PRACOWNIK FIZYCZNY ===+"<<endl;
    cout<<"Dane osobowe: ";
    cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
    cout<<"Dane ogolne pracownika: ";
    cout<<"firma: "<<firma<<endl;
    cout<<"Dane szczegolowe pracownika:"<<endl;
    cout<<"Zarobki: "<<stawka_h<<"/h ";
    cout<<"Premia: "<<premia<<"%."<<endl;
}

void pracownikFizyczny::zarobki()
{
    int f;
    cout<<"podaj ilosc godzin: ";
    cin>>f;
    cout<<"Zarobki wynosza: ";
    cout<<f*stawka_h;

}
