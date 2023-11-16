
#include "tdomownik.h"


#include <iostream>
#include <string>



using namespace std;



string Tdomownik::kod;


Tdomownik::Tdomownik()
{

}


Tdomownik::~Tdomownik()
{

}


void Tdomownik::show()
{
    cout<<"Domownik: "<<nazwa<<"\nJego sekret to: "<<sekret<<"\nKOD: "<<kod<<"\n";
    return;
}


void Tdomownik::load()
{
    int n;
    cout<<"Podaj nazwe domownika: ";
    cin>>nazwa;
    cout<<"Podaj sekret domownika: ";
    cin>>sekret;
    cout<<"Czy ustawic kod dla domownika?\n(1 - tak; 0 - nie)";
    cin>>n;
    if(n)
    {
        cout<<"Podaj kod: ";
        cin>>kod;
    }
    else
    {
        cout<<"Czy ustawic domyslny kod dla domownika?\n(1 - tak; 0 - nie)";
        cin>>n;
        if(n)
            kod = "1234";
    }
    //kod = "1234";
    return;
}


void Tdomownik::setkod()
{
    cout<<"Podaj kod domownika: ";
    cin>>kod;
    return;
}


void Tdomownik::getkod()
{
    cout<<"Kod domownika: "<<kod<<"\n";
    return;
}


string sasiad(Tdomownik *domownik)
{
    domownik->setkod();
    return domownik->sekret;
}
