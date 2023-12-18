package com.lab8;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Arrays;

public class Main 
{
    public static void main(String[] args)
    {
        System.out.println("Hello world!");
        /*int a = 20, b = 50;
        metodaY(a, b, () -> {
            System.out.println(a * b);
            });
        */

        /*
        List<String> lista = List.of("MatematykaDyskretna", "AlgorytmyAnalizyNumerycznej", "ProgramowanieObiektoweWJava", "HLA", "WstepDoInformatyki");
        zad1M(lista, (s) -> {
            System.out.println(s);
        });
        */

        /*
        int tab[]={3, 2, 5, 1, 8};
        zad2M(tab, (a, b) -> {
            return Integer.compare(a, b);
        });

        for (int i : tab) 
        {
            System.out.println(i);
        }
        */


        ArrayList<String> lista = new ArrayList<>(Arrays.asList("MatematykaDyskretna", "AlgorytmyAnalizyNumerycznej", "ProgramowanieObiektoweWJaava", "HLA", "WstepDoInformatyki"));
        zad3M(lista, (a, b) -> {
            return Integer.compare(a.length(), b.length());
        });

        for(String string : lista) 
        {
            System.out.println(string);
        }

    }

    public static void metodaY(int x, int y, TestowyInterfejs ti) 
    {
        ti.abstrakcyjnaMetodaX();
    }

    public static void zad1M(List<String> lista, zad1Interface z1)
    {
        for (String string : lista) 
        {
            z1.wyrLambda(string);
        } 
    }

/*
Wykorzystując interfejs funkcyjny Comparator<T> napisz metodę sortującą tablicę 
liczb całkowitych. Metoda compare(T o1,T o2) zwraca liczbę całkowitą zgodnie z funkcją 
signum (ujemną, zero lub dodatnią) jeśli pierwszy argument jest odpowiednio (mniejszy, 
równy, większy) od drugiego. Użyj wyrażenia lambda.
*/

    public static void zad2M(int[] tab, Comparator<Integer> cmp)
    {
        for (int i = 0; i < tab.length; i++) 
        {
            for (int j = 0; j < tab.length; j++) 
            {
                if (cmp.compare(tab[i], tab[j]) < 0) 
                {
                    int temp = tab[i];
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
            }
        }
    }

/*
ZAD3
Wykorzystując interfejs funkcyjny Comparator<T> napisz metodę sortującą listę 
łańcuchów znaków w zależności od długości. Metoda compare(T o1,T o2) zwraca liczbę 
całkowitą zgodnie z funkcją signum (ujemną, zero lub dodatnią) jeśli pierwszy argument jest 
odpowiednio (mniejszy, równy, większy) od drugiego. Użyj wyrażenia lambda
*/
    public static void zad3M(ArrayList<String> lista, Comparator<String> cmp)
    {
        for (int i = 0; i < lista.size(); i++) 
        {
            for (int j = 0; j < lista.size(); j++) 
            {
                if (cmp.compare(lista.get(i), lista.get(j)) < 0) 
                {
                    String temp = lista.get(i);
                    lista.set(i, lista.get(j));
                    lista.set(j, temp);
                }
            }
        }
    }

}