#ifndef MEANBUFOR_H
#define MEANBUFOR_H
#include "bufor.h"

// Klasa MeanBufor - oblicza średnią arytmetyczną
class MeanBufor : public Bufor {
    public:
        // Konstruktor dziedziczony po Buforze
        MeanBufor(int size) : Bufor(size) {}

        // Nadpisuje metodę calculate, zwracając średnią arytmetyczną
        double calculate() override {
            if (firstFree == 0) return 0; // Brak elementów
            double sum = 0;
            for (int i = 0; i < firstFree; ++i) {
                sum += tab[i];
            }
            return sum / firstFree;
        }
};

#endif // MEANBUFOR_H