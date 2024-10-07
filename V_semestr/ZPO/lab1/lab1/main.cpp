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
        if (animals[i].getProtected()) {  // Używamy teraz metody getProtected
            count++;
        }
    }
    return count;
}


void howManyTrackerDogs(Dog dogs[], int size) {
    for (int i = 0; i < size; ++i) {
        if (dogs[i].getSkillLevel(2) > dogs[i].getSkillLevel(1)) {  // 2 dla tropiciela, 1 dla przewodnika
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


    //Animal a1(3,"3nogipies",true);
    //a1.info();

/*
    // 1. Statyczna tablica statycznych obiektów
    Student staticArray[2];
    staticArray[0].init("Jan", "Kowalski", 21);
    staticArray[0].setIndex("99999");
    staticArray[1].init("Joanna", "Kowalska", 22);
    staticArray[1].setIndex("88888");

    cout << "Statyczna tablica statycznych obiektów:" << endl;
    for (int i = 0; i < 2; ++i) {
        staticArray[i].showInfoStudent();
    }

    // 2. Dynamiczna tablica statycznych obiektów klasy Student
    int n = 2; // Rozmiar tablicy
    Student* dynamicArray = new Student[n]; // Dynamiczna tablica statycznych obiektów
    dynamicArray[0].init("Jan", "Kowalski", 21);
    dynamicArray[0].setIndex("99999");
    dynamicArray[1].init("Joanna", "Kowalska", 22);
    dynamicArray[1].setIndex("88888");

    cout << "\nDynamiczna tablica statycznych obiektów:" << endl;
    for (int i = 0; i < n; ++i) {
        dynamicArray[i].showInfoStudent();
    }

    delete[] dynamicArray;

    // 3. Statyczna tablica dynamicznych obiektów
    Student* staticDynamicArray[2];
    staticDynamicArray[0] = new Student("Kacper", "Kowalski", 22, "11111");
    staticDynamicArray[1] = new Student("Dawid", "Kowalski", 22, "33333");

    cout << "\nStatyczna tablica dynamicznych obiektów:" << endl;
    for (int i = 0; i < 2; ++i) {
        staticDynamicArray[i]->showInfoStudent();
    }
    for (int i = 0; i < 2; ++i) {
        delete staticDynamicArray[i];
    }

    // 4. Dynamiczna tablica dynamicznych obiektów
    Student** dynamicDynamicArray = new Student*[n]; // Dynamiczna tablica wskaźników
    dynamicDynamicArray[0] = new Student("Ewa", "Kowalska", 22, "555555");
    dynamicDynamicArray[1] = new Student("Franek", "Cimoszewicz", 22, "666666");

    cout << "\nDynamiczna tablica dynamicznych obiektów:" << endl;
    for (int i = 0; i < n; ++i) {
        dynamicDynamicArray[i]->showInfoStudent();
    }
    for (int i = 0; i < n; ++i) {
        delete dynamicDynamicArray[i];
    }
    delete[] dynamicDynamicArray;
*/
    return 0;
}
