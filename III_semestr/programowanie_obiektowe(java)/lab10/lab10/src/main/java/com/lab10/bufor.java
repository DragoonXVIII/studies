package com.lab10;

import java.util.LinkedList;

class bufor 
{
    private LinkedList<Integer> buffer = new LinkedList<>();
    private static final int MAX_SIZE = 5;

    public void produce() throws InterruptedException 
    {
        synchronized(this) 
        {
            while(buffer.size() == MAX_SIZE) 
            {
                wait();
            }

            int item = (int) (Math.random() * 100);
            buffer.add(item);
            System.out.println("Producent wyprodukował: " + item);

            notifyAll();
        }
    }

    public void consume() throws InterruptedException 
    {
        synchronized(this) 
        {
            while(buffer.isEmpty()) 
            {
                wait();
            }

            int item = buffer.removeFirst();
            System.out.println("Konsument skonsumował: " + item);

            notifyAll();
        }
    }
}

class Producer implements Runnable 
{
    private bufor buffer;

    public Producer(bufor buffer) 
    {
        this.buffer = buffer;
    }

    @Override
    public void run() 
    {
        try 
        {
            while(true)
            {
                buffer.produce();
                Thread.sleep((long) (Math.random() * 1000));
            }
        } 
        catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

class Consumer implements Runnable 
{
    private bufor buffer;

    public Consumer(bufor buffer) 
    {
        this.buffer = buffer;
    }

    @Override
    public void run() 
    {
        try 
        {
            while(true) 
            {
                buffer.consume();
                Thread.sleep((long) (Math.random() * 1000));
            }
        } 
        catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

