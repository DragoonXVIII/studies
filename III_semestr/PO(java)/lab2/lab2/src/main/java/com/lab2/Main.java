package com.lab2;

public class Main 
{
    public static void main(String[] args) 
    {
        System.out.println("Hello world!");

        Inicjalizacja obiekt1 = new Inicjalizacja();
        obiekt1.wypisz();
        MetodaStatyczna.wypiszWartosci();

        Uczen uczen1 = new Uczen("Jan", "Kowalski", 18, 4.5);
        Uczen uczen2 = new Uczen("Anna", "Nowak", 17, 4.2);
        System.out.println(uczen1.imie + " " + uczen1.nazwisko + " " + uczen1.wiek + " " + uczen1.srednia);
        System.out.println(uczen2.imie + " " + uczen2.nazwisko + " " + uczen2.wiek + " " + uczen2.srednia);

        Owoc owoc1 = new Owoc("Jabłko", 0.2);
        Owoc owoc2 = new Owoc("Banan", 0.15);

        System.out.println("Owoc 1: Nazwa - " + owoc1.getNazwa() + ", Masa - " + owoc1.getMasa() + " kg");
        System.out.println("Owoc 2: Nazwa - " + owoc2.getNazwa() + ", Masa - " + owoc2.getMasa() + " kg");

        Petla petla1 = new Petla();
        petla1.wyswietl();

        Trojkat trojkat1 = new Trojkat();
        trojkat1.sprawdzTrojkat(3, 3, 3);
        trojkat1.sprawdzTrojkat(3, 4, 5);
        trojkat1.sprawdzTrojkat(4, 4, 5);
        trojkat1.sprawdzTrojkat(1, 2, 3);

        LiczbyCalkowite liczba1 = new LiczbyCalkowite();
        liczba1.wypisz();

        System.out.println("");
        CiagFibonacciego ciag1 = new CiagFibonacciego();
        ciag1.wyswietlFibonacci(10);

    }
}