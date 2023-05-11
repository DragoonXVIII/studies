
#ifndef TKOLO_H
#define TKOLO_H

#include "tpunkt.h"


class Tkolo
{
    public:
        Tkolo();
        ~Tkolo();
        friend bool nalezy(Tpunkt &, Tkolo &);
        int getR();
    private:
        int r;
};

#endif // TKOLO_H
