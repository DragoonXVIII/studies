package com.lab2;

public class CiagFibonacciego 
{
    public static void wyswietlFibonacci(int n)
    {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++)
        {
            System.out.print(a + " ");
            int temp = a + b;
            a = b;
            b = temp;
        }
    }
}

