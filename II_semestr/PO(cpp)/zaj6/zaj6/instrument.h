#ifndef INSTRUMENT_H
#define INSTRUMENT_H


#include <iostream>
#include <string.h>


using namespace std;


class instrument
{
    public:
        instrument();
        instrument(string nazwa);
        virtual ~instrument();
        virtual string dzwiek();
        void muzyka(int n);

    protected:
        string nazwa;
};

#endif // INSTRUMENT_H
