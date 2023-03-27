#include "data.h"

#include <iostream>
#include <string.h>



using namespace std;



o_data::o_data()
{

}


o_data::~o_data()
{

}


void o_data::load()
{
    cout<<"Podaj dzien urodzenia: ";
    cin>>d;
    cout<<endl<<"Podaj miesiac urodzenia: ";
    cin>>m;
    cout<<endl<<"Podaj rok urodzenia: ";
    cin>>y;
    cout<<endl;
    return;
}


void o_data::show()
{
    if(d<10)
        cout<<"0";
    cout<<d<<".";
    if(m<10)
        cout<<"0";
    cout<<m<<".";
    cout<<y<<endl;

    return;
}


int o_data::getY()
{
    return y;
}
