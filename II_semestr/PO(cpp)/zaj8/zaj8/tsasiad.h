
#ifndef TSASIAD_H
#define TSASIAD_H

#include "tdomownik.h"

#include <string>



using namespace std;



class Tsasiad
{
    public:
        Tsasiad();
        Tsasiad(string nazwa): nazwa(nazwa){};
        ~Tsasiad();
        void info(Tdomownik *domownik);

    protected:
        string nazwa;

};

#endif // TSASIAD_H
