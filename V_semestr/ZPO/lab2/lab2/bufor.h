#ifndef BUFOR_H
#define BUFOR_H

#include <iostream>
#include <algorithm> // dla std::max

// Klasa Bufor
class Bufor {
protected:
    int* tab;      // Wskaźnik na dynamiczną tablicę
    int size;      // Rozmiar tablicy
    int firstFree; // Indeks pierwszego wolnego miejsca

public:
    Bufor() : size(10), firstFree(0) {
        tab = new int[size];
    }

    Bufor(int size) : size(size), firstFree(0) {
        tab = new int[size];
    }

    virtual ~Bufor() {
        delete[] tab;
    }

    virtual void add(int value) {
        if (firstFree < size) {
            tab[firstFree++] = value;
        } else {
            std::cout << "Brak miejsca w tablicy!" << std::endl;
        }
    }

    virtual double calculate() = 0;

    int getIndex() const {
        return firstFree;
    }

    int getSize() const {
        return size;
    }

    int getTab(int i) const {
        return tab[i];
    }

    int getFirst() const {
        return firstFree;
    }

    void setFirst(int value) {
        firstFree = value;
    }

    void setTab(int pos, int value) {
        if (pos >= 0 && pos < size) {
            tab[pos] = value;
        }
    }

    void showTab() const {
        std::cout << "Tablica: ";
        for (int i = 0; i < firstFree; ++i) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // BUFOR_H
