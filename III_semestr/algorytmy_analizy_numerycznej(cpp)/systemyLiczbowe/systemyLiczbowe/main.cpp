#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Funkcja do konwersji części całkowitej liczby na inny system liczbowy
string IntToBase(int number, int base)
{
    string result = "";
    while (number > 0)
    {
        int digit = number % base;
        char digitChar;
        if (digit < 10)
        {
            digitChar = '0' + digit;
        }
        else
        {
            digitChar = 'A' + digit - 10;
        }
        result = digitChar + result;
        number /= base;
    }
    if (result.empty())
    {
        result = "0";
    }
    return result;
}

// Funkcja do konwersji części ułamkowej liczby na inny system liczbowy
string FractionToBase(double fraction, int base, int precision)
{
    string result = ".";
    for (int i = 0; i < precision; i++)
    {
        fraction *= base;
        int digit = static_cast<int>(fraction);
        char digitChar;
        cout<<digit<<endl;
        if (digit < 10)
        {
            digitChar = '0' + digit;
        }
        else
        {
            digitChar = 'A' + digit - 10;
        }
        result += digitChar;
        fraction -= digit;
    }
    return result;
}

int main()
{
    int number;
    double decimal;
    int base;
    int precision;

    // Pobieranie liczby i jej systemu liczbowego od użytkownika
    cout << "Podaj liczbe calkowita: ";
    cin >> number;
    cout << "Podaj liczbe po przecinku: ";
    cin >> decimal;
    cout << "Podaj podstawe systemu liczbowego: ";
    cin >> base;
    cout << "Podaj ilosc cyfr po przecinku: ";
    cin >> precision;

    // Konwersja części całkowitej i ułamkowej na wybrany system
    string intPart = IntToBase(number, base);
    string floatPart = FractionToBase(decimal, base, precision);

    // Wyświetlenie wyniku
    cout << "Wynik: " << intPart << floatPart << endl;

    return 0;
}





/*#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Funkcja do konwersji części całkowitej liczby na inny system liczbowy
string IntToBase(int number, int base)
{
    string result = "";
    while (number > 0)
    {
        int digit = number % base;
        result = to_string(digit) + result;
        number /= base;
    }
    return result;
}

// Funkcja do konwersji części ułamkowej liczby na inny system liczbowy
string FractionToBase(double fraction, int base, int precision)
{
    string result = ".";
    for (int i = 0; i < precision; i++)
    {
        fraction *= base;
        int digit = static_cast<int>(fraction);
        result += to_string(digit);
        fraction -= digit;
    }
    return result;
}

int main()
{
    int number; //*A*.xxx
    double decimal; //X.*aaa*

    int base; //q
    int precision; //n

    // Pobieranie liczby i jej systemu liczbowego od użytkownika
    cout << "Podaj liczbe calkowita: ";
    cin >> number;
    cout << "Podaj liczbe po przecinku: ";
    cin >> decimal;

    cout << "Podaj podstawe systemu liczbowego: ";
    cin >> base;
    cout << "Podaj ilosc cyfr po przecinku: ";
    cin >> precision;

    // Konwersja części całkowitej i ułamkowej na wybrany system
    string intPart = IntToBase(number, base);
    string fractionPart = FractionToBase(decimal, base, precision);

    // Wyświetlenie wyniku
    cout << "Wynik: " << intPart << fractionPart << endl;

    return 0;
}
*/
