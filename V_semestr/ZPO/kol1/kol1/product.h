#ifndef PRODUCT_H
#define PRODUCT_H


#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    /*Pola prywatne:
    name (nazwa produktu, typu string),
    price (cena produktu, typu float),
    quantity (ilość produktu, typu int),
    studentID (Twój numer albumu, typu string).*/
    string name;
    float price;
    int quantity;
    string studentID;

public:

    /*Konstruktory:
    Bezargumentowy ustawiający wartości domyślne: "undefined", 0.0 i 0.
    Argumentowy inicjalizujący wszystkie pola, w tym studentID.*/
    Product() : name("undefined"), price(0.0), quantity(0), studentID("00000") {}
    Product(string n, float p, int q, string id) : name(n), price(p), quantity(q), studentID(id) {}


    /*Metody publiczne:
    setName, setPrice, setQuantity – ustawiające odpowiednie pola,
    getName, getPrice, getQuantity – zwracające odpowiednie pola,
    info() – wyświetlającą informacje o produkcie w formacie:
    Produkt: <nazwa>, Cena: <cena>, Ilość: <ilość>, Numer albumu: <studentID>*/
    void setName(string n);
    void setPrice(float p);
    void setQuantity(int q);

    string getName() const; //const zeby nie modyfikowac danych w srodku, tak samo robilem wiekszosc zadan z labolatoriow
    float getPrice() const;
    int getQuantity() const;

    void info() const;
};




#endif // PRODUCT_H
