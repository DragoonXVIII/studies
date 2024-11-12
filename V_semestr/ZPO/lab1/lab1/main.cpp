#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "student.h"
#include "animal.h"
#include "dog.h"
#include "cat.h"

using namespace std;

int howManyProtectedAnimals(Animal animals[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (animals[i].getProtected()) {  
            count++;
        }
    }
    return count;
}

// 2 dla tropiciela, 1 dla przewodnika
void howManyTrackerDogs(Dog dogs[], int size) {
    for (int i = 0; i < size; ++i) {
        if (dogs[i].getSkillLevel(2) > dogs[i].getSkillLevel(1)) {  
            cout << "Dog: " << dogs[i].getName() << " - Tracker level: " << dogs[i].getSkillLevel(2)
                 << " Guide level: " << dogs[i].getSkillLevel(1) << endl;
        }
    }
}

void howManyCats(Cat cats[], int size) {
    for (int i = 0; i < size; ++i) {
        int totalMice = 0;
        for (int year = 1; year <= 5; ++year) {
            totalMice += cats[i].getMice(year);
        }
        cout << "Cat: " << cats[i].getName() << " - Total mice hunted in 5 years: " << totalMice << endl;
    }
}


int main()
{
    Dog d1(3,"3nogipies",true,"mieszaniec",9,9);
    d1.info();

    Animal animals[3] = {Animal(4, "LEW", true), Animal(4, "slon", true), Animal(2, "waz", false)};

    Dog dogs[2] = {Dog(4, "rex", true, "niemiecki owczarek", 5, 8),
                   Dog(4, "ziomal", true, "pudel", 3, 7)};

    Cat cats[2];
    cats[0].initCat(4, "Whiskers", false, 7, 3, 5, 2, 8, 4);
    cats[1].initCat(4, "Tom", false, 9, 6, 7, 8, 9, 10);

    int protectedAnimals = howManyProtectedAnimals(animals, 3);
    cout << "Number of protected animals: " << protectedAnimals << endl;

    cout << "Tracker dogs:" << endl;
    howManyTrackerDogs(dogs, 2);

    cout << "Cats hunting mice:" << endl;
    howManyCats(cats, 2);

    return 0;
}
