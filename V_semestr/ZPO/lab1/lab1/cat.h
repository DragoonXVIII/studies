#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include "Animal.h"

class Cat : public Animal
{
private:
    int levelOfMouseHunting;  // poziom umiejętności łowienia myszy (1-10)
    int mice[5];              // tablica przechowująca liczbę upolowanych myszy w ciągu 5 lat

public:
    // Konstruktor bezparametrowy
    Cat() : Animal(), levelOfMouseHunting(0) {
        for (int i = 0; i < 5; i++) {
            mice[i] = 0;
        }
    }

    // Konstruktor inicjalizujący tylko składowe klasy Animal
    Cat(int limbNr, string name, bool protectedAnimal)
        : Animal(limbNr, name, protectedAnimal), levelOfMouseHunting(0) {
        for (int i = 0; i < 5; i++) {
            mice[i] = 0;
        }
    }

    // Metoda initMice – inicjalizuje wartościami tablicę mice
    void initMice(int m1, int m2, int m3, int m4, int m5) {
        mice[0] = m1;
        mice[1] = m2;
        mice[2] = m3;
        mice[3] = m4;
        mice[4] = m5;
    }

    // Metoda initCat – inicjalizuje wszystkie składowe klasy Cat
    void initCat(int limbNr, string name, bool protectedAnimal, int levelOfHunting, int m1, int m2, int m3, int m4, int m5) {
        // Inicjalizacja klasy bazowej Animal za pomocą konstruktora
        *this = Cat(limbNr, name, protectedAnimal);
        setLevelOfMouseHunting(levelOfHunting);
        initMice(m1, m2, m3, m4, m5);
    }

    // Setter dla poziomu umiejętności łowienia myszy
    void setLevelOfMouseHunting(int value) {
        if (value >= 1 && value <= 10) {
            levelOfMouseHunting = value;
        } else {
            cout << "Level of mouse hunting must be between 1 and 10." << endl;
        }
    }

    // Getter dla poziomu umiejętności łowienia myszy
    int getLevelOfMouseHunting() {
        return levelOfMouseHunting > 0 ? levelOfMouseHunting : 0;
    }

    // Getter dla liczby upolowanych myszy w danym roku
    int getMice(int index) {
        if (index >= 1 && index <= 5) {
            return mice[index - 1];
        } else {
            cout << "Index out of bounds. Valid range is 1 to 5." << endl;
            return 0;
        }
    }

    // Przesłonięcie metody giveVoice() z klasy Animal
    void giveVoice() override {
        cout << "Miau miau" << endl;
    }

    // Przesłonięcie metody info() z klasy Animal
    void info() override {
        Animal::info();  // Wywołanie metody bazowej
        cout << "Level of mouse hunting: " << getLevelOfMouseHunting() << endl;
        cout << "Mice hunted in last 5 years: ";
        for (int i = 0; i < 5; i++) {
            cout << mice[i] << (i < 4 ? ", " : "\n");
        }
    }
};

#endif // CAT_H_INCLUDED