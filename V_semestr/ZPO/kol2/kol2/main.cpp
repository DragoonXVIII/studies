#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>
// ctr c ctrv z wszysktich projektow co by nie zabraklo xd

#include "student.h"

/*
ZADANIE 1.
Napisz program, który wczytuje dane liczbowe z pliku tekstowego input.txt
(każda liczba w nowej linii). Ignoruje błędne linie (np. tekst lub pustą linię),
zapisując szczegóły błędu do pliku error.log w formacie: Linia [numer_linii]: [treść_linii] - nieprawidłowy format.
Jeśli plik będzie pusty, program powinien zawierać walidację i wyświetlić w konsoli "Plik nie posiada danych".
Następnie obliczy średnią tych wartości oraz wyświetli tę średnią i zapisze do pliku, który będzie nazwany Twoim numerem albumu (np. 123456.txt).
Do pliku wynikowego dołącz liczby składowe średniej, według przykładu poniżej.
*/

void zad1()
{
    std::ifstream inputFile("input.txt");
    std::ofstream errorFile("error.log");
    std::vector<double> suma;
    std::string linia;

    int numerLinii = 0;
    if(!inputFile.is_open())
    {
        std::cerr<< "Nie mozna otworzyc pliku input.txt" << std::endl;
        return;
    }

    while(std::getline(inputFile, linia))
    {
        numerLinii++;
        std::stringstream ss(linia);
        double liczby;

        if(!(ss >> liczby))
        {
            errorFile<< "Linia "<< numerLinii<< ": "<< linia<< " - nieprawidlowy format"<< std::endl;
        }
        else
        {
            suma.push_back(liczby);
        }
    }

    inputFile.close();
    errorFile.close();

    if(suma.empty())
    {
        std::cout<< "Plik nie posiada danych"<< std::endl;
        return;
    }

    double sum = 0;
    for(double num : suma)
    {
        sum += num;
    }

    double average = sum/suma.size();

    std::cout<< "Srednia: "<< average<< std::endl;
    std::ofstream outputFile("99630.txt");

    outputFile<< "Srednia: "<< average<< std::endl;
    outputFile<< "Liczby składowe średniej:"<< std::endl;

    for(double num : suma)
    {
        outputFile<< num<< std::endl;
    }
    outputFile.close();
    return;
}

/*
ZADANIE 2.

Napisz program, który pobiera od użytkownika stringa i sprawdza, czy tekst jest poprawnym adresem e-mail
(np. przy użyciu wyrażenia regularnego). Jeśli tekst nie jest adresem e-mail, wyświetla komunikat o błędzie.
 Jeśli tekst jest poprawnym adresem e-mail, dzieli go na część lokalną i domenę.

Przykład widoku konsoli dla "user@example.com":
Część lokalna: user
Domena: example.com
*/

void zad2()
{
    std::string email;
    std::cout<< "Podaj adres e-mail: ";
    std::cin>> email;

    const std::regex wzor ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(std::regex_match(email, wzor))
    {
        size_t malpa = email.find('@');
        std::string cz_lokalna = email.substr(0, malpa);
        std::string cz_domeny = email.substr(malpa + 1);

        std::cout<< "Czesc lokalna: "<< cz_lokalna<< std::endl;
        std::cout<< "Domena: "<< cz_domeny<< std::endl;
    }
    else
    {
        std::cout<< "Niepoprawny adres e-mail"<< std::endl;
    }
    return;
}

/*
ZADANIE 3.

Utwórz klasę Student, która zawiera:
imię (std::string),
numer indeksu (std::string).

Napisz program, który tworzy dynamiczną tablicę obiektów Student przy użyciu inteligentnych wskaźników
 (std::shared_ptr) i uzupełnia dane studentów na podstawie wejścia od użytkownika
- program powinien zapytać się ilu użytkownik ma studentów, a następnie przyjąć podaną liczbę danych.
Wyświetl listę studentów w formacie:
Imię: [imię], Numer indeksu: [indeks]

Punkty obowiązkowe do wykonania:
- Zaimplementuj konstruktor parametryczny w klasie Student
- Użyj pętli do dodawania obiektów do tablicy
*/

void zad3()
{
    int liczba_studentow;
    std::cout<< "Podaj liczbe studentow: ";
    std::cin>> liczba_studentow;

    std::vector<std::shared_ptr<Student>> studenci;
    for(int i = 0; i < liczba_studentow; i++)
    {
        std::string imie, numer_indeksu;
        std::cout<< "Podaj imie studenta: ";
        std::cin>> imie;
        std::cout<< "Podaj numer indeksu studenta: ";
        std::cin>> numer_indeksu;
        studenci.push_back(std::make_shared<Student>(imie, numer_indeksu));
    }

    std::cout<< "Lista studentow:"<< std::endl;
    for(const auto& student : studenci)
    {
        std::cout<< "Imie: "<< student->imie<< ", Numer indeksu: "<< student->numer_indeksu<< std::endl;
    }
}

/*
ZADANIE 4.
Napisz program, który tworzy wektor krotek, gdzie każda krotka zawiera trzy elementy:
std::string (nazwa przedmiotu), int (liczba godzin), float (średnia ocen).
Posortuj wektor w porządku rosnącym według liczby godzin za pomocą wyrażenia lambda.
Skorzystaj z std::sort i lambdy do sortowania oraz wykorzystaj std::get do dostępu do elementów krotki.
Na końcu konsoli wyświetl swoje inicjały, aby podpisać swoje kolokwium :)

Wyświetl posortowaną listę w formacie:
[Nazwa przedmiotu] - [Liczba godzin]h - Średnia ocen: [średnia].
PT
*/

void zad4()
{

    std::vector< std::tuple<std::string, int, float>> przedmioty =
    {
        {"Systemy wbudowane", 120, 4.5},
        {"Zaawansowana Inzynieria Oprogramowania", 100, 4.0},
        {"Programowanie Aplikacji Internetowych", 80, 3.5},
        {"Programowanie w jezyku SWIFT", 90, 4.2}
    };

    std::sort(przedmioty.begin(), przedmioty.end(), [](const auto& a, const auto& b)
    {
        return std::get<1>(a) < std::get<1>(b);
    });

    for(const auto& przedmiot : przedmioty)
    {
        std::cout<< std::get<0>(przedmiot)<< " - "<<
        std::get<1>(przedmiot)<< "h - Srednia ocen: "<<
        std::get<2>(przedmiot)<< std::endl;
    }

    std::cout<< "JM"<< std::endl;
    return;
}

int main()
{

    //zad1();

    //zad2();

    //zad3();

    //zad4();

    while(true)
    {
        int choice;
        std::cout<<"Wybierz: "<<std::endl;
        std::cout<<"Zadanie 1. (do poprawnego dzialania nalezy uruchomic z poziomu cmd)"<<std::endl
                 <<"Zadanie 2."<<std::endl
                 <<"Zadanie 3."<<std::endl
                 <<"Zadanie 4."<<std::endl;
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            zad1();
            break;

        case 2:
            zad2();
            break;

        case 3:
            zad3();
            break;

        case 4:
            zad4();
            break;
        }
    }


    std::getchar();
    return 0;
}


