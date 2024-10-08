#include <iostream>
#include "developer.h"
using namespace std;

int Developer::calculateSalary(int value)
{
    return int(value + ((0.2 * value) * (salary + experience)));
}

float Developer::calculateBonus(int value) const
{
    std::cout<<value<<"+0.2*"<<value<<"*("<<salary<<"+"<<experience<<")\n";
    return value + 0.2 * value * (salary + experience);
}

Developer::~Developer()
{
    std::cout << "Developer destructor called\n";
}
