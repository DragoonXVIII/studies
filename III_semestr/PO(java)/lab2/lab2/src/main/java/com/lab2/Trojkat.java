package com.lab2;

public class Trojkat 
{
    public void sprawdzTrojkat(int a, int b, int c)
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && b == c) 
            {
                System.out.println("Trójkąt równoboczny");
            } 
            else if (a == b || b == c || a == c) 
            {
                System.out.println("Trójkąt równoramienny");
            }
            else 
            {
                System.out.println("Trójkąt różnoboczny");
            }
        } 
        else
        {
            System.out.println("Nie można zbudować trójkąta z podanych boków.");
        }
    }
}