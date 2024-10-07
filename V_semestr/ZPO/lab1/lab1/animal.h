#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
using namespace std;

class Animal {
private:
    int limbNr;
    string name;
    bool protectedAnimal;

public:
    // Konstruktor bezparametrowy
    Animal() : limbNr(0), name("Unknown"), protectedAnimal(true) {}

    // Konstruktor z parametrami
    Animal(int limbNr, string name, bool protectedAnimal = true)
        : limbNr(limbNr), name(name), protectedAnimal(protectedAnimal) {}

    // Setter i getter dla limbNr
    void setLimbNr(int limbNr) { this->limbNr = limbNr; }
    int getLimbNr() { return limbNr; }

    // Setter i getter dla name
    void setName(string name) { this->name = name; }
    string getName() { return name; }

    // Setter i getter dla protectedAnimal
    void setProtected(bool protectedAnimal) { this->protectedAnimal = protectedAnimal; }
    bool getProtected() const { return protectedAnimal; }

    // Metoda giveVoice()
    virtual void giveVoice() {
        cout << "Chrum, miau, hau, piiiii" << endl;
    }

    // Metoda info()
    virtual void info() {
        cout << "Animal: " << name << " | Limbs: " << limbNr
             << " | Protected: " << (protectedAnimal ? "Yes" : "No") << endl;
    }
};

#endif // ANIMAL_H_INCLUDED
