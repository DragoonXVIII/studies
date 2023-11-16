#include <iostream>
#include <fstream>

#include "data.h"
#include "o_osoba.h"
#include "tosobas.h"



using namespace std;



int main()
{
    /*
    o_osoba osoba_1("xd","loll",o_data(1,2,2020)),
            osoba_2("XD","LOL",{3,2,2010});

    osoba_1.show();
    osoba_2.show();

    cout<<"name&surname"<<osoba_1.get_nameandsurname()<<endl;
    cout<<"olddiff"<<osoba_1.old_diff(osoba_2)<<endl;

    o_osoba osoba_3 = osoba_1.longersurname(osoba_2);
    osoba_3.show();

    cout<<osoba_1.old_diff(osoba_2)<<endl;
    */

    /*
    TosobaS osoba1("lol","XD",556);

    TosobaS *osoba2;
    osoba2 = new TosobaS;
    TosobaS osoba3 = osoba1;

    osoba1.wyswietl();

    delete osoba2;

    osoba3.wyswietl();
    */

    int n = 5;

    o_osoba *osoby[n];
    ofstream plik("notatnik.txt");
    string osoba;

    for(int i=0;i<n;i++)
    {
        //osoby[i] = new o_osoba("xD","xd",{4,5,6});
        osoby[i] = new o_osoba();
        osoby[i]->get();
        //osoba = osoby[i]->get_nameandsurname() +";"+ to_string(osoby[i]->birth_date.d) +";"+ to_string(osoby[i]->birth_date.m) +";"+ to_string(osoby[i]->birth_date.y) + "\n";
        //cout<<osoba<<endl;
        plik<<osoba;//<<endl;
        osoba = "0";
    }

    for(int i=0;i<n;i++)
    {
        osoby[i]->birth_date.show();
        delete osoby[i];
    }

    plik.close();
    return 0;
}

