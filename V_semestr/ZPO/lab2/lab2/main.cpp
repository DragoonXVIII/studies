#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;
int main()
{
    //LAB 1 1/2
    /*
    Figure* f1=new Square(4);
    Figure* f2=new Circle(2);
    f1->calculateArea();
    f1->show();
    f2->calculateArea();
    f2->show();

    Figure *f3;
    Square s1(4);
    f3=&s1;
    f3->calculateArea();
    f3->show();

    Figure* tab[3];
    tab[0]=new Square(4);
    tab[1]=new Square(2);
    tab[2]=new Circle(5);

    for(int i=0;i<3;i++)
    {
        tab[i]->calculateArea();
        delete tab[i];
    }

    delete f1;
    delete f2;
    */
    //LAB 1 2/2
    Figure* tab[2];
    tab[0]=new Square(4);
    tab[1]=new Circle(2);
    for(int i=0;i<2;i++)
    {
        tab[i]->calculateArea();
        tab[i]->calculatePerimeter();
        tab[i]->show();
        delete tab[i];
    }
    return 0;
}
