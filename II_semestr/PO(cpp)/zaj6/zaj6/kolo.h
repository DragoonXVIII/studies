#ifndef KOLO_H
#define KOLO_H

#include "figura.h"


class kolo: public figura
{
    public:
        kolo();
        kolo(float r);
        ~kolo();

    protected:
        float promien;

        float pole();
        float obwod();

};

#endif // KOLO_H
