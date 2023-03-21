#ifndef TOSOBA_H
#define TOSOBA_H

#include <string>


using namespace std;



struct data
{
    int dzien;
    int miesiac;
    int rok;
};



class Tosoba
{
    public:
        string imie; //string
        string nazwisko;
        data data_urodzenia;

        Tosoba();
        Tosoba(string iimie, string nnazwisko, data data_urodzenia);
        ~Tosoba();

        void wczytaj(string iimie, string nnazwisko, data data_urodzenia);
        void wyswietl_1();
        void wyswietl_2();
        void info_1();
        void info_2();

    protected:

    private:
};

#endif // TOSOBA_H
