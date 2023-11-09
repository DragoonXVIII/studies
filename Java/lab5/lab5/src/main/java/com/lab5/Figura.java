package com.lab5;

import java.awt.Color;

public class Figura 
{
    public 

        void figura()
        {
            
        }
        void figura(int _pole, int _obwod, Color _kolor)
        {
            pole = _pole;
            obwod = _obwod;
            kolor = _kolor;
        }

        void setPole(int a)
        {
            pole = a;
        }
        void setObwod(int a)
        {
            obwod = a;
        }
        void setColor(Color a)
        {
            kolor = a;
        }

        int getPole()
        {
            return pole;
        }
        int getObwod()
        {
            return obwod;
        }
        Color getKolor()
        {
            return kolor;
        }
        
    protected 

        int pole;
        int obwod;

        void rysuj()
        {
            System.out.println("Rysowanie figury");
        }
        void usun()
        {
            System.out.println("Usuwanie figury");
        }
        void przesun()
        {
            System.out.println("Przesuwanie figury");
        }

        /*String podajParametry()
        {
            
            return;
        }*/

    private
        Color kolor;

}


/*
 * 
 * twórz nową klasę – Figura. Zdefiniuj w klasie pola: 
 protected: 
o int pole,
o int obwód,
 private:
o Color kolor (klasa importowana) .
Zdefiniuj w klasie metody chronione (protected): 
 void rysuj(),
 void usuń() ,
 void przesuń(),
 String podajParametry(),
Dodaj konstruktor parametrowy oraz metody typu get i set (ALT+Insert → getter and 
setter dla pól klasy). Utwórz nowe klasy dziedziczące po klasie Figura  Elipsa, Figura 
Wielokąt. Wróć do klasy figura i zdefiniuj tam konstruktor bezparametrowy. Usuń 
modyfikato
 */