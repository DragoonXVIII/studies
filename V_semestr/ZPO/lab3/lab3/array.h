#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        int maxSize;
        int firstAvail;
        T *array;   //pole do przechowywania tablicy o typie T*,
    public:
        Array(); //bezargumentowy, 10 maxSize
        Array(int maxSize); //argumentowy, przydzieli pamiec;
        ~Array(); //zwolni pamiec

        void sortAscending();
        void showArray();
        void addEl(T el);

        T getMaxEl() const;
        T getNEl(int n) const;
};

template <>
class Array<std::string>
{
    private:
        int maxSize;
        int firstAvail;
        std::string *array;   //pole do przechowywania tablicy o typie T*,
    public:
        Array(); //bezargumentowy, 10 maxSize
        Array(int maxSize); //argumentowy, przydzieli pamiec;
        ~Array(); //zwolni pamiec

        void sortAscending();
        void showArray();
        void addEl(std::string el);

        std::string getMaxEl() const;
        std::string getNEl(int n) const;
};

/*
    Dokonaj specjalizacji klasy Array dla typu string, w taki sposób aby:
    • metoda sortująca sortowała słowa pod względem ich długości;
    • metoda zwracająca element maksymalny zwracała najdłuższy napis znajdujący się
    w tablicy.
*/

#endif // ARRAY_H
