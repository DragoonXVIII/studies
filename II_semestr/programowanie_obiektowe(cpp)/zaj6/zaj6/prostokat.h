#ifndef PROSTOKAT_H
#define PROSTOKAT_H


#include "figura.h"


class prostokat: public figura
{
    public:
        prostokat();
        prostokat(float a,float b);
        ~prostokat();

    protected:
        float a,b;
        virtual float pole();
        virtual float obwod();

};

#endif // PROSTOKAT_H
