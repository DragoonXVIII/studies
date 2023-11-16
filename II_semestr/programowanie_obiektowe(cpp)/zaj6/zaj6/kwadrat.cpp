#include "kwadrat.h"

#include <iostream>
#include <string.h>


using namespace std;


kwadrat::kwadrat()
{
    nazwa = "kwadrat_def";
    a = 2;
}


kwadrat::kwadrat(float a)
{
    nazwa = "kwadrat";
    this->a = a;
}

kwadrat::~kwadrat()
{

}

float kwadrat::pole()
{
    return a*a;
}

float kwadrat::obwod()
{
    return 4*a;
}
