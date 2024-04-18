#include "trumpet.h"


trumpet::trumpet()
{
    cout<<"Utworzone obiekt <trumpet> poprzez konstruktor domyslny"<<endl;
    nazwa="trabka";
}


trumpet::trumpet(string nazwa)
{
    this->nazwa=nazwa;
    cout<<"Utworzone obiekt <trumpet> poprzez konstruktor z argumentem"<<endl;
}


trumpet::~trumpet()
{
    cout<<"Usunieto obiekt <trumpet> poprzez destruktor domyslny"<<endl;
}


string trumpet::dzwiek()
{
    return "*dzwiek trabki*";
}

