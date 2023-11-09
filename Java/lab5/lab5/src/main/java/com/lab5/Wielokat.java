package com.lab5;

public class Wielokat extends Figura
{
    public 
        void setLiczbaWierzcholkow(int a)
        {
            liczbaWierzcholkow = a;
        }
        void setLiczbaBokow(int a)
        {
            liczbaBokow = a;
        }
        void setSumaKatowWewnetrznych(int a)
        {
            sumaKatowWewnetrznych = a;
        }
        int getLiczbaWierzcholkow()
        {
            return liczbaWierzcholkow;
        }
        int getLiczbBokow()
        {
            return liczbaBokow;
        }
        int getSumaKatowWewnetrznych()
        {
            return sumaKatowWewnetrznych;
        }

        public int obliczSumaKątówWewnętrznych()
        {
            return (liczbaBokow - 2) * 180;
        }

    protected
        int liczbaWierzcholkow;
        int liczbaBokow;
        int sumaKatowWewnetrznych;

        @Override
        void rysuj()
        {
            System.out.println("Rysowanie wielokata");
        }
        @Override
        void przesun()
        {
            System.out.println("Przesuwanie wielokata");
        }
        @Override
        void usun()
        {
            System.out.println("Usuwanie wielokata");
        }
}
