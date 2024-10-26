#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <numeric>

#include "car.h"

using namespace std;

/*
  Funkcja zwraca:
- długość najkrótszego napisu,
- średnią długość napisu,
- najdłuższy napis
*/
tuple<size_t, double, string> analyzeStrings(const vector<string>& strings)
{
    if (strings.empty())
    {
        return {0, 0.0, ""};
    }

    auto minLengthIt = min_element(strings.begin(), strings.end(),
                                    [](const string& a, const string& b)
    {
        return a.length() < b.length();
    });

    auto maxLengthIt = max_element(strings.begin(), strings.end(),
                                    [](const string& a, const string& b)
    {
        return a.length() < b.length();
    });


    double averageLength = 0.0;
    for (const auto& str : strings)
    {
        averageLength += str.length();
    }
    averageLength /= strings.size();

    return {minLengthIt->length(), averageLength, maxLengthIt->c_str()};
}

void zad1()
{
    vector<string> strings = {"hello", "world", "C++", "programming", "lambda"};

    auto [minLength, avgLength, maxLengthStr] = analyzeStrings(strings);

    cout << "Dlugosc najkrotszego napisu: " << minLength << endl;
    cout << "Srednia dlugosc napisu: " << avgLength << endl;
    cout << "Najdluzszy napis: " << maxLengthStr << endl;

    return;
}

void zad2()
{
    vector<Car> cars;
    cars.emplace_back("Toyota Corolla", 2015, 1.6);
    cars.emplace_back("Ford Fiesta", 2018, 1.0);
    cars.emplace_back("Honda Civic", 2012, 1.8);
    cars.emplace_back("BMW 320i", 2020, 2.0);
    cars.emplace_back("Audi A4", 2019, 2.0);

    //  rosnąco po roku produkcji
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
    {
        return a.getProductionYear() < b.getProductionYear();
    });
    cout << "Samochody posortowane rosnaco wedlug roku produkcji:" << endl;
    for (size_t i = 0; i < cars.size(); ++i)
    {
        cout << (i + 1) << ". ";
        cars[i].display();
    }

    //  malejąco po pojemności
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b)
    {
        return a.getEngineCapacity() > b.getEngineCapacity();
    });
    cout << "\nSamochody posortowane malejaco wedlug pojemnosci silnika:" << endl;
    for (size_t i = 0; i < cars.size(); ++i)
    {
        cout << (i + 1) << ". ";
        cars[i].display();
    }

    return;
}

void displayVector(const vector<int>& vec)
{
    for(const auto& elem : vec)
    {
        cout << elem << "|";
    }
    cout << endl;
}

double calculateAverage(const vector<int>& vec)
{
    if(vec.empty())
        return 0.0;
    return static_cast<double>(accumulate(vec.begin(), vec.end(), 0)) / vec.size();
}

int countEvenNumbers(const vector<int>& vec)
{
    return count_if(vec.begin(), vec.end(), [](int x)
    {
        return x % 2 == 0;
    });
}

void removeNegativeNumbers(vector<int>& vec)
{
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x)
    {
        return x < 0;
    }), vec.end());
}

void sortEvenOdd(vector<int>& vec)
{
    stable_sort(vec.begin(), vec.end(), [](int a, int b)
    {
        return (a % 2 == 0) && (b % 2 != 0); // parzyste przed nieparzystymi
    });
}


void negateValues(vector<int>& vec)
{
    transform(vec.begin(), vec.end(), vec.begin(), [](int x)
    {
        return -x;
    });
}


int countLessThan(const vector<int>& vec, int threshold)
{
    return count_if(vec.begin(), vec.end(), [threshold](int x)
    {
        return x < threshold;
    });
}

void zad3()
{
    vector<int> numbers = {10, -5, 3, 6, 8, -1, 2, 7, 4, -9};

    cout << "Wektory: ";
    displayVector(numbers);

    double average = calculateAverage(numbers);
    cout << "Srednia arytmetyczna: " << average << endl;

    int evenCount = countEvenNumbers(numbers);
    cout << "Liczba elementow parzystych: " << evenCount << endl;

    removeNegativeNumbers(numbers);
    cout << "Wektor po usunieciu ujemnych: ";
    displayVector(numbers);

    sortEvenOdd(numbers);
    cout << "Wektor po posortowaniu parzystych i nieparzystych: ";
    displayVector(numbers);

    negateValues(numbers);
    cout << "Wektor po negacji wartosci: ";
    displayVector(numbers);

    int threshold;
    cout << "Podaj wartosc progowa: ";
    cin >> threshold;
    int countLess = countLessThan(numbers, threshold);
    cout << "Liczba elementow mniejszych niz " << threshold << ": " << countLess << endl;

    return;
}

int main()
{
    while(true)
    {
        int choice;
        std::cout<<"Wybierz: "<<std::endl;
        std::cout<<"Zadanie 12.1. Algorytmy."<<std::endl
                <<"Zadanie 12.2. Samochody."<<std::endl
                <<"Zadanie 12.3. Statystyka."<<std::endl;
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
        }
    }
    return 0;
}
