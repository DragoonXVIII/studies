#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "figure.h"
class Circle: public Figure
{
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;
    virtual void calculatePerimeter() override;
    /* tylko dla czytelnosci (xD)*/
};
#endif // CIRCLE_H_INCLUDED
