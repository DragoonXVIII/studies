using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;
using Lab1;

// See https://aka.ms/new-console-template for more information
/*
Console.WriteLine("Zad3: FizzBuzz");
zad3();

Console.WriteLine();
Console.WriteLine("Zad4: Gra - zgadnij liczbę (bez licznika prób)");
zad4();

Console.WriteLine();
Console.WriteLine("Zad5: Gra - zgadnij liczbę (z licznikiem prób)");
zad5();
*/
Console.WriteLine();
Console.WriteLine("Zad6: Gra - zgadnij liczbę (z zapisem HighScore)");
zad6();

static void zad3()
{
    // FizzBuzz: wypisuje liczby od1 do100
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            Console.WriteLine("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (i % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
        {
            Console.WriteLine(i);
        }
    }
}

// Gra
static void zad4()
{
    var rand = new Random();
    int value = rand.Next(1, 101);

    while (true)
    {
        Console.Write("Podaj próbę: ");
        string? input = Console.ReadLine();

        if (!int.TryParse(input, out int guess))
        {
            Console.WriteLine("Nieprawidłowe wejście. Podaj liczbę.");
            continue;
        }

        if (guess < value)
        {
            Console.WriteLine("Za mało.");
        }
        else if (guess > value)
        {
            Console.WriteLine("Za dużo.");
        }
        else
        {
            Console.WriteLine("Gratulacje! Zgadłeś.");
            break;
        }
    }
}

// Gra + licznik prób 
static void zad5()
{
    var rand = new Random();
    int value = rand.Next(1, 101);
    int attempts = 0;

    while (true)
    {
        Console.Write("Podaj próbę: ");
        string? input = Console.ReadLine();

        if (!int.TryParse(input, out int guess))
        {
            Console.WriteLine("Nieprawidłowe wejście. Podaj liczbę.");
            continue;
        }

        attempts++;

        if (guess < value)
        {
            Console.WriteLine("Za mało.");
        }
        else if (guess > value)
        {
            Console.WriteLine("Za dużo.");
        }
        else
        {
            Console.WriteLine($"Gratulacje! Zgadłeś w {attempts} próbach.");
            break;
        }
    }
}

// Gra + zapis HighScore do pliku highscores.json
static void zad6()
{
    const string FileName = "highscores.json";

    List<HighScore> highScores;
    if (File.Exists(FileName))
    {
        try
        {
            string json = File.ReadAllText(FileName);
            highScores = JsonSerializer.Deserialize<List<HighScore>>(json) ?? new List<HighScore>();
        }
        catch
        {
            highScores = new List<HighScore>();
        }
    }
    else
    {
        highScores = new List<HighScore>();
    }

    var rand = new Random();
    int value = rand.Next(1, 101);
    int attempts = 0;

    while (true)
    {
        Console.Write("Podaj próbę: ");
        string? input = Console.ReadLine();

        if (!int.TryParse(input, out int guess))
        {
            Console.WriteLine("Nieprawidłowe wejście. Podaj liczbę.");
            continue;
        }

        attempts++;

        if (guess < value)
        {
            Console.WriteLine("Za mało.");
        }
        else if (guess > value)
        {
            Console.WriteLine("Za dużo.");
        }
        else
        {
            Console.WriteLine($"Gratulacje! Zgadłeś w {attempts} próbach.");

            Console.Write("Podaj swoje imię: ");
            string? name = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(name))
            {
                name = "GallAnonim";
            }

            var hs = new HighScore { Name = name, Trials = attempts };
            highScores.Add(hs);

            var sorted = highScores.OrderBy(h => h.Trials).ToList();
            try
            {
                File.WriteAllText(FileName, JsonSerializer.Serialize(sorted));
            }
            catch
            {

            }

            Console.WriteLine();
            Console.WriteLine("Lista najlepszych wyników:");
            foreach (var item in sorted)
            {
                Console.WriteLine($"{item.Name} -- {item.Trials} prób");
            }

            break;
        }
    }
}