package com.lab5;

public abstract class Czlowiek 
{
    public
        abstract void jedz();
        abstract void pij();
        int ileLat()
        {
            return wiek;
        }
        String cechy()
        {
            return cecha;
        }

    protected
        int wiek;
        String cecha;
}


/*
 * Dodaj do klasy metody abstrakcyjne:
 jedz(),
 pij().
Dodaj do klasy metody z implementacją:
 ileLat(),
 cechy().
 */