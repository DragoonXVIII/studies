#ifndef TSTUDENT_H
#define TSTUDENT_H


class Tstudent
{
    public:
        Tstudent();
        virtual ~Tstudent();

        char imie[10];
        char nazwisko[10];
        float oceny[3];

    public:
        void wczytaj();
        void wyswietl();
        float srednia();

};

#endif // TSTUDENT_H
