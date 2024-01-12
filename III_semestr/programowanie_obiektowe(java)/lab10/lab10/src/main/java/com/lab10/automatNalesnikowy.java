package com.lab10;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

class automatNalesnikowy 
{
    private final BlockingQueue<String> pancakeQueue = new LinkedBlockingQueue<>();

    public void fryPancake(String pancake) throws InterruptedException 
    {
        System.out.println("Smażenie naleśnika: " + pancake);
        Thread.sleep(5000);
    }

    public void spreadJam(String pancake) throws InterruptedException 
    {
        System.out.println("Smarowanie dżemem: " + pancake);
        Thread.sleep(2000);
    }

    public void rollPancake(String pancake) throws InterruptedException 
    {
        System.out.println("Zwijanie w rulon: " + pancake);
        Thread.sleep(3000);
    }

    public BlockingQueue<String> getPancakeQueue() 
    {
        return pancakeQueue;
    }
}
