#include "product.h"

void Product::setName(string n)
{
    name = n;
}

void Product::setPrice(float p)
{
    price = p;
}

void Product::setQuantity(int q)
{
    quantity = q;
}

string Product::getName() const
{
    return name;
}

float Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

void Product::info() const
{
    cout<< "Produkt: "<< name<< ", Cena: "<< price<< ", Ilosc: "<< quantity<< ", Numer albumu: "<< studentID<< endl;
}
