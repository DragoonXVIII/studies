#include <iostream>

#include "instrument.h"
#include "trumpet.h"
#include "violin.h"
#include "figura.h"
#include "kolo.h"
#include "prostokat.h"
#include "kwadrat.h"


using namespace std;


int main()
{
    /*
    instrument i1, i2("instrumencik");
    trumpet t1,t2("trabeczka");
    violin v1,v2("skrzypeczki");

    i1.muzyka(2);
    i2.muzyka(3);

    t1.muzyka(4);
    t2.muzyka(5);

    v1.muzyka(6);
    v2.muzyka(7);
    */

    figura f1;
    kolo k1,k2(10);
    prostokat p1,p2(3,4);
    kwadrat s1,s2(4);

    f1.wyswietl();
    cout<<endl;
    k1.wyswietl();
    cout<<endl;
    k2.wyswietl();
    cout<<endl;
    p1.wyswietl();
    cout<<endl;
    p2.wyswietl();
    cout<<endl;
    s1.wyswietl();
    cout<<endl;
    s2.wyswietl();
    cout<<endl;

    return 0;
}
