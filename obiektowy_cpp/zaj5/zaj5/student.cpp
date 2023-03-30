#include "student.h"

#include <iostream>


using namespace std;



student::student()
{
    cout<<"Utworzono obiekt klasy <student> konstruktorem <bez parametrow>"<<endl;
}


student::student(string imie, string nazwisko, int wiek, string uczelnia, ::oceny oceny)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;
    this->uczelnia=uczelnia;
    this->oceny=oceny;

    cout<<"Utworzono obiekt klasy <student> konstruktorem <z parametrami>"<<endl;
}


student::~student()
{
    cout<<"Usunieto obiekt klasy <student>"<<endl;
}


void student::wyswietl_s()
{
    cout<<"+=== STUDENT ===+"<<endl;
    cout<<"Dane osobowe: ";
    wyswietl_o();
    cout<<"Dane studenta: ";
    cout<<uczelnia<<" "
        <<oceny.przedmiot1<<","
        <<oceny.przedmiot2<<","
        <<oceny.przedmiot3<<","<<endl;

    return;
}



float student::srednia()
{
    return float(oceny.przedmiot1+oceny.przedmiot2+oceny.przedmiot3)/3;
}


bool student::czy_zaliczyl()
{
    if( srednia() >= 3.0)
        return true;
    else return false;
}
