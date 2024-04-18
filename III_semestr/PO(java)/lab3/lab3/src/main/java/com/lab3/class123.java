package com.lab3;

import java.util.Scanner;

public class class123 
{

    public static void check(String tekst, char znak) 
    {
        int count = 0; 
    
        for(int i = 0; i < tekst.length(); i++) 
        {
            if(znak == tekst.charAt(i)) 
            {
                count++;
            }
        }

        System.out.println("Znak '" + znak + "' występuje " + count + " razy w ciągu '" + tekst + "'.");
    }

    public static int sumaASCII(String tekst) 
    {
        int suma = 0;
        for(int i = 0; i < tekst.length(); i++) 
        {
            char znak = tekst.charAt(i);
            if(znak >= 'a' && znak <= 'z' || Character.isDigit(znak)) 
            {
                suma += (int) znak;
            }
        }
        return suma;  
    }

    public static void IntToChar() 
    {
        System.out.println("Podaj liczbę całkowitą z zakresu <33,126>: ");
        
        Scanner scanner = new Scanner(System.in);
        int liczba = scanner.nextInt();
        scanner.close();

        if (liczba < 33 || liczba > 126) 
        {
            System.out.println("Liczba nie mieści się w zakresie.");
        }
        else
        {
            System.out.print((char)liczba);
        }
    }

}
