package com.lab5;

import java.awt.Color;

public class Kwadrat extends Prostokat
{
    public

        void kwadrat(int a, int liczbaBokow, int liczbaWierzcholkow, int sumaKatowWewnetrznych, Color kolor)
        {
            this.a = a;
            this.liczbaBokow = liczbaBokow;
            this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
            setColor(kolor);
        }

        int obliczObwod()
        {
            this.obwod = a * liczbaBokow;
            return obwod;
        }

        int obliczPole()
        {
            this.pole = a * a;
            return pole;
        }
        

        @Override
        int getA()
        {
            return a;
        }

        @Override
        void setA(int a)
        {
            this.a = a;
        }
}
