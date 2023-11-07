package com.lab5;

abstract class Dorosly extends Czlowiek
{
    public abstract void obowiazki();
    public void praca()
    {
        System.out.println("Dorosły pracuje");
    }   

    @Override
    public void jedz()
    {
        System.out.println("Dorosły je");   
    }
    @Override
    public void pij() 
    {
        System.out.println("Dorosły pije");
    }
}
