#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

#include "files.h"

using namespace std;

int readNumber(int& attempts)
{
    int number;
    while (true)
    {
        cout << "Podaj dodatnia liczbe calkowita: ";
        cin >> number;

        // Sprawdzenie, czy podano liczbę
        if (cin.fail() || number <= 0)
        {
            cin.clear(); // Oczyść flagę błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoruj błędne wejście
            cout << "Bledne dane. Proszę sprobowac ponownie." << endl;
            attempts++; // Zwiększ liczbę prób
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Oczyść bufor
            attempts++; // Zwiększ liczbę prób
            return number;
        }
    }
}



void zad1()
{
    ifstream file("kod.txt");
    if (!file.is_open())
    {
        cerr << "Nie mozna otworzyc pliku kod.txt" << endl;
        return;  // if blad end
    }

    string line;
    while (getline(file, line))
    {
        size_t comment_pos = line.find("//");

        if (comment_pos != string::npos) //string::npos to takie smieszne co zwraca find jak nie findnie
        {
            line = line.substr(0, comment_pos);
        }
        if (!line.empty())
        {
            cout << line << endl;  // Wyświetl zmodyfikowaną linię
        }
    }
    file.close();
    return;
}

void zad2()
{
    int sum = 0;
    int attempts = 0;  //podejscia

    while(sum < 21)
    {
        int number = readNumber(attempts);
        sum += number;

        if(sum == 21)
        {
            cout << "Suma osiagnela oczko (21). Zakonczono program." << endl;
            break;
        }
        else if(sum > 21)
        {
            cout << "Suma przekroczyla 21. Sprobuj ponownie z suma przed przekroczeniem 21." << endl;
            sum -= number; // odrzuca ostatnią liczbę i znowu od ostatniego punktu
        }
    }

    // Wyświetlenie liczby prób
    cout << "Udalo sie osiagnac oczko po " << attempts << " probach." << endl;
    return;
}

void zad3()
{
    Files files;
    string filePath;
    cout << "Podaj ścieżkę do pliku (dane.csv): ";
    cin >> filePath;

    files.loadFromFile(filePath);

    int option;
    while(true)
    {
        cout << "\n1. Wyświetlenie książki adresowej\n"
             << "2. Zapisanie do książki adresowej kolejnej osoby\n"
             << "3. Wyświetlenie osób o podanym nazwisku\n"
             << "4. Stworzenie plików k.csv oraz m.csv\n"
             << "5. Wyświetlenie X pierwszych studentów\n"
             << "6. Posortowanie studentów względem oceny rosnąco\n"
             << "7. Wyjście z programu\n"
             << "Wybierz opcję: ";
        cin >> option;

        switch (option)
        {
            case 1:
                files.displayStudents();
                break;

            case 2:
                files.addStudent();
                files.saveToCSV(filePath); // Zapisuje nowego studenta do pliku
                break;

            case 3:
            {
                string lastName;
                cout << "Podaj nazwisko do wyszukania: ";
                cin >> lastName;
                files.searchByLastName(lastName);
                break;
            }

            case 4:
                files.createGenderFiles();
                break;

            case 5:
            {
                int x;
                cout << "Podaj liczbę studentów do wyświetlenia: ";
                cin >> x;
                files.displayFirstXStudents(x);
                break;
            }

            case 6:
                files.sortStudentsByGrade();
                break;

            case 7:
                cout << "Wyjście z programu." << endl;
                return;

            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie." <<endl;
        }
    }
    return;
}

int main()
{

    //zad1();

    //zad2();

    zad3();

    return 0;
}
