package com.lab2;

public class LiczbyCalkowite 
{
    public static void wypisz()
    {
        for (int i = 11; i <= 111; i++) 
        {
            if (i % 13 == 0)
            {
                System.out.print(i + " ");
            }
        }
    }
}

