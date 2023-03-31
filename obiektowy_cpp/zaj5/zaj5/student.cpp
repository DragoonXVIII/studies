#include "student.h"

#include <iostream>
#include <vector>

using namespace std;



student::student()
{
    cout<<"Utworzono obiekt klasy <student> konstruktorem <bez parametrow>"<<endl;
}


student::student(string imie, string nazwisko, int wiek, string uczelnia, vector <float> oceny)
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


void student::wczytaj()
{
    int n;
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
    int x;
    for(int i=0;i<n;i++)
    {
        cout<<"Podaj "<<i+1<<" ocene: ";
        cin>>x;
        oceny.push_back(x);
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
    for(int i=0;i<oceny.size();i++)
    {
        cout<<oceny[i]<<";";
    }
    cout<<endl;

    return;
}



float student::srednia()
{
    float a=0;
    for(int i=0;i<oceny.size();i++)
    {
        a+=oceny[i];
    }
    return a/oceny.size();
}


bool student::czy_zaliczyl()
{
    for(int i=0;i<oceny.size();i++)
    {
        if(oceny[i]<3)
            return false;
    }
    if( srednia() >= 3.0)
        return true;
    else return false;
}
