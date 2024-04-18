package com.lab10;

import java.util.Random;

/*
Zadanie 10.1. Losowanie liczb w wielu wątkach
Napisz klasę zad1 implementującą interfejs Runnable z metodą losującą liczby całkowite 
z zakresu <0,100>. Wywołaj metodę w kilku wątkach.
*/

class zad1 implements Runnable 
{
    private static final Object lock = new Object();

    @Override
    public void run() 
    {
        // Losowanie liczby całkowitej w zakresie <0, 100>
        int randomNumber = new Random().nextInt(101);

        // Synchronizacja, aby uniknąć współbieżnych operacji
        synchronized(lock) 
        {
            System.out.println(Thread.currentThread().getName() + " wylosowal: " + randomNumber);
        }
    }
}
