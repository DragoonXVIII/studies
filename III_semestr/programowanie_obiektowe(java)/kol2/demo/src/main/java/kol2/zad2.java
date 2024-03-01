package kol2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/*
Utwórz obiekt zawierający metody zapisu i odczytu danych z pliku.
Pobierz liczby z klawiatury, zapisz je w pliku używając utworzonego obiektu.
Wyświetl zawartość pliku.
 */

public class zad2 
{   
    public List<Integer> liczby = new ArrayList<Integer>();
    String nazwaPliku;

    public void dodaj(int liczba)
    {
        liczby.add(liczba);
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

    public void zapis()
    {
        System.out.println("Zapisywanie do pliku");
        System.out.println("Podaj nazwę pliku");
        nazwaPliku = System.console().readLine();
        File plik = new File(nazwaPliku+".txt");
        try 
        {
            FileWriter fileWriter = new FileWriter(plik, false);
            fileWriter.append(liczby.toString() + "\n");
            fileWriter.close();
        } 
        catch(IOException ex)
        {
            System.err.println(ex.getCause());
        }
    }

    public void odczyt()
    {
        System.out.println("Odczytywanie z pliku");
        File plik = new File(nazwaPliku+".txt");
        try 
        {
            BufferedReader fileReader = new BufferedReader(new FileReader(plik));
            String fileText = fileReader.readLine();
            fileReader.close();
            System.out.println("Zawartość pliku:");
            System.out.println(fileText);
        } 
        catch(IOException ex)
        {
            System.err.println(ex.getCause());
        }
    }
}
