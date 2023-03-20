#include "Tdzialania.h"
#include <iostream>
#include <cmath>

void Tdzialania::podajDane()
{
    std::cout<<"Podaj dwie liczby calkowite ";
    std::cin>>a>>b;
}

int Tdzialania::suma()
{
    return a+b;
}

int Tdzialania::roznica()
{
    return a-b;
}

long long Tdzialania::mnozenie()
{
    return a*b;
}

float Tdzialania::dzielenie()
{
    return float(a)/float(b);
}

long long Tdzialania::potega()
{
    return std::pow(a,b);
}
