#ifndef MAXBUFOR_H
#define MAXBUFOR_H
#include "bufor.h"

// Klasa MaxBufor - oblicza maksymalną wartość
class MaxBufor : public Bufor {
    public:
        // Konstruktor dziedziczony po Buforze
        MaxBufor(int size) : Bufor(size) {}

        // Nadpisuje metodę calculate, zwracając maksymalną wartość
        double calculate() override {
            if (firstFree == 0) return 0; // Brak elementów
            int maxVal = tab[0];
            for (int i = 1; i < firstFree; ++i) {
                maxVal = std::max(maxVal, tab[i]);
            }
            return maxVal;
        }

        // Nadpisuje metodę add - sprawdza, czy jest miejsce
        void add(int value) override {
            if (firstFree < size) {
                Bufor::add(value);  // Wywołanie podstawowej metody add
            } else {
                std::cout << "Brak miejsca w MaxBufor!" << std::endl;
            }
        }
};

#endif // MAXBUFOR_H
