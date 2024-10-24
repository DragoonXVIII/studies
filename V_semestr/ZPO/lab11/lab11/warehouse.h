#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>

using namespace std;

class Warehouse
{
private:
    string productName;
    int quantity;

public:
    Warehouse(const string& name, int qty) : productName(name), quantity(qty)
    {
        cout << "Konstruktor Warehouse: " << productName << ", Ilość: " << quantity << endl;
    }

    ~Warehouse()
    {
        cout << "Destruktor Warehouse: " << productName << endl;
    }

    // Gettery
    string getProductName() const
    {
        return productName;
    }

    int getQuantity() const
    {
        return quantity;
    }

    // Settery
    void setQuantity(int qty)
    {
        quantity = qty;
    }

    // Metoda wyświetlająca informacje o magazynie
    void displayInfo() const
    {
        cout << "Towar: " << productName << ", Ilość: " << quantity << endl;
    }
};


#endif // WAREHOUSE_H
