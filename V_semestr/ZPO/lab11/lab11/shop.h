#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "warehouse.h"

using namespace std;

class Shop
{
private:
    string shopName;
    vector<shared_ptr<Warehouse>> warehouses; // Lista magazynów

public:
    Shop(const string& name) : shopName(name)
    {
        cout << "Konstruktor Shop: " << shopName << endl;
    }

    ~Shop()
    {
        cout << "Destruktor Shop: " << shopName << endl;
    }

    // Metoda dodająca magazyn do listy
    void addWarehouse(shared_ptr<Warehouse> warehouse)
    {
        warehouses.push_back(warehouse);
    }

    // Metoda sprzedająca towar
    void sellProduct(const string& productName, int qty)
    {
        for (auto& warehouse : warehouses)
        {
            if (warehouse->getProductName() == productName)
            {
                if (warehouse->getQuantity() >= qty)
                {
                    warehouse->setQuantity(warehouse->getQuantity() - qty);
                    cout << "Sprzedano " << qty << " sztuk " << productName << " z magazynu." << endl;
                    return;
                }
                else
                {
                    cout << "Brak wystarczającej ilości " << productName << " w magazynie." << endl;
                    return;
                }
            }
        }
        cout << "Towar " << productName << " nie znaleziony w żadnym magazynie." << endl;
    }

    // Metoda wyświetlająca informacje o magazynach
    void displayWarehouses() const
    {
        cout << "Magazyny dla sklepu " << shopName << ":" << endl;
        for (const auto& warehouse : warehouses)
        {
            warehouse->displayInfo();
        }
    }

    // Metoda wyświetlająca nazwę sklepu
    string getShopName() const
    {
        return shopName;
    }
};

#endif // SHOP_H
