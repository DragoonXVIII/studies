
#include "tpunkt.h"

Tpunkt::Tpunkt()
{

}


Tpunkt::~Tpunkt()
{

}


void Tpunkt::ruch(int xMove, int yMove)
{
    x += xMove;
    y += yMove;
    return;
}


int Tpunkt::getX()
{
    return x;
}


int Tpunkt::getY()
{
    return y;
}
