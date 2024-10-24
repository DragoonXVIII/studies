#include <iostream>
#include <memory>

using namespace std;

// Klasa reprezentująca pojedynczy węzeł listy dwukierunkowej
class Node
{
public:
    int data;                      // Przechowywana wartość
    shared_ptr<Node> next;        // Wskaźnik do następnego węzła
    weak_ptr<Node> prev;          // Wskaźnik do poprzedniego węzła (weak_ptr zapobiega cyklom)

    Node(int value) : data(value), next(nullptr)
    {
        cout << "Konstruktor Node: " << data << endl;
    }

    ~Node()
    {
        cout << "Destruktor Node: " << data << endl;
    }
};

// Klasa reprezentująca dwukierunkową listę
class DoublyLinkedList
{
private:
    shared_ptr<Node> head;        // Wskaźnik do pierwszego węzła
    shared_ptr<Node> tail;        // Wskaźnik do ostatniego węzła

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {
        cout << "Konstruktor DoublyLinkedList" << endl;
    }

    ~DoublyLinkedList()
    {
        cout << "Destruktor DoublyLinkedList" << endl;
        while (!isEmpty())
        {
            removeFront(); // Usunięcie wszystkich węzłów
        }
    }

    // Sprawdzanie, czy lista jest pusta
    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Dodawanie na początek listy
    void addFront(int value)
    {
        auto newNode = make_shared<Node>(value);
        if (isEmpty())
        {
            head = tail = newNode; // Pierwszy węzeł
        }
        else
        {
            newNode->next = head;   // Nowy węzeł wskazuje na obecny head
            head->prev = newNode;   // Obecny head wskazuje na nowy węzeł
            head = newNode;         // Nowy węzeł staje się head
        }
    }

    // Dodawanie na koniec listy
    void addBack(int value)
    {
        auto newNode = make_shared<Node>(value);
        if (isEmpty())
        {
            head = tail = newNode; // Pierwszy węzeł
        }
        else
        {
            tail->next = newNode;  // Obecny tail wskazuje na nowy węzeł
            newNode->prev = tail;   // Nowy węzeł wskazuje na obecny tail
            tail = newNode;         // Nowy węzeł staje się tail
        }
    }

    // Usuwanie z początku listy
    void removeFront()
    {
        if (isEmpty())
        {
            cout << "Lista jest pusta, nie można usunąć elementu." << endl;
            return;
        }
        cout << "Usunięto z przodu: " << head->data << endl;
        head = head->next; // Przesunięcie head do następnego węzła
        if (head)
        {
            head->prev.reset(); // Resetowanie wskaźnika do poprzedniego węzła
        }
        else
        {
            tail.reset(); // Lista jest pusta, resetowanie tail
        }
    }

    // Usuwanie z końca listy
    void removeBack()
    {
        if (isEmpty())
        {
            cout << "Lista jest pusta, nie można usunąć elementu." << endl;
            return;
        }
        cout << "Usunięto z tyłu: " << tail->data << endl;
        tail = tail->prev.lock(); // Używamy weak_ptr do uzyskania poprzedniego węzła
        if (tail)
        {
            tail->next.reset(); // Resetowanie wskaźnika do następnego węzła
        }
        else
        {
            head.reset(); // Lista jest pusta, resetowanie head
        }
    }

    // Wyświetlanie zawartości listy
    void display() const
    {
        if (isEmpty()) {
            cout << "Lista jest pusta." << endl;
            return;
        }
        cout << "Zawartość listy: ";
        shared_ptr<Node> current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Funkcja main do testowania
int main()
{
    DoublyLinkedList list;

    // Dodawanie elementów
    list.addFront(10);
    list.addFront(20);
    list.addBack(30);
    list.addBack(40);

    // Wyświetlanie zawartości listy
    list.display();

    // Usuwanie elementów
    list.removeFront();
    list.removeBack();

    // Wyświetlanie zawartości listy
    list.display();

    // Usuwanie wszystkich elementów
    list.removeFront();
    list.removeFront();

    // Wyświetlanie zawartości listy
    list.display();

    return 0;
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
