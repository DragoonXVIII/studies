#include "Tosoba.h"
#include <iostream>
#include <string>


using namespace std;

Tosoba::Tosoba()
{
    imie = "grzegorz";
    nazwisko = "brzeczyszczykiewiczx";
    data_urodzenia.dzien = 79;
    data_urodzenia.miesiac = 18;
    data_urodzenia.rok = 2137;
}


Tosoba::Tosoba(string iimie, string nnazwisko, data ddata_urodzenia):imie(iimie),nazwisko(nnazwisko),data_urodzenia(ddata_urodzenia){};


Tosoba::~Tosoba()
{
    //dtor
}



void Tosoba::wyswietl_1()
{
    cout<<imie<<" "<<nazwisko<<" "<<data_urodzenia.dzien<<"."<<data_urodzenia.miesiac<<"."<<data_urodzenia.rok<<endl;
    return;
}


void Tosoba::wyswietl_2()
{
    cout<<imie<<" "<<nazwisko<<" "<<2023-data_urodzenia.rok<<endl;
    return;
}


void Tosoba::info_1()
{
    if(2023-data_urodzenia.rok<18)
        cout<<"dziecko"<<endl;
    else if(2023-data_urodzenia.rok<30)
        cout<<"pelnoletnia"<<endl;
    else if(2023-data_urodzenia.rok<50)
        cout<<"30tka"<<endl;
    else if(2023-data_urodzenia.rok>=50)
        cout<<"50tka"<<endl;

    return;
}


void Tosoba::info_2()
{
    if(2023-data_urodzenia.rok<18)
        cout<<"dziecko"<<endl;
    else cout<<"ukonczyl w "<<data_urodzenia.rok+18<<" roku"<<endl;
    return;
}
