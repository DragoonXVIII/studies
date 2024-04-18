#include <iostream>
#include <string>
#include "Tosoba.h"



using namespace std;



int main()
{
    Tosoba osoba_1,osoba_2("lacper","kutomski",{68,15,2115});

    osoba_1.wyswietl_1();
    osoba_2.wyswietl_2();

    osoba_1.info_1();
    osoba_2.info_2();

    Tosoba *a = new Tosoba;
    a->wyswietl_1();
    a->info_2();

    delete a;

    //cout<<osoba_1.imie<<osoba_1.nazwisko<<osoba_1.data_urodzenia.dzien<<osoba_1.data_urodzenia.miesiac<<osoba_1.data_urodzenia.rok<<endl;
    //cout<<osoba_2.imie<<osoba_2.nazwisko<<osoba_2.data_urodzenia.dzien<<osoba_2.data_urodzenia.miesiac<<osoba_2.data_urodzenia.rok<<endl;

    return 0;
}
