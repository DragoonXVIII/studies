package com.lab10;

public class Main 
{
    public static void main(String[] args) 
    {
        //zad1
        /*
        int numberOfThreads = 5;

        Thread[] threads = new Thread[numberOfThreads];
        for (int i = 0; i < numberOfThreads; i++)
        {
            threads[i] = new Thread(new zad1(), "Wątek " + (i + 1));
            threads[i].start();
        }

        try 
        {
            for (Thread thread : threads) 
            {
                thread.join();
            }
        } 
        catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
        */

        //zad2
        bufor buffer = new bufor();

        // Utworzenie wątku producenta i konsumenta
        Thread producerThread = new Thread(new Producer(buffer));
        Thread consumerThread = new Thread(new Consumer(buffer));

        // Uruchomienie wątków
        producerThread.start();
        consumerThread.start();
    }
}
