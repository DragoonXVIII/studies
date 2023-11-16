#ifndef AFIGURA_H
#define AFIGURA_H


#include <iostream>
#include <string.h>


using namespace std;


class afigura
{
    public:
        afigura();
        virtual ~afigura();
        void wyswietl();

    protected:
        string nazwa;
        void info();
        void rysuj();
        virtual float pole() = 0;
        virtual float obwod() = 0;

};

#endif // AFIGURA_H
