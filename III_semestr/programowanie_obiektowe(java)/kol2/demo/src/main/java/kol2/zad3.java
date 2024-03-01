package kol2;

import java.util.List;

/*
Napisz interfejs zawierający jedną metodę abstrakcyjną przyjmującą jako parametr
łańcuch znaków. Stwórz listę (np. ArrayList) zawierającą spis przedmiotów do zaliczenia
(klasa String). Napisz metodę przyjmującą jako parametry: listę łańcuchów znaków oraz
stworzony interfejs – metoda ma wypisać wszystkie elementy listy. Użyj wyrażenia lambda
przy wywołaniu metody.
 */

interface zad3Interface
{
    public void metodaLambda(String s);
}

public class zad3
{
    public void metoda(List<String> lista, zad3Interface interfejs)
    {
        System.out.println("Metoda z wyrażeniem lambda");
        for (String string : lista) 
        {
            interfejs.metodaLambda(string);
        }
    }
    
}
