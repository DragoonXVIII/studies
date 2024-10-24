#include <iostream>
#include <memory>

#include "doublylinkedlist.h"
#include "warehouse.h"
#include "shop.h"

using namespace std;

void zad1()
{
    DoublyLinkedList list;

    list.addFront(10);
    list.addFront(20);
    list.addBack(30);
    list.addBack(40);

    list.display();

    list.removeFront();
    list.removeBack();

    list.display();

    list.removeFront();
    list.removeFront();

    list.display();
    return;
}

void zad2()
{
    auto warehouse1 = make_shared<Warehouse>("Książki", 50);
    auto warehouse2 = make_shared<Warehouse>("Komputery", 30);
    auto warehouse3 = make_shared<Warehouse>("Łóżka", 15);

    vector<shared_ptr<Shop>> shops;
    shops.push_back(make_shared<Shop>("Sklep 1"));
    shops.push_back(make_shared<Shop>("Sklep 2"));

    shops[0]->addWarehouse(warehouse1);
    shops[0]->addWarehouse(warehouse2);
    shops[1]->addWarehouse(warehouse2); // ten sam magazyn
    shops[1]->addWarehouse(warehouse3);

    for (const auto& shop : shops)
    {
        shop->displayWarehouses();
    }

    shops[0]->sellProduct("Książki", 10);
    shops[1]->sellProduct("Komputery", 5);
    shops[0]->sellProduct("Łóżka", 20); // za duzo sztuk

    cout << endl << "Stan magazynów po sprzedaży:" << endl;
    for (const auto& shop : shops)
    {
        shop->displayWarehouses();
    }
    return;
}

void zad3()
{

    return;
}

int main()
{

    //zad1();

    zad2();

    //zad3();

}

/*
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Klasa Warehouse reprezentująca magazyn
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

// Klasa Shop reprezentująca sklep
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

// Funkcja main do testowania
int main()
{
    // Tworzenie magazynów
    auto warehouse1 = make_shared<Warehouse>("Książki", 50);
    auto warehouse2 = make_shared<Warehouse>("Komputery", 30);
    auto warehouse3 = make_shared<Warehouse>("Łóżka", 15);

    // Tworzenie sklepów
    vector<shared_ptr<Shop>> shops;
    shops.push_back(make_shared<Shop>("Sklep 1"));
    shops.push_back(make_shared<Shop>("Sklep 2"));

    // Dodawanie magazynów do sklepów
    shops[0]->addWarehouse(warehouse1);
    shops[0]->addWarehouse(warehouse2);
    shops[1]->addWarehouse(warehouse2); // Używanie tego samego magazynu
    shops[1]->addWarehouse(warehouse3);

    // Wyświetlanie magazynów
    for (const auto& shop : shops)
    {
        shop->displayWarehouses();
    }

    // Sprzedaż towaru
    shops[0]->sellProduct("Książki", 10);
    shops[1]->sellProduct("Komputery", 5);
    shops[0]->sellProduct("Łóżka", 20); // Zbyt wiele sztuk

    // Wyświetlanie magazynów po sprzedaży
    cout << endl << "Stan magazynów po sprzedaży:" << endl;
    for (const auto& shop : shops)
    {
        shop->displayWarehouses();
    }

    return 0;
}
*/

/*#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Klasa abstrakcyjna Buffer
class Buffer {
public:
    Buffer() {
        cout << "Konstruktor Buffer" << endl;
    }
    virtual ~Buffer() {
        cout << "Destruktor Buffer" << endl;
    }
    virtual void add(int a) = 0; // czysto wirtualna metoda
    virtual void write() = 0; // czysto wirtualna metoda
};

// Klasa BufferArr dziedzicząca po Buffer
class BufferArr : public Buffer {
private:
    int* arr;
    size_t size;
    size_t count;

public:
    BufferArr(size_t size) : size(size), count(0) {
        arr = new int[size];
        cout << "Konstruktor klasy BufferArr" << endl;
    }

    ~BufferArr() override {
        delete[] arr; // Zwalnianie pamięci
        cout << "Destruktor klasy BufferArr" << endl;
    }

    void add(int a) override {
        if (count < size) {
            arr[count++] = a;
        } else {
            cout << "Tablica jest pełna, nie można dodać elementu: " << a << endl;
        }
    }

    void write() override {
        cout << "Elementy w BufferArr: ";
        for (size_t i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Klasa BufferFile dziedzicząca po Buffer
class BufferFile : public Buffer {
private:
    string filePath;

public:
    BufferFile(const string& path) : filePath(path) {
        cout << "Konstruktor klasy BufferFile" << endl;
    }

    ~BufferFile() override {
        cout << "Destruktor klasy BufferFile" << endl;
    }

    void add(int a) override {
        ofstream file(filePath, ios::app);
        if (file.is_open()) {
            file << a << endl;
            file.close();
        } else {
            cout << "Nie można otworzyć pliku: " << filePath << endl;
        }
    }

    void write() override {
        ifstream file(filePath);
        if (!file.is_open()) {
            cout << "Nie można otworzyć pliku: " << filePath << endl;
            return;
        }

        cout << "Elementy w BufferFile: ";
        int number;
        while (file >> number) {
            cout << number << " ";
        }
        cout << endl;
        file.close();
    }
};

// Funkcja main do testowania
int main() {
    vector<shared_ptr<Buffer>> buffers; // Kontener z inteligentnymi wskaźnikami

    // Tworzenie instancji BufferArr i BufferFile
    buffers.push_back(make_shared<BufferArr>(5)); // Tablica rozmiaru 5
    buffers.push_back(make_shared<BufferFile>("numbers.txt")); // Plik

    // Testowanie dodawania i wypisywania
    buffers[0]->add(1);
    buffers[0]->add(2);
    buffers[0]->add(3);
    buffers[0]->add(4);
    buffers[0]->add(5);
    buffers[0]->add(6); // Przekroczenie rozmiaru tablicy

    buffers[0]->write();

    buffers[1]->add(10);
    buffers[1]->add(20);
    buffers[1]->add(30);

    buffers[1]->write(); // Wypisuje zawartość pliku

    return 0;
}
*/
