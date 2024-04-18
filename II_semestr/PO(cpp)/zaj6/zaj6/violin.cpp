#include "violin.h"


violin::violin()
{
    cout<<"Utworzone obiekt <violin> poprzez konstruktor domyslny"<<endl;
    nazwa="skrzypce";
}


violin::violin(string nazwa)
{
    this->nazwa=nazwa;
    cout<<"Utworzone obiekt <violin> poprzez konstruktor z argumentem"<<endl;
}


violin::~violin()
{
    cout<<"Usunieto obiekt <violin> poprzez destruktor domyslny"<<endl;
}


string violin::dzwiek()
{
    return "*dzwiek skrzypiec*";
}
