#ifndef O_OSOBA_H
#define O_OSOBA_H

#include "data.h"

#include <iostream>
#include <string.h>


using namespace std;



class o_osoba
{
    public:

        string name;
        string surname;
        string motto;
        o_data birth_date;
        int wiek;

        o_osoba();
        o_osoba(string imie, string nazwisko, o_data birth_date);
        ~o_osoba();

        void get();
        void show();
        string get_nameandsurname();
        int old_diff(o_osoba &osoba);
        o_osoba longersurname(o_osoba &osoba);

    private:

    protected:

};
#endif // O_OSOBA_H
