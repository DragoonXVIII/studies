package kol2;

import java.util.ArrayList;
import java.util.List;

public class Main 
{
    
    public static void main(String[] args) 
    {
        //ZAD1
        /*
        System.out.println("Hello world!");
        zad1 z1 = new zad1();
        z1.podajDane();
        z1.wyswietl();
        */

        //ZAD2
        /*
        zad2 z2 = new zad2();
        z2.podajDane();
        z2.zapis();
        z2.odczyt();
        */

        //ZAD3
        
        List<String> lista = new ArrayList<String>();
        lista.add("Algorytmy Analizy Numerycznej");
        lista.add("Matematyka dla Informayków II");
        lista.add("Programowanie Obiektowe - Java");
        zad3 z3 = new zad3();
        z3.metoda(lista, (s) -> System.out.println(s));    
        
    }
}