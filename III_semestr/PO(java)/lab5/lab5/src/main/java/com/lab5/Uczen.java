package com.lab5;

public class Uczen extends Dziecko implements Podstawowy, Szkola
{
    @Override
    public void zabawa()
    {
        System.out.println("Uczeń się bawi");
    }
    public void nauka()
    {
        System.out.println("Uczeń się uczy");
    }
    @Override
    public void obowiazki() 
    {
        System.out.println("Uczeń ma obowiązki");
    }
    @Override
    public void odrobLekcje() 
    {
        System.out.println("Uczeń odrabia lekcje");
    }
    @Override
    public void uczSie() 
    {
        System.out.println("Uczeń się uczy");
    }
    @Override
    public void odpoczywaj() 
    {
        System.out.println("Uczeń odpoczywa");
    }
    @Override
    public void spij() 
    {
        System.out.println("Uczeń śpi");
    }
    @Override
    public void wstan() 
    {
        System.out.println("Uczeń wstaje");
    }
}
