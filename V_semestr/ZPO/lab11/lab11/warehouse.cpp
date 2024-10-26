#include "warehouse.h"

#include <string>

using namespace std;

Warehouse::Warehouse(const string& name, int qty) : productName(name), quantity(qty)
{
    cout << "Konstruktor Warehouse: " << productName << ", Ilosc: " << quantity << endl;
}

Warehouse::~Warehouse()
{
    cout << "Destruktor Warehouse: " << productName << endl;
}

// Gettery
string Warehouse::getProductName() const
{
    return productName;
}

int Warehouse::getQuantity() const
{
    return quantity;
}

void Warehouse::setQuantity(int qty)
{
    quantity = qty;
}

void Warehouse::displayInfo() const
{
    cout << "Towar: " << productName << ", Ilosc: " << quantity << endl;
}
