#include "tosobas.h"

#include <iostream>
#include <string.h>



using namespace std;



int TosobaS::liczbaObiektow = 0;



TosobaS::TosobaS()
{
    liczbaObiektow++;
    cout<<liczbaObiektow<<endl;
    cout<<"utworzono obeikt TosobaS"<<endl;
}


TosobaS::TosobaS(char *nazwisko, char *imie, int wiek)
{
    strcpy(this->nazwisko, nazwisko);
    strcpy(this->imie, imie);
    this->wiek = wiek;
    cout<<"utworzono obeikt TosobaS"<<endl;
    liczbaObiektow++;
    cout<<liczbaObiektow<<endl;
}


TosobaS::~TosobaS()
{
    cout<<"zniszczono obeikt TosobaS"<<endl;
}


void TosobaS::podajDane()
{
    cin>>imie;
    cin>>nazwisko;
    cin>>wiek;
}


void TosobaS::wyswietl()
{
    cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
}


int TosobaS::ile()
{
    return liczbaObiektow;
}
