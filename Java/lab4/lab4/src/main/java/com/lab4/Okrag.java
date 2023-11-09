package com.lab4;

import java.util.Random;

class Okrag 
{
    private double x;
    private double y;
    private double promien;

    public Okrag() 
    {
        Random rand = new Random();
        x = rand.nextDouble() * 90 + 5; // Losowa liczba z zakresu <5, 95>
        y = rand.nextDouble() * 90 + 5; // Losowa liczba z zakresu <5, 95>
        promien = rand.nextDouble() * 4 + 1; // Losowa liczba z zakresu <1, 5>
    }

    public static String sprawdzWzajemnePolozenie(Okrag okrag1, Okrag okrag2) 
    {
        double odlegloscMiedzySrodkami = Math.sqrt(Math.pow(okrag1.x - okrag2.x, 2) + Math.pow(okrag1.y - okrag2.y, 2));
        double sumaPromieni = okrag1.promien + okrag2.promien;

        if (odlegloscMiedzySrodkami == sumaPromieni) 
        {
            return "Okręgi są styczne.";
        } 
        else if (odlegloscMiedzySrodkami < sumaPromieni) 
        {
            return "Okręgi przecinają się.";
        } 
        else if (odlegloscMiedzySrodkami > sumaPromieni)
        {
            return "Okręgi są rozłączne.";
        } 
        else if (odlegloscMiedzySrodkami == 0 && okrag1.promien == okrag2.promien) 
        {
            return "Okręgi pokrywają się.";
        } 
        else 
        {
            return "Nierozpoznane położenie okręgów.";
        }
    }

    @Override
    public String toString() 
    {
        return "Współrzędne (x, y): (" + x + ", " + y + "), Promień: " + promien;
    }
}