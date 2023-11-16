
#include "Tpunkt.h"
#include "Tkolo.h"

#include <iostream>
#include <cmath>
#include <math.h>


using namespace std;


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


bool nalezy(Tpunkt *punkt, Tkolo *kolo)
{
    //jezeli promien jest dluzszy niz odleglosc miedzy 0,0 a punktem
    float odl = sqrt(pow(punkt->getX(),2)+pow(punkt->getY(),2));
    //cout<<"Odleglosc punktu od srodka kola: "<<odl<<"Promien kola: "<<kolo->getR()<<"\n";
    if(odl<kolo->getR())
    {
        //cout<<"Punkt w kole\n";
        return true;
    }
    else
    {
        //cout<<"Punkt nie nalezy do kola\n";
        return false;
    }
}


