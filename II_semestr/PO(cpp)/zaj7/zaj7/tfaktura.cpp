#include "tfaktura.h"

#include <iostream>



Tfaktura::Tfaktura()
{

}


Tfaktura::~Tfaktura()
{

}


Tfaktura::Tfaktura(Data data, std::string nazwa, std::string sprzedawca, std::string kupujacy, double long cena)
{
    this->data = data;
    this->nazwa = nazwa;
    this->sprzedawca = sprzedawca;
    this->kupujacy = kupujacy;
    this->cena = cena;
}

void Tfaktura::wyswietl()
{
    std::cout<<"+===FAKTURA===+\n";
    std::cout<<"Data faktury:"<<data.dzien<<"."<<data.miesiac<<"."<<data.rok<<"\n";
    std::cout<<"o nazwie: "<<nazwa<<"\n";
    std::cout<<"sprzedawcy: "<<sprzedawca;
    std::cout<<", nabywca: "<<kupujacy<<"\n";
    std::cout<<"koszt: "<<cena<<"\n";
    return;
}
