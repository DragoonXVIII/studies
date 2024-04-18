#ifndef TRUMPET_H
#define TRUMPET_H


#include "instrument.h"

#include <iostream>
#include <string.h>


using namespace std;


class trumpet: public instrument
{
    public:
        trumpet();
        trumpet(string nazwa);
        virtual ~trumpet();
        string dzwiek();//redefiniowanie metody wirtualnej
};


#endif // TRUMPET_H
