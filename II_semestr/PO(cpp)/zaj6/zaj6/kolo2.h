#ifndef KOLO2_H
#define KOLO2_H


#include "afigura.h"


class kolo2: public afigura
{
    public:
        kolo2();
        kolo2(float r, string nazwa);
        ~kolo2();

    protected:
        float promien;

        float pole();
        float obwod();

};
#endif // KOLO2_H
