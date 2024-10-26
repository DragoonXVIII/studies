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
    Warehouse(const string& name, int qty);
    ~Warehouse();

    string getProductName() const;
    int getQuantity() const;
    void setQuantity(int qty);

    void displayInfo() const;
};


#endif // WAREHOUSE_H
