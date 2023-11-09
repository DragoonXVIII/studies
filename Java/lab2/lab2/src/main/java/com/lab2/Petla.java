package com.lab2;

public class Petla
{
    public void wyswietl()
    {
        System.out.println("Użycie pętli for:");
        for (int i = 5; i <= 80; i += 15)
        {
            System.out.print(i + " ");
        }

        System.out.println("\nUżycie pętli while:");
        int j = 5;
        while (j <= 80)
        {
            System.out.print(j + " ");
            j += 15;
        }

        System.out.println("\nUżycie pętli do-while:");
        int k = 5;
        do 
        {
            System.out.print(k + " ");
            k += 15;
        } while (k <= 80);
    }
}
