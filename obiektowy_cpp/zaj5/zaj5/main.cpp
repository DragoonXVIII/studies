#include <iostream>

#include "osoba.h"
#include "student.h"
#include "pracownik.h"
#include "pracownikfizyczny.h"
#include "pracownikumyslowy.h"



using namespace std;



int main()
{
    /*
    student student1("grzegorz","brzeczyszczykiewicz",30,
                     "POLLUB",{3,4,5});

    pracownikFizyczny pracownikf1("Stefan","Siarzewski",55,
                                  "Siara company",
                                  9999,10);

    pracownikUmyslowy pracowniku1("Tomasz","Rozek",40,
                                  "rozek.pl",
                                  20000,20);

    student1.wyswietl();
    cout<<student1.srednia()<<" "<<student1.czy_zaliczyl()<<endl;

    pracownikf1.wyswietl_pf();
    pracowniku1.wyswietl_pu();
    */
    /*
    int n;
    cout<<"Podaj ilosc ocen: ";
    cin>>n;
    float *oceny;
    oceny = new float[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Podaj "<<i+1<<"ocene: ";
        cin>>oceny[i];
    }
    */

    osoba osoba1("lol","xd",15);
    //osoba1.wczytaj();
    student student1;//("student","studencki",16,"AGH",oceny);
    student1.wczytaj();

    pracownik p1("siara","siarzewski",50,"killer");
    pracownikFizyczny pf1("jakub","polak",22,"DPD industries",22,5);
    pracownikUmyslowy pu1("max","kolonko",50,"POLSKA",500,50);

    osoba1.wyswietl();
    student1.wyswietl();
    cout<<"srednia: "<<student1.srednia()<<", z: "<<student1.czy_zaliczyl()<<endl;
    p1.wyswietl();
    pf1.wyswietl();
    pu1.wyswietl();
    return 0;
}
