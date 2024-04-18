#ifndef PROSTOKAT2_H
#define PROSTOKAT2_H


#include "afigura.h"


class prostokat2: public afigura
{
    public:
        prostokat2();
        prostokat2(float a,float b, string nazwa);
        ~prostokat2();

    protected:
        float a,b;
        virtual float pole();
        virtual float obwod();

};


#endif // PROSTOKAT2_H
