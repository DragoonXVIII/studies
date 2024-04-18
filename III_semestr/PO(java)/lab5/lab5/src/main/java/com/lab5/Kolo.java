package com.lab5;

import java.awt.Color;

public class Kolo extends Elipsa 
{

    public Kolo(double a, double b, double F1x, double F1y, double F2x, double F2y, Color kolor) 
    {
        super(a, b, F1x, F1y, F2x, F2y, kolor);
        obliczPole();
        //TODO Auto-generated constructor stub
    }

    protected void obliczPole()
    {
        this.pole = (int)((a/2)*(a/2)*3.14);
    }
    protected void obliczObwod()
    {
        this.obwod = (int)(2*3.14*(a/2));
    }

    @Override
    protected void rysuj() 
    {
        System.out.println("Rysowanie kola");
    }
    @Override
    protected void przesun() 
    {
        System.out.println("Przesuwanie kola");
    }
    @Override
    protected void usun() 
    {
        System.out.println("Usuwanie kola");
    }
}
