#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include <string>

class Citizen
{
    private:
        std::string name;
        std::string surname;
        int age;
        char sex;
        std::string postalCode;
        //pola prywatne: name, surname typu string, age typu int, sex typu char oraz postal_code typu string;
    public:
        Citizen();
        Citizen(std::string name, std::string surname, int age, char sex, std::string postalCode): name(name), surname(surname), age(age), sex(sex), postalCode(postalCode){}; //konstruktory: bezargumentowy oraz pozwalający na inicjalizację pól klasy;
        void show() const; //metodę show wyświetlającą informację o mieszkańcu;

        std::string getName() const;
        std::string getSurname() const;
        int getAge() const;
        char getSex() const;
        std::string getPostalCode() const; //odpowiednie gettery do pól
};

#endif // CITIZEN_H
