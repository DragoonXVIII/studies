#ifndef DOG_H_INCLUDED
#define DOG_H_INCLUDED

#include "Animal.h"

class Dog : public Animal
{
private:
    string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;

public:
    Dog() : Animal(), breed("Unknown"), levelOfGuideSkills(0), levelOfTrackerSkills(0) {}

    Dog(int limbNr, string name, bool protectedAnimal) : Animal(limbNr, name, protectedAnimal),
        breed("Unknown"), levelOfGuideSkills(0), levelOfTrackerSkills(0) {}

    Dog(int limbNr, string name, bool protectedAnimal, string breed, int guideSkills, int trackerSkills)
        : Animal(limbNr, name, protectedAnimal), breed(breed)
    {
        setSkillLevel(1, guideSkills);
        setSkillLevel(2, trackerSkills);
    }

    void setBreed(string breed) { this->breed = breed; }
    string getBreed() { return breed; }

    void setSkillLevel(int type, int value) {
        if (value < 1 || value > 10) {
            cout << "Skill level must be between 1 and 10." << endl;
            return;
        }
        if (type == 1) {
            levelOfGuideSkills = value;
        } else if (type == 2) {
            levelOfTrackerSkills = value;
        } else {
            cout << "Invalid skill type." << endl;
        }
    }

    int getSkillLevel(int type) {
        if (type == 1) {
            return levelOfGuideSkills;
        } else if (type == 2) {
            return levelOfTrackerSkills;
        } else {
            return 0;  //blad
        }
    }

    void giveVoice() override {
        cout << "Hau, hau" << endl;
    }

    void info() override {
        Animal::info();  
        cout << "Breed: " << breed << endl;
        cout << "Guide skills level: " << levelOfGuideSkills << endl;
        cout << "Tracker skills level: " << levelOfTrackerSkills << endl;
    }
};

#endif // DOG_H_INCLUDED
