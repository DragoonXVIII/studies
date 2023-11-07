package com.lab5;

public class Student extends Dorosly implements Podstawowy, Studia, Praca
{
    @Override
    public void obowiazki()
    {
        System.out.println("Student ma obowiązki");
    }
    public void impreza()
    {
        System.out.println("Student się bawi");
    }
    @Override
    public void pracuj() 
    {    
        System.out.println("Student pracuje");
    }
    @Override
    public void placPodatki() 
    {
        System.out.println("Student płaci podatki");
    }
    @Override
    public void odpoczywaj() 
    {
        System.out.println("Student odpoczywa");
    }
    @Override
    public void trenuj() 
    {
        System.out.println("Student trenuje");
    }
    @Override
    public void studiuj() 
    {
        System.out.println("Student studiuje"); 
    }
    @Override
    public void nieIdzNaZajecia() 
    {
        System.out.println("Student nie idzie na zajęcia");
    }
    @Override
    public void bawSie()
    {
        System.out.println("Student się bawi");
    }
    @Override
    public void graj() 
    {
        System.out.println("Student gra");
    }
    @Override
    public void spij() 
    {
        System.out.println("Student śpi");
    }
    @Override
    public void wstan() 
    {
        System.out.println("Student wstaje");
    }    
}
