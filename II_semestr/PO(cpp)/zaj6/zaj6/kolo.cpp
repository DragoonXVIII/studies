#include "kolo.h"

#include <iostream>
#include <string.h>


using namespace std;


kolo::kolo()
{
    nazwa = "kolo_def";
    promien = 5;
}

kolo::kolo(float r)
{
    nazwa = "kolo";
    this->promien = r;
}

kolo::~kolo()
{

}

float kolo::pole()
{
    return 3.14*promien*promien;
}

float kolo::obwod()
{
    return 2*3.14*promien;
}
