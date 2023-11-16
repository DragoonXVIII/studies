
#include <iostream>


#include "tdomownik.h"
#include "tsasiad.h"
#include "tkolo.h"
#include "tpunkt.h"

using namespace std;



int main()
{
    /*Tdomownik domownik1("Mama","pracuje w CKE"),domownik2;
    domownik1.setkod();
    domownik1.show();
    domownik2.load();
    domownik1.getkod();
    domownik1.show();
    domownik2.show();*/

    /*Tdomownik d1("Mama","pracuje w CKE","1234"), d2;
    d1.show();
    d2.load();
    d2.show();
    sasiad(&d1);
    d1.show();
    d2.show();*/

    /*Tdomownik d1("Mama","sekret1","1234"),
            d2("Tata","sekret2"),
            d3("Syn","sekret3"),
            d4("Corka","sekret4");
    Tsasiad s1("Mat");
    s1.info(&d1);
    s1.info(&d2);
    s1.info(&d3);
    s1.info(&d4);*/

    Tkolo k1(5);
    Tpunkt p1(-6,-6); // sqrt( 4^2 + 3^2 ) = 5

    for(int i=0;i<12;i++)
    {
        if(nalezy(&p1,&k1))
            cout<<"Punkt o wsporzednych: ("<<p1.getX()<<","<<p1.getY()<<") NALEZY do okregu o promieniu: "<<k1.getR()<<"\n";
        else
        {
            cout<<"Punkt o wsporzednych: ("<<p1.getX()<<","<<p1.getY()<<") NIE NALEZY do okregu o promieniu: "<<k1.getR()<<"\n";
        }
        p1.ruch(1,1);
    }
    return 0;
}



