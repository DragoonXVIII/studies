#ifndef KWADRAT2_H
#define KWADRAT2_H


#include "prostokat2.h"


class kwadrat2: public prostokat2
{
public:
    kwadrat2();
    kwadrat2(float a,string nazwa);
    ~kwadrat2();

protected:
    float a;
    float pole();
    float obwod();

};

#endif // KWADRAT2_H
