#include "Tstudent.h"
#include <iostream>

using namespace std;

Tstudent::Tstudent()
{
    //ctor
}

Tstudent::~Tstudent()
{
    //dtor
}

void Tstudent::wczytaj()
{
    cin>>imie;
    cin>>nazwisko;

    for(int i=0;i<3;i++)
        cin>>oceny[i];

    return;
}

void Tstudent::wyswietl()
{
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<srednia()<<endl;
    return;
}

float Tstudent::srednia()
{
    float srednia_ocen = 0.0;
    for(int i=0;i<3;i++)
        srednia_ocen+=oceny[i];

    return srednia_ocen/3.0;
}
