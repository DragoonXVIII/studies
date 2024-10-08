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
        // Bezargumentowy konstruktor - tablica o rozmiarze 10
        Bufor() : size(10), firstFree(0) {
            tab = new int[size];
        }

        // Konstruktor argumentowy - tablica o zadanym rozmiarze
        Bufor(int size) : size(size), firstFree(0) {
            tab = new int[size];
        }

        // Wirtualny destruktor
        virtual ~Bufor() {
            delete[] tab;
        }

        // Wirtualna metoda add - dodaje element do tablicy
        virtual void add(int value) {
            if (firstFree < size) {
                tab[firstFree++] = value;
            } else {
                std::cout << "Brak miejsca w tablicy!" << std::endl;
            }
        }

        // Czysto wirtualna metoda calculate
        virtual double calculate() = 0;

        // Zwraca indeks pierwszego wolnego miejsca
        int getIndex() const {
            return firstFree;
        }

        // Zwraca rozmiar tablicy
        int getSize() const {
            return size;
        }

        // Zwraca element pod indeksem i
        int getTab(int i) const {
            return tab[i];
        }

        // Zwraca pierwszy wolny indeks
        int getFirst() const {
            return firstFree;
        }

        // Ustawia indeks pierwszego wolnego miejsca
        void setFirst(int value) {
            firstFree = value;
        }

        // Ustawia wartość tablicy pod zadanym indeksem
        void setTab(int pos, int value) {
            if (pos >= 0 && pos < size) {
                tab[pos] = value;
            }
        }

        // Wyświetla zawartość tablicy
        void showTab() const {
            std::cout << "Tablica: ";
            for (int i = 0; i < firstFree; ++i) {
                std::cout << tab[i] << " ";
            }
            std::cout << std::endl;
        }
};

#endif // BUFOR_H
