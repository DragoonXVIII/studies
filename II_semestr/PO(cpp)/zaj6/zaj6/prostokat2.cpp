#include "prostokat2.h"

#include <iostream>
#include <string.h>


using namespace std;


prostokat2::prostokat2()
{
    nazwa = "prostokat2_def";
    a = 1, b = 2;
}

prostokat2::prostokat2(float a,float b, string nazwa)
{
    this->nazwa = nazwa;
    this->a = a;
    this->b = b;
}

prostokat2::~prostokat2()
{

}

float prostokat2::pole()
{
    return a*b;
}

float prostokat2::obwod()
{
    return 2*a + 2*b;
}
