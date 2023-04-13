#ifndef KWADRAT_H
#define KWADRAT_H


#include "prostokat.h"


class kwadrat: public prostokat
{
public:
    kwadrat();
    kwadrat(float a);
    ~kwadrat();

protected:
    float a;
    float pole();
    float obwod();

};

#endif // KWADRAT_H
