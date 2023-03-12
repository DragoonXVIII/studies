#include "zaj2.h"
#include <iostream>

using namespace std;

void Tpracownik::wczytaj()
{
    cout<<"Podaj imie"<<endl;
    cin>>imie;

    cout<<"Podaj nazwisko"<<endl;
    cin>>nazwisko;

    cout<<"Podaj stawke godzinowa"<<endl;
    cin>>stawka_za_godzine;

    cout<<"Podaj liczbe godzin"<<endl;
    cin>>liczba_godzin;

    cout<<"Podaj dzien"<<endl;
    cin>>Tdata_zatrudnienia.dzien;

    cout<<"Podaj miesiac"<<endl;
    cin>>Tdata_zatrudnienia.miesiac;

    cout<<"Podaj rok"<<endl;
    cin>>Tdata_zatrudnienia.rok;

    return;
}

float Tpracownik::placa()
{
    float kasa = float(liczba_godzin) * stawka_za_godzine;

    return kasa;
}

void Tpracownik::wyswietl()
{
    cout<<imie<<" ";

    cout<<nazwisko<<endl;

    cout<<stawka_za_godzine<<"/h * "<<liczba_godzin<<" =  "<<placa()<<endl;

    cout<<Tdata_zatrudnienia.dzien<<"."<<Tdata_zatrudnienia.miesiac<<"."<<Tdata_zatrudnienia.rok<<endl;

    return;
}
