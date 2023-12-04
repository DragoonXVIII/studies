package com.lab6;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
    {
        //ZAD 1
        //Kalkulator.petla();
        
        //ZAD 2
        //System.out.println(pobierzLiczbe());
        
        //ZAD 3
        //System.out.println(zad3());
    }

    public static double pobierzLiczbe()
    {
        Scanner wejscie = new Scanner(System.in);
        double liczba = 0;
        boolean poprawna = false;
        while (!poprawna)
        {
            try
            {
                System.out.println("Podaj liczbę rzeczywistą:");
                liczba = wejscie.nextDouble();
                poprawna = true;
            }
            catch (InputMismatchException e)
            {
                System.out.println("Błąd: Podana wartość nie jest liczbą rzeczywistą.");
                wejscie.nextLine();
            }
        }
        double mantysa = liczba - (int)liczba; 
        double cecha = liczba - mantysa;
        System.out.println("Cecha: "+cecha);
        System.out.println("Mantysa: "+mantysa);
        return cecha / mantysa;
    }

    public static int zad3()
    {
        Scanner wejscie = new Scanner(System.in);
        int liczba = 0;
        boolean poprawna = false;
        while (!poprawna)
        {
            try
            {
                System.out.println("Podaj liczbę z zakresu <99;999>:");
                liczba = wejscie.nextInt();
                if(liczba >= 99 && liczba <= 999)
                    poprawna = true;
                else
                    System.out.println("Liczba poza zakresem!");
            }
            catch (InputMismatchException e)
            {
                System.out.println("Blad: Podana wartosc nie jest liczba calkowita.");
                wejscie.nextLine();
            }
        }
        int suma = 0;
        String l1 = String.valueOf(liczba);
        for (int i = 0; i < l1.length(); i++) 
        {
            int tmp = Character.getNumericValue(l1.charAt(i));
            suma += tmp * tmp;
        }

        return suma;
    }

}
