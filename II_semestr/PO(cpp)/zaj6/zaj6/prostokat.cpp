#include "prostokat.h"

#include <iostream>
#include <string.h>


using namespace std;


prostokat::prostokat()
{
    nazwa = "prostokat_def";
    a = 1, b = 2;
}

prostokat::prostokat(float a,float b)
{
    nazwa = "prostokat";
    this->a = a;
    this->b = b;
}

prostokat::~prostokat()
{

}

float prostokat::pole()
{
    return a*b;
}

float prostokat::obwod()
{
    return 2*a + 2*b;
}
