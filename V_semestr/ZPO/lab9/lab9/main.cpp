#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

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
}

void zad2()
{
    int sum = 0;       // Suma liczb
    int attempts = 0;  // Liczba prób

    while(sum < 21)
    {
        int number = readNumber(attempts); // Odczytaj liczbę od użytkownika
        sum += number; // Dodaj liczbę do sumy

        if(sum == 21)
        {
            cout << "Suma osiagnela oczko (21). Zakonczono program." << endl;
            break; // Zakończ program
        }
        else if(sum > 21)
        {
            cout << "Suma przekroczyla 21. Sprobuj ponownie z suma przed przekroczeniem 21." << endl;
            sum -= number; // Odrzuć ostatnią liczbę
        }
    }

    // Wyświetlenie liczby prób
    cout << "Udalo sie osiagnac oczko po " << attempts << " probach." << endl;
}


int main()
{

    //zad1();

    zad2();

    //zad3();

    return 0;
}
