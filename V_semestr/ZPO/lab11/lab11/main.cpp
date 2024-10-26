#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "doublylinkedlist.h"
#include "warehouse.h"
#include "shop.h"
#include "bufferarr.h"
#include "bufferfile.h"


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
    auto warehouse1 = make_shared<Warehouse>("Ksiazki", 50);
    auto warehouse2 = make_shared<Warehouse>("Komputery", 30);
    auto warehouse3 = make_shared<Warehouse>("Lozka", 15);

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

    shops[0]->sellProduct("Ksiazki", 10);
    shops[1]->sellProduct("Komputery", 5);
    shops[0]->sellProduct("Lozka", 20); // za duzo sztuk

    cout << endl << "Stan magazynow po sprzedazy:" << endl;
    for (const auto& shop : shops)
    {
        shop->displayWarehouses();
    }
    return;
}

void zad3()
{
    vector<shared_ptr<Buffer>> buffers;


    buffers.push_back(make_shared<BufferArr>(5));
    buffers.push_back(make_shared<BufferFile>("numbers.txt"));

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

    buffers[1]->write(); // wypisz plik

    return;
}

int main()
{
    while(true)
    {
        int choice;
        std::cout<<"Wybierz: "<<std::endl;
        std::cout<<"Zadanie 11.1. Bufor."<<std::endl
                <<"Zadanie 11.2. Sklepy."<<std::endl
                <<"Zadanie 11.3. Lista dwukierunkowa."<<std::endl;
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            zad3();
            break;

        case 2:
            zad2();
            break;

        case 3:
            zad1();
            break;
        }
    }
}
