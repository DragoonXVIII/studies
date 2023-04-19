#include "kolo2.h"

#include <iostream>
#include <string.h>


using namespace std;


kolo2::kolo2()
{
    nazwa = "kolo2_def";
    promien = 5;
}

kolo2::kolo2(float r,string nazwa)
{
    this->nazwa = nazwa;
    this->promien = r;
}

kolo2::~kolo2()
{

}

float kolo2::pole()
{
    return 3.14*promien*promien;
}

float kolo2::obwod()
{
    return 2*3.14*promien;
}
