#ifndef VIOLIN_H
#define VIOLIN_H


#include <iostream>
#include <string.h>
#include "instrument.h"


using namespace std;


class violin: public instrument
{
    public:
        violin();
        violin(string n);
        virtual ~violin();
        string dzwiek();//redefiniowanie metody wirtualnej
};

#endif // VIOLIN_H
