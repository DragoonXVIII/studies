/*#include <fstream>
#include <iostream>

void generate_combinations(std::ofstream& file, std::string str, int length)
{
    if(length == 0)
    {
        file << str << std::endl;
        return;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        generate_combinations(file, str + i, length - 1);
    }
}

void generate_combinationsaZ(std::ofstream& file, std::string str, int length)
{
    if(length == 0)
    {
        file << str << std::endl;
        return;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        generate_combinationsaZ(file, str + i, length - 1);
    }

    for(char i = 'A'; i <= 'Z'; i++)
    {
        generate_combinationsaZ(file, str + i, length - 1);
    }
}

int main()
{
    std::cout<<"Sprawozdanie:"<<std::endl;
    std::string name3az = "passwords_3_az.txt";
    std::ofstream file3az(name3az);
    //zacznij liczyc czas;
    generate_combinations(file3az, "", 3);
    //zakoncz liczyc czas;
    file3az.close();
    //wyswietl formule "generowanie hasel: 3 znaki, a-z czas: <czas_w_sekundach>;

    std::string name4az = "passwords_4_az.txt";
    std::ofstream file4az(name4az);
    //zacznij liczyc czas;
    generate_combinations(file4az, "", 4);
    //zakoncz liczyc czas;
    file4az.close();
    //wyswietl formule "generowanie hasel: 4 znaki, a-z czas: <czas_w_sekundach>;

    std::string name5az = "passwords_5_az.txt";
    std::ofstream file5az(name5az);
    //zacznij liczyc czas;
    generate_combinations(file5az, "", 5);
    //zakoncz liczyc czas;
    file5az.close();
    //wyswietl formule "generowanie hasel: 5 znaki, a-z czas: <czas_w_sekundach>;

    std::string name6az = "passwords_6_az.txt";
    std::ofstream file6az(name6az);
    //zacznij liczyc czas;
    generate_combinations(file6az, "", 6);
    //zakoncz liczyc czas;
    file6az.close();
    //wyswietl formule "generowanie hasel: 6 znaki, a-z czas: <czas_w_sekundach>;

    std::cout<<"zakonczono zadanie 1"<<std::endl;


    /*
    std::string name3aZ = "passwords_3_aZ.txt";
    std::ofstream file3aZ(name3aZ);
    //zacznij liczyc czas;
    generate_combinationsaZ(file3aZ, "", 3);
    //zakoncz liczyc czas;
    file3aZ.close();
    //wyswietl formule "generowanie hasel: 3 znaki, a-Z czas: <czas_w_sekundach>;
    std::cout<<"zakonczono 3aZ"<<std::endl;

    std::string name4aZ = "passwords_4_aZ.txt";
    std::ofstream file4aZ(name4aZ);
    //zacznij liczyc czas;
    generate_combinationsaZ(file4aZ, "", 4);
    //zakoncz liczyc czas;
    file4aZ.close();
    //wyswietl formule "generowanie hasel: 4 znaki, a-Z czas: <czas_w_sekundach>;

    std::string name5aZ = "passwords_5_aZ.txt";
    std::ofstream file5aZ(name5aZ);
    //zacznij liczyc czas;
    generate_combinationsaZ(file5aZ, "", 5);
    //zakoncz liczyc czas;
    file5aZ.close();
    //wyswietl formule "generowanie hasel: 5 znaki, a-Z czas: <czas_w_sekundach>;

    std::string name6aZ = "passwords_6_aZ.txt";
    std::ofstream file6aZ(name6aZ);
    //zacznij liczyc czas;
    generate_combinationsaZ(file6aZ, "", 6);
    //zakoncz liczyc czas;
    file6aZ.close();
    //wyswietl formule "generowanie hasel: 6 znaki, a-Z czas: <czas_w_sekundach>;

    std::cout<<"zakonczono zadanie 2"<<std::endl;
    /
    return 0;
}*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono> // Biblioteka do pomiaru czasu

// Funkcja generująca kombinacje znaków a-z o zadanej długości i zapisująca je do pliku
void generate_combinations(std::ofstream& file, std::string str, int length)
{
    // Jeśli osiągnięto żądaną długość kombinacji, zapisz ją do pliku
    if (length == 0)
    {
        file << str << std::endl;
        return;
    }

    // Wygeneruj kombinacje dodając kolejne małe litery do ciągu
    for (char i = 'a'; i <= 'z'; i++)
    {
        generate_combinations(file, str + i, length - 1);
    }
}

void generate_PESEL(std::ofstream& file)
{
    //zmniejszyc 7zipem wielkosc bazy danych peseli chociaz do:  61 MB (kilku kilobajtow)
}

int main()
{
    std::cout << "Sprawozdanie:" << std::endl;

    // Mierz czas dla generowania haseł dla długości 3, 4, 5 i 6 znaków z zakresem a-z
    for (int length = 3; length <= 6; ++length)
    {
        std::string name = "passwords_" + std::to_string(length) + "_az.txt";
        std::ofstream file(name);

        // Rozpocznij mierzenie czasu
        auto start = std::chrono::steady_clock::now();

        // Wygeneruj kombinacje haseł i zapisz je do pliku
        generate_combinations(file, "", length);

        // Zakończ mierzenie czasu
        auto end = std::chrono::steady_clock::now();

        // Oblicz czas trwania w sekundach
        double duration = std::chrono::duration<double>(end - start).count();

        // Zapisz czas generowania haseł do pliku
        file << "Czas generowania: " << duration << " sekund" << std::endl;

        // Wyświetl komunikat o generowaniu haseł
        std::cout << "Wygenerowano hasla: " << length << " znaki, a-z czas: " << duration << " sekund" << std::endl;

        // Zamknij plik
        file.close();
    }

    std::cout << "Zakończono zadanie 1" << std::endl;

    return 0;
}

/*
    W dowolnym języku programowania napisz program generujący (lub próbujący to zrobić) wszystkie hasła 3, 4, 5
    i 6 znakowe (zapisz je do pliku) z następującymi założeniami:
    1.1. Hasła składa się tylko z małych liter.
    1.2. Hasło składa się z małych i dużych liter.
    1.3. Hasło składa się z małych i dużych liter, cyfr i pozostałych znaków ASCI (kody ASCI od 32 do 126))

    RRMMDDPPPPK
    RR - 00-99
    MM - 01-12
    DD - 01-31
    PPPP - 0-9999
    K - 1-9

*/
