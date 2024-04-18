package kol2;

import java.util.List;
import java.util.ArrayList;

/*
Utwórz obiekt zawierający kolekcję.
Pobierz liczby z klawiatury, zapisz je w kolekcji.
Utwórz metodę wyświetlającą zawartość kolekcji.
 */

public class zad1 
{
    public List<Integer> kolekcja = new ArrayList<Integer>();

    public void dodaj(int liczba)
    {
        kolekcja.add(liczba);
    }

    public void podajDane()
    {
        System.out.println("Podaj liczby, 0 kończy wprowadzanie");
        int liczba = 1;
        while(liczba != 0)
        {
            try
            {
                liczba = Integer.parseInt(System.console().readLine());
                if(liczba != 0)
                    dodaj(liczba);
            }
            catch(NumberFormatException ex)
            {
                System.err.println("Nie podano liczby");
            }
        }
    }

    public void wyswietl()
    {
        System.out.println(kolekcja);
    }
}
