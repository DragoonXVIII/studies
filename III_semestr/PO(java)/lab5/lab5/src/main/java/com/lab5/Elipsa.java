package com.lab5;

import java.awt.Color;

class Elipsa extends Figura 
{
    protected double a;
    protected double b;
    protected double F1x, F1y, F2x, F2y;
    protected double c;

    public Elipsa(double a, double b, double F1x, double F1y, double F2x, double F2y, Color kolor) 
    {
        this.a = a;
        this.b = b;
        this.F1x = F1x;
        this.F1y = F1y;
        this.F2x = F2x;
        this.F2y = F2y;
        obliczC();
    }

    public void obliczC() 
    {
        c = Math.sqrt(a * a - b * b);
    }
    public double getC() 
    {
        return c;
    }

    @Override
    protected void rysuj() 
    {
        System.out.println("Rysowanie elipsy");
    }
    @Override
    protected void przesun() 
    {
        System.out.println("Przesuwanie elipsy");
    }
    @Override
    protected void usun() 
    {
        System.out.println("Usuwanie elipsy");
        
    }
}
