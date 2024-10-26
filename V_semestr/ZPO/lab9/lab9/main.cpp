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

        if (cin.fail() || number <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  bledne wejscie
            cout << "Bledne dane. Proszę sprobowac ponownie." << endl;
            attempts++;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            attempts++;
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
        return;
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
            cout << line << endl;  // pokazuje zmodyfikowaną
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

    cout << "Udalo sie osiagnac oczko po " << attempts << " probach." << endl;
    return;
}

void zad3()
{
    Files files;
    string filePath;
    cout << "Podaj sciezke do pliku (dane.csv): ";
    cin >> filePath;

    files.loadFromFile(filePath);

    int option;
    while(true)
    {
        cout << "\n1. Wyswietlenie ksiazki adresowej\n"
             << "2. Zapisanie do ksiazki adresowej kolejnej osoby\n"
             << "3. Wyswietlenie osob o podanym nazwisku\n"
             << "4. Stworzenie plikow k.csv oraz m.csv\n"
             << "5. Wyswietlenie X pierwszych studentow\n"
             << "6. Posortowanie studentow wzgledem oceny rosnaco\n"
             << "7. Wyjscie z programu\n"
             << "Wybierz opcje: ";
        cin >> option;

        switch (option)
        {
            case 1:
                files.displayStudents();
                break;

            case 2:
                files.addStudent();
                files.saveToCSV(filePath);
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
                cout << "Podaj liczbe studentow do wyswietlenia: ";
                cin >> x;
                files.displayFirstXStudents(x);
                break;
            }

            case 6:
                files.sortStudentsByGrade();
                break;

            case 7:
                cout << "Wyjscie z programu." << endl;
                return;

            default:
                cout << "Nieprawidlowa opcja. Sprobuj ponownie." <<endl;
        }
    }
    return;
}

int main()
{
    while(true)
    {
        int choice;
        std::cout<<"Wybierz: "<<std::endl;
        std::cout<<"Zadanie 9.1. Kod programu ."<<std::endl
                <<"Zadanie 9.2. Oczko."<<std::endl
                <<"Zadanie 9.3.  Kartoteka studentow."<<std::endl;
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
            zad3(); //!!!!!!!!!!! pokazac w z cmd bo qt jest upo lekko i nie ogarnie wczytania pliku ze sciezki
            break;
        }
    }


    return 0;
}
