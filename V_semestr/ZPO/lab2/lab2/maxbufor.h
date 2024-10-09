#ifndef MAXBUFOR_H
#define MAXBUFOR_H
#include "bufor.h"

class MaxBufor : public Bufor {
    public:
        MaxBufor(int size) : Bufor(size) {}

        double calculate() override {
            if (firstFree == 0) return 0; // Brak ele
            int maxVal = tab[0];
            for (int i = 1; i < firstFree; ++i) {
                maxVal = std::max(maxVal, tab[i]);
            }
            return maxVal;
        }

        void add(int value) override {
            if (firstFree < size) {
                Bufor::add(value);
            } else {
                std::cout << "Brak miejsca w MaxBufor!" << std::endl;
            }
        }
};

#endif // MAXBUFOR_H
