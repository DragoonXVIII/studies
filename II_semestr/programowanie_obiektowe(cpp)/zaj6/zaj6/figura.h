#ifndef FIGURA_H
#define FIGURA_H


#include <iostream>
#include <string.h>


using namespace std;


class figura
{
    public:
        figura();
        ~figura();
        void wyswietl();

    protected:
        string nazwa;
        void info();
        void rysuj();
        virtual float pole();
        virtual float obwod();

};

#endif // FIGURA_H
