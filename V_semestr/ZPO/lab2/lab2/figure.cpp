#include <iostream>
#include "Figure.h"
using namespace std;

Figure::Figure()
{
    cout<<"Konstruktor klasy bazowej Figure"<<endl;
}
Figure:: ~Figure()
{
    cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;
}
float Figure:: getArea()
{
    return area;
}
float Figure::getPerimeter()
{
    return perimeter;
}
void Figure::setArea(float area1)
{
    area=area1;
}
void Figure::setPerimeter(float perimeter1)
{
    perimeter=perimeter1;
}
void Figure::show()
{
    cout<<"Pole: "<<area<<"Obwod: "<<perimeter<<endl;
}
