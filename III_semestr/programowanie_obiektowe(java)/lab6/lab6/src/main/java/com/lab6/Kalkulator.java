package com.lab6;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Kalkulator {

    public static void petla() 
    {
        Scanner wejscie = new Scanner(System.in);

        while (true) 
        {
            try 
            {
                System.out.println("Podaj pierwszą liczbę:");
                double liczba1 = wejscie.nextDouble();

                System.out.println("Podaj drugą liczbę:");
                double liczba2 = wejscie.nextDouble();

                System.out.println("Wybierz operację:");
                System.out.println("1. Dodawanie");
                System.out.println("2. Odejmowanie");
                System.out.println("3. Mnożenie");
                System.out.println("4. Dzielenie");
                System.out.println("5. Pierwiastkowanie");
                System.out.println("6. Potęgowanie");
                System.out.println("7. Wyjście");

                int operacja = wejscie.nextInt();

                switch (operacja)
                {
                    case 1:
                        System.out.println("Wynik: " + (liczba1 + liczba2));
                        break;
                    case 2:
                        System.out.println("Wynik: " + (liczba1 - liczba2));
                        break;
                    case 3:
                        System.out.println("Wynik: " + (liczba1 * liczba2));
                        break;
                    case 4:
                        if (liczba2 != 0) {
                            System.out.println("Wynik: " + (liczba1 / liczba2));
                        } else {
                            System.out.println("Błąd: Dzielenie przez zero.");
                        }
                        break;
                    case 5:
                        System.out.println("Wynik: " + Math.sqrt(liczba1));
                        break;
                    case 6:
                        System.out.println("Wynik: " + Math.pow(liczba1, liczba2));
                        break;
                    case 7:
                        System.out.println("Do widzenia!");
                        System.exit(0);
                    default:
                        System.out.println("Nieprawidłowy wybór operacji.");
                        break;
                }
            } 
            catch (InputMismatchException e) 
            {
                System.out.println("Błąd: Wprowadź poprawne dane.");
                wejscie.nextLine();
            }
        }
    }
}