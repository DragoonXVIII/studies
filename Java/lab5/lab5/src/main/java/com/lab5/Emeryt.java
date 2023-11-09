package com.lab5;

public class Emeryt extends Dorosly implements Praca, Emerytura
{
    @Override
    public void obowiazki()
    {
        System.out.println("Emeryt ma obowiązki");
    }
    public void odpoczynek()
    {
        System.out.println("Emeryt odpoczywa");
    }
    @Override
    public void pracuj()
    {
        System.out.println("Emeryt pracuje");
    }
    @Override
    public void placPodatki()
    {
        System.out.println("Emeryt płaci podatki");
    }
    @Override
    public void odpoczywaj() 
    {
        System.out.println("Emeryt odpoczywa");
    }
    @Override
    public void trenuj() 
    {
        System.out.println("Emeryt trenuje");
    }
    @Override
    public void odbierzEmeryture() {
        System.out.println("Emeryt odbiera emeryturę");    
    }
    @Override
    public void idzDoLekarza() {
        System.out.println("Emeryt idzie do lekarza");  
    }
    @Override
    public void czytajKsiazke() {
        System.out.println("Emeryt czyta książkę");
    }
    @Override
    public void spaceruj() {
        System.out.println("Emeryt spaceruje");
    }
    
}
