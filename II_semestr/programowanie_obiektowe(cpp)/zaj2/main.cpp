#include <iostream>
#include "zaj2.h"
#include "Tstudent.h"
#include "Tdzialania.h"

using namespace std;

int main()
{
    Tdzialania dzialania_1, dzialania_2;
    Tpracownik pracownik_1,pracownik_2;
    Tstudent student_1,student_2;


    pracownik_1.wczytaj();
    pracownik_2.wczytaj();

    pracownik_1.wyswietl();
    pracownik_2.wyswietl();

    student_1.wczytaj();
    student_2.wczytaj();

    student_1.wyswietl();
    student_2.wyswietl();

    dzialania_1.podajDane();
    dzialania_2.podajDane();

    cout<<dzialania_1.suma()<<endl;
    cout<<dzialania_2.suma()<<endl;

    cout<<dzialania_1.suma()<<endl;
    cout<<dzialania_2.suma()<<endl;

    cout<<dzialania_1.mnozenie()<<endl;
    cout<<dzialania_2.mnozenie()<<endl;

    cout<<dzialania_1.dzielenie()<<endl;
    cout<<dzialania_2.dzielenie()<<endl;

    cout<<dzialania_1.potega()<<endl;
    cout<<dzialania_2.potega()<<endl;

    return 0;
}
