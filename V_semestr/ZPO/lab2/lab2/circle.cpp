#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(float r1)
{
    r=r1;
    cout<<"Konstruktor w klasie Circle"<<endl;
}

Circle::~Circle()
{
    cout<<"Destruktor w klasie Circle"<<endl;
}
void Circle::calculateArea()
{
    float p=3.14*r*r;
    setArea(p);
}

void Circle::calculatePerimeter()
{
    float p=3.14*2*r;
    setPerimeter(p);
}
