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
    vector<shared_ptr<Warehouse>> warehouses;

public:
    Shop(const string& name);
    ~Shop();

    void addWarehouse(shared_ptr<Warehouse> warehouse);
    void sellProduct(const string& productName, int qty);
    void displayWarehouses() const;
    string getShopName() const;
};

#endif // SHOP_H
