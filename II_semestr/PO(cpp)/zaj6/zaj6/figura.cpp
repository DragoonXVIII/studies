#include "figura.h"

#include <iostream>
#include <string.h>


using namespace std;


figura::figura()
{
    this->nazwa="figura_def";
}


figura::~figura()
{

}


void figura::wyswietl()
{
    info();
    rysuj();
    cout<<"pole: "<<pole()<<" obwod: "<<obwod()<<endl;
    return;
}


void figura::info()
{
    cout<<nazwa<<endl;
    return;
}


void figura::rysuj()
{
    cout<<"rysuje <"<<nazwa<<">"<<endl;
    return;
}


float figura::pole()
{
    return 1234567;
}


float figura::obwod()
{
    return 7654321;
}
