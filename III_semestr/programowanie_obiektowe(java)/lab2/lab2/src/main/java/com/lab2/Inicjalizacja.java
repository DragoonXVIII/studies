package com.lab2;

public class Inicjalizacja 
{
    int intValue;
    char charValue;
    String stringValue;

    public void wypisz() 
    {
        Inicjalizacja obiekt = new Inicjalizacja();
        System.out.println("Wartość int: " + obiekt.intValue);
        System.out.println("Wartość char: " + obiekt.charValue);
        System.out.println("Wartość String: " + obiekt.stringValue);
    }
}
