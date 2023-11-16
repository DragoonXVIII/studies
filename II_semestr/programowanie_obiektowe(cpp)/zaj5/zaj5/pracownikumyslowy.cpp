#include "pracownikumyslowy.h"

#include <iostream>



using namespace std;



pracownikUmyslowy::pracownikUmyslowy()
{
    cout<<"Utworzono obiekt klasy <pracownikUmyslowy> konstruktorem <bez parametrow>"<<endl;
}


pracownikUmyslowy::pracownikUmyslowy(string imie, string nazwisko, int wiek,
                  string firma,
                  int wynagordzenie_m, int premia)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;
    this->firma=firma;
    this->wynagordzenie_m=wynagordzenie_m;
    this->premia=premia;


    cout<<"Utworzono obiekt klasy <pracownikUmyslowy> konstruktorem <z parametrami>"<<endl;
}


pracownikUmyslowy::~pracownikUmyslowy()
{
    cout<<"Usunieto obiekt klasy <pracownikUmyslowy>"<<endl;
}


void pracownikUmyslowy::wyswietl()
{
    cout<<"+=== PRACOWNIK UMYSLOWY ===+"<<endl;
    pracownik::wyswietl();
    cout<<"Dane szczegolowe pracownika:"<<endl;
    cout<<"Zarobki: "<<wynagordzenie_m<<"/miesiac ";
    cout<<"Premia: "<<premia<<"(%); "<<float(premia*wynagordzenie_m/100)<<"(zl)"<<endl;
}
