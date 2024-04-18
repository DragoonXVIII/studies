package com.lab5;

import java.awt.Color;

public class Prostokat extends Wielokat
{
    public
        void prostokat(int liczbaWierzcholkow, int liczbaBokow, int sumaKatowWewnetrznych, int a, int b, Color kolor)
        {
            this.liczbaWierzcholkow = liczbaWierzcholkow;
            this.liczbaBokow = liczbaBokow;
            this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
            this.a = a;
            this.b = b;
            setColor(kolor);
        }
    
        int a;
        int b;
        
        void setA(int a)
        {
            this.a = a;
        }
        void setB(int b)
        {
            this.b = b;
        }
        int getA()
        {
            return a;
        }
        int getB()
        {
            return b;
        }

        int obliczPole()
        {
            return a*b;
        }

        int obliczObwod()
        {
            return 2*a+2*b;
        }
        
    protected

        @Override
        void rysuj()
        {
            System.out.println("Rysowanie prostokata");
        }
        @Override
        void przesun()
        {
            System.out.println("Przesuwanie prostokata");
        }
        @Override
        void usun()
        {
            System.out.println("Usuwanie prostokata");
        }


}
