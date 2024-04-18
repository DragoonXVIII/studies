#ifndef TDOKUMENT_H
#define TDOKUMENT_H

#include <string>


struct Data
{
    int dzien;
    int miesiac;
    int rok;
};

class  Tdokument
{
    public:
        Tdokument();
        ~Tdokument();
        virtual void wyswietl();

    protected:
        Data data;
        std::string nazwa;
};

#endif // TDOKUMENT_H
