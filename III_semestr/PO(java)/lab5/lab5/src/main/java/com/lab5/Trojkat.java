package com.lab5;

import java.awt.Color;

public class Trojkat extends Wielokat
{
    public
        void trojkat(int liczbaBokow, int liczbaWierzcholkow, int sumaKatowWewnetrznych, Color kolor)
        {
            this.liczbaBokow = liczbaBokow;
            this.liczbaWierzcholkow = liczbaWierzcholkow;
            this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
            setColor(kolor);
        }

        int getWysokosc()
        {
            return wysokosc;
        }
        int getPodstawa()
        {
            return podstawa;
        }
        void setWysokosc(int a)
        {
            wysokosc = a;
        }
        void setPodstawa(int a)
        {
            podstawa = a;
        }
        
    protected
        int wysokosc;
        int podstawa;
        
        int obliczPole()
        {
            this.pole=(int)(podstawa*wysokosc/2);
            return pole;
        }
        int obliczObwod()
        {
            this.obwod=(int)(podstawa+2*Math.sqrt((podstawa*podstawa/4)+(wysokosc*wysokosc)));
            return obwod;
        }

        @Override
        void rysuj()
        {
            System.out.println("Rysowanie trojkata");
        }
        @Override
        void przesun()
        {
            System.out.println("Przesuwanie trojkata");
        }
        @Override
        void usun()
        {
            System.out.println("Usuwanie trojkata");
        }
}
