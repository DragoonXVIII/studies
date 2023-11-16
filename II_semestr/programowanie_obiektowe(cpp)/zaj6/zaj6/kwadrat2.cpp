#include "kwadrat2.h"

#include <iostream>
#include <string.h>


using namespace std;


kwadrat2::kwadrat2()
{
    nazwa = "kwadrat2_def";
    a = 2;
}


kwadrat2::kwadrat2(float a,string nazwa)
{
    this->nazwa = nazwa;
    this->a = a;
}

kwadrat2::~kwadrat2()
{

}

float kwadrat2::pole()
{
    return a*a;
}

float kwadrat2::obwod()
{
    return 4*a;
}
