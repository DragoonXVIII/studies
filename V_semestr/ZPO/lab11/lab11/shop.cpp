#include "shop.h"


Shop::Shop(const string& name) : shopName(name)
{
    cout << "Konstruktor Shop: " << shopName << endl;
}

Shop::~Shop()
{
    cout << "Destruktor Shop: " << shopName << endl;
}

void Shop::addWarehouse(shared_ptr<Warehouse> warehouse)
{
    warehouses.push_back(warehouse);
}

void Shop::sellProduct(const string& productName, int qty)
{
    for(auto& warehouse : warehouses)
    {
        if(warehouse->getProductName() == productName)
        {
            if(warehouse->getQuantity() >= qty)
            {
                warehouse->setQuantity(warehouse->getQuantity() - qty);
                cout << "Sprzedano " << qty << " sztuk " << productName << " z magazynu." << endl;
                return;
            }
            else
            {
                cout << "Brak wystarczajacej ilosci " << productName << " w magazynie." << endl;
                return;
            }
        }
    }
    cout << "Towar " << productName << " nie znaleziony w zadnym magazynie." << endl;
}

void Shop::displayWarehouses() const
{
    cout << "Magazyny dla sklepu " << shopName << ":" << endl;
    for(const auto& warehouse : warehouses)
    {
        warehouse->displayInfo();
    }
}

string Shop::getShopName() const
{
    return shopName;
}
