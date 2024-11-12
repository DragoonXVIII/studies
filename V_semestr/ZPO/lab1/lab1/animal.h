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
    Animal() : limbNr(0), name("Unknown"), protectedAnimal(true) {}

    Animal(int limbNr, string name, bool protectedAnimal = true)
        : limbNr(limbNr), name(name), protectedAnimal(protectedAnimal) {}

    void setLimbNr(int limbNr) { this->limbNr = limbNr; }
    int getLimbNr() { return limbNr; }

    void setName(string name) { this->name = name; }
    string getName() { return name; }

    void setProtected(bool protectedAnimal) { this->protectedAnimal = protectedAnimal; }
    bool getProtected() const { return protectedAnimal; }

    virtual void giveVoice() {
        cout << "Chrum, miau, hau, piiiii" << endl;
    }

    virtual void info() {
        cout << "Animal: " << name << " | Limbs: " << limbNr
             << " | Protected: " << (protectedAnimal ? "Yes" : "No") << endl;
    }
};

#endif // ANIMAL_H_INCLUDED
