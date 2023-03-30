#include "student.h"

#include <iostream>


using namespace std;



student::student()
{
    cout<<"Utworzono obiekt klasy <student> konstruktorem <bez parametrow>"<<endl;
}


student::student(string imie, string nazwisko, int wiek, string uczelnia, float *oceny)
{
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->wiek=wiek;
    this->uczelnia=uczelnia;
    this->oceny=oceny;
    this->n=sizeof(oceny)/sizeof(oceny[0]);
    cout<<"Utworzono obiekt klasy <student> konstruktorem <z parametrami>"<<endl;
}


student::~student()
{
    delete []oceny;
    cout<<"Usunieto obiekt klasy <student>"<<endl;
}


void student::wczytaj()
{

    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj wiek: ";
    cin>>wiek;
    cout<<"Podaj uczelnie: ";
    cin>>uczelnia;
    cout<<"Podaj liczbe ocen: ";
    cin>>n;
    oceny = new float[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Podaj "<<i+1<<"ocene: ";
        cin>>oceny[i];
    }

    return;
}

void student::wyswietl()
{
    cout<<"+=== STUDENT ===+"<<endl;
    cout<<"Dane osobowe: ";
    cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
    cout<<"Dane studenta: ";
    cout<<uczelnia<<" ";
    for(int i=0;i<n;i++)
    {
        cout<<oceny[i]<<";";
    }
    cout<<endl;

    return;
}



float student::srednia()
{
    float a=0;
    for(int i=0;i<n;i++)
    {
        a+=oceny[i];
    }
    return a/n;
}


bool student::czy_zaliczyl()
{
    for(int i=0;i<n;i++)
    {
        if(oceny[i]<3)
            return false;
    }
    if( srednia() >= 3.0)
        return true;
    else return false;
}
