#include <iostream>

#include "osoba.h"
#include "student.h"
#include "pracownik.h"
#include "pracownikfizyczny.h"
#include "pracownikumyslowy.h"



using namespace std;



int main()
{
    student student1("grzegorz","brzeczyszczykiewicz",30,
                     "POLLUB",{3,4,5});

    pracownikFizyczny pracownikf1("Stefan","Siarzewski",55,
                                  "Siara company",
                                  9999,10);

    pracownikUmyslowy pracowniku1("Tomasz","Rozek",40,
                                  "rozek.pl",
                                  20000,20);

    student1.wyswietl_s();
    cout<<student1.srednia()<<" "<<student1.czy_zaliczyl()<<endl;

    pracownikf1.wyswietl_pf();
    pracowniku1.wyswietl_pu();
    return 0;
}
