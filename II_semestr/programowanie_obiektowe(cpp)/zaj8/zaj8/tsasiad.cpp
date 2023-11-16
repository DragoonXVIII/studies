
#include "tsasiad.h"

#include <iostream>
#include <string>



using namespace std;



Tsasiad::Tsasiad()
{

}


Tsasiad::~Tsasiad()
{

}


void Tsasiad::info(Tdomownik *domownik)
{
    cout<<"Ja sasiad <"<<nazwa<<"> znam sekrety domownika <"<<domownik->nazwa<<"> "<<domownik->sekret<<" i kod do domu <"<<domownik->kod<<">.\n";
    return;
}
