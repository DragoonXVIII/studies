package com.lab7;


import java.util.ArrayList;
import java.util.Scanner;

public class pobieranie 
{
    static void pobieranie1() 
    {
        int liczba = 1;
        int suma = 0;
        int iloczyn = 1;
        int licznik = 0;
        Scanner skaner = new Scanner(System.in);
        while (liczba != 0) 
        {
            System.out.println("Podaj liczbę: ");
            liczba = skaner.nextInt();
            if (liczba != 0) 
            {
                suma += liczba;
                iloczyn *= liczba;
                licznik++;
            }
        }
        skaner.close();
        System.out.println("Wprowadzono " + licznik + " liczb.");
        System.out.println("Suma wprowadzonych liczb wynosi: " + suma);
        System.out.println("Iloczyn wprowadzonych liczb wynosi: " + iloczyn);
    }
    
    static void pobieranie2() 
    {
        int liczba = 1;
        int suma = 0;
        int iloczyn = 1;
        int licznik = 0;
        Scanner skaner = new Scanner(System.in);
        while (Math.abs(suma) <= 250 && Math.abs(iloczyn) <= 3000000) 
        {
            System.out.println("Podaj liczbę: ");
            liczba = skaner.nextInt();
                suma += liczba;
                iloczyn *= liczba;
                licznik++;
        }
        skaner.close();
        System.out.println("Wprowadzono " + licznik + " liczb.");
        System.out.println("Suma wprowadzonych liczb wynosi: " + suma);
        System.out.println("Iloczyn wprowadzonych liczb wynosi: " + iloczyn);
    }
    
    static void pobieranie3()
    {
        /*
        * Zadanie 7.4. Korekcja sumy kolekcji
        Napisz program pobierający od użytkownika liczby całkowite dopóki ich suma nie 
        będzie równa 64. Jeżeli wartość zostanie przekroczona największa liczba z wprowadzonych 
        ma zostać usunięta i pobieranie ma odbywać się dalej. Wykorzystaj sortowanie!!!!
        */
        ArrayList<Integer> lista = new ArrayList<>();
        int liczba;
        int suma = 0;
        boolean var = true;
        Scanner skaner = new Scanner(System.in);
        while(var)
        {
            System.out.println("Podaj liczbę: ");
            liczba = skaner.nextInt(); 
            lista.add(liczba);
            suma += liczba;
            if(suma > 64)
            {
                lista.sort(null);
                suma -= lista.get(0);
                lista.remove(0);
            }
            System.out.println("Suma wprowadzonych liczb wynosi: " + suma);
            if(suma == 64)
            {
                var = false;
                System.out.println("Koniec programu.");
            }
        }
        skaner.close();
    }

    /*
    Zadanie 7.5. Korekcja iloczynu kolekcji
    Napisz program pobierający od użytkownika liczby całkowite dopóki ich iloczyn nie 
    będzie równy 256. Jeżeli wartość zostanie przekroczona najmniejsza liczba z wprowadzonych 
    ma zostać usunięta i pobieranie ma odbywać się dalej. Wykorzystaj sortowanie
    */
    static void pobieranie4()
    {
        ArrayList<Integer> lista = new ArrayList<>();
        int liczba;
        int iloczyn = 1;
        boolean var = true;
        Scanner skaner = new Scanner(System.in);
        while(var)
        {
            System.out.println("Podaj liczbę: ");
            liczba = skaner.nextInt(); 
            lista.add(liczba);
            iloczyn *= liczba;
            if(iloczyn > 256)
            {
                lista.sort(null);
                iloczyn /= lista.get(0);
                lista.remove(0);
            }
            System.out.println("Iloczyn wprowadzonych liczb wynosi: " + iloczyn);
            if(iloczyn == 256)
            {
                var = false;
                System.out.println("Koniec programu.");
            }
        }
        skaner.close();
    }
}
