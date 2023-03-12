#ifndef ZAJ2_H
#define ZAJ2_H

int suma(int a, int b);

struct data_zatrudnienia
{
    int dzien;
    int miesiac;
    int rok;
};

class Tpracownik
{
    public:
        char imie[10];
        char nazwisko[10];
        float stawka_za_godzine;
        int liczba_godzin;
        data_zatrudnienia Tdata_zatrudnienia;

    public:
        void wczytaj();
        float placa();
        void wyswietl();
};

#endif
