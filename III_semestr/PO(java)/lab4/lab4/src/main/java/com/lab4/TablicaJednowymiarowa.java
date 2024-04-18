package com.lab4;

import java.util.Random;

public class TablicaJednowymiarowa
{

    public static int[] utworzWypelnionaTablice(int rozmiar) 
    {
        int tablica[] = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++) 
        {
            tablica[i] = i;
        }
        return tablica;
    }

    public static void wyswietlTablice(int tablica[], int kolumny) 
    {
        int dlugosc = tablica.length;
        int wiersze = dlugosc / kolumny;

        for (int i = 0; i < wiersze; i++) 
        {
            for (int j = 0; j < kolumny; j++)
            {
                int indeks = i * kolumny + j;
                System.out.print(String.format("%4d", tablica[indeks]));
                if (j < kolumny - 1) 
                {
                    System.out.print(", ");
                }
            }
            System.out.println();
        }
    //srednia
        for (int j = 0; j < kolumny; j++)
        {
            int suma = 0;
            for (int i = 0; i < wiersze; i++) 
            {
                int indeks = i * kolumny + j;
                suma += tablica[indeks];
            }
            double srednia = (double) suma / wiersze;
            System.out.print(String.format("%.2f ",srednia));
        }
    }

    public static int[][] utworzTabliceLosowa(int rozmiar) 
    {
        int[][] tablica = new int[rozmiar][rozmiar];
        Random rand = new Random();

        for (int i = 0; i < rozmiar; i++) 
        {
            for (int j = 0; j < rozmiar; j++) 
            {
                if (i == j) 
                {
                    //skos
                    tablica[i][j] = rand.nextBoolean() ? -1 : 1;
                } else 
                {
                    //normalnosc
                    tablica[i][j] = rand.nextInt(41) - 20;
                }
            }
        }
        return tablica;
    }

    public static double obliczStosunek(int[][] tablica) 
    {
        int sumaParzystychWiersze = 0;
        int sumaNieparzysteKolumny = 0;

        for (int i = 0; i < tablica.length; i++) 
        {
            for (int j = 0; j < tablica[i].length; j++) 
            {
                if (i % 2 == 0) 
                {
                    sumaParzystychWiersze += tablica[i][j];
                }
                if (j % 2 != 0) 
                {
                    sumaNieparzysteKolumny += tablica[i][j];
                }
            }
        }

        if (sumaNieparzysteKolumny != 0) 
        {
            return (double) sumaParzystychWiersze / sumaNieparzysteKolumny;
        } else 
        {
            return -1;  //how to avoid breaking fundamental laws of the universe
        }
    }

}