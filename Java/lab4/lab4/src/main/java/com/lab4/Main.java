package com.lab4;

import java.util.Random;

public class Main 
{
    public static void main(String[] arg) 
    {
        //System.out.println("Hello world!");

        /*
        int rozmiar = 100;
        int kolumny = 10;

        int[] tablica = TablicaJednowymiarowa.utworzWypelnionaTablice(rozmiar);
        TablicaJednowymiarowa.wyswietlTablice(tablica, kolumny);
        */

        /*
        Random rand = new Random();
        int rozmiar = rand.nextInt(11) + 10; // Losowa wielkość z zakresu [10, 20]

        int[][] tablica = TablicaJednowymiarowa.utworzTabliceLosowa(rozmiar);
        double stosunek = TablicaJednowymiarowa.obliczStosunek(tablica);

        System.out.println("Tablica:");
        for (int i = 0; i < rozmiar; i++) 
        {
            for (int j = 0; j < rozmiar; j++) 
            {
                System.out.print(tablica[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("Stosunek sumy liczb leżących w komórkach tablicy o parzystych indeksach wierszy do sumy liczb leżących w komórkach tablicy o nieparzystych indeksach kolumn: " + stosunek);
        */

        /*
        Okrag okregi[] = Main.createOkreg();

        Main.showOkreg(okregi);

        Main.checkOkreg(okregi);
        */
    }

    public static Okrag[] createOkreg()
    {
        Okrag okregi[] = new Okrag[5];
        for (int i = 0; i < okregi.length; i++) 
        {
            okregi[i] = new Okrag();
        }
        return okregi;
    } 

    public static  void showOkreg(Okrag okregi[])
    {
        for (Okrag okrag : okregi) 
        {
            System.out.println(okrag);
        }
    } 

    public static void checkOkreg(Okrag okregi[])
    {
        Okrag okrag1 = okregi[0];
        Okrag okrag2 = okregi[1];
        System.out.println("Położenie okręgów: " + Okrag.sprawdzWzajemnePolozenie(okrag1, okrag2));
    } 

}