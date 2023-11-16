#ifndef TFAKTURA_H
#define TFAKTURA_H

#include "tdokument.h"



class Tfaktura : protected Tdokument
{
    public:
        Tfaktura();
        Tfaktura(Data data, std::string nazwa, std::string sprzedawca, std::string kupujacy, double long cena);
        ~Tfaktura();
        void wyswietl();

    protected:
        std::string sprzedawca;
        std::string kupujacy;
        double long cena;
};

#endif // TFAKTURA_H
