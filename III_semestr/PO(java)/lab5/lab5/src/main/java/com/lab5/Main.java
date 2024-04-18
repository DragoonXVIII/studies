package com.lab5;

public class Main 
{
    public static void main(String[] args) 
    {
        /*Kolo kolo1 = new Kolo(10, 10, 5, 5, 5, 5, null);
        kolo1.rysuj();
        System.out.println(kolo1.getPole());
        Wielokat wiel = new Wielokat();
        wiel.setPole(5);
        //System.out.println("Hello world!");
        */
        Uczen u1 = new Uczen();
        u1.obowiazki();
        u1.odrobLekcje();
        u1.uczSie();
        u1.odpoczywaj();
        u1.spij();
        u1.wstan();
        u1.jedz();
        u1.pij();
        u1.zabawa();
        u1.nauka();
        Student s1 = new Student();
        s1.obowiazki();
        s1.odpoczywaj();
        s1.spij();
        s1.wstan();
        s1.jedz();
        s1.pij();
        s1.praca();
        s1.studiuj();
        Emeryt e1 = new Emeryt();
        e1.obowiazki();
        e1.odpoczywaj();
        e1.jedz();
        e1.pij();
        e1.praca();
        e1.spaceruj();
    }
}