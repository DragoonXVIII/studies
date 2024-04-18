#include "afigura.h"

#include <iostream>
#include <string.h>


using namespace std;


afigura::afigura()
{
    this->nazwa="figura_def";
}


afigura::~afigura()
{

}


void afigura::wyswietl()
{
    info();
    rysuj();
    cout<<"pole: "<<pole()<<" obwod: "<<obwod()<<endl;
    return;
}


void afigura::info()
{
    cout<<nazwa<<endl;
    return;
}

void afigura::rysuj()
{
    cout<<"rysuje <"<<nazwa<<">"<<endl;
    return;
}
