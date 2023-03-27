#include "o_osoba.h"
#include "data.h"

#include <iostream>
#include <string.h>



using namespace std;



o_osoba::o_osoba()
{
    wiek = 2023 - birth_date.y;
}


o_osoba::~o_osoba()
{

}


o_osoba:: o_osoba(string name, string surname, o_data birth_date)
{
    this->name=name;
    this->surname=surname;
    this->birth_date=birth_date;
    this->motto="zdefiniowane wewnatrz konstruktora z parametrami";
    wiek = 2023 - birth_date.y;
}


void o_osoba::get()
{
    cin>>name;
    cin>>surname;
    cin>>motto;
    birth_date.load();
}


void o_osoba::show()
{
    cout<<name<<" "<<surname<<endl;
    birth_date.show();
    cout<<motto<<endl;
}


string o_osoba::get_nameandsurname()
{
    return name+surname;
}


int o_osoba::old_diff(o_osoba &osoba)
{
    return abs(osoba.wiek-wiek);
}


o_osoba o_osoba::longersurname(o_osoba &osoba)
{
    if(osoba.surname.length()>surname.length())
        return osoba;
    else
        return *this;
}
