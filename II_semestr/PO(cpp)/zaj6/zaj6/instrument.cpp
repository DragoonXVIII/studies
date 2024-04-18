#include "instrument.h"

#include <iostream>
#include <string.h>


using namespace std;


instrument::instrument()
{
    cout<<"Utworzone obiekt <instrument> poprzez konstruktor domyslny"<<endl;
    nazwa="instrument";
}


instrument::instrument(string nazwa)
{
    this->nazwa=nazwa;
    cout<<"Utworzone obiekt <instrument> poprzez konstruktor z argumentem"<<endl;
}


instrument::~instrument()
{
    cout<<"Usunieto obiekt <instrument> poprzez destruktor domyslny"<<endl;
}


string instrument::dzwiek()
{
    return "*domyslny*";
}


void instrument::muzyka(int n)
{
    cout<<nazwa<<" gra: ";
    for(int i=0;i<n;i++)
    {
        cout<<dzwiek()<<" ";
    }
    cout<<endl;
}
