#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <memory>

#include "node.h"

using namespace std;

class DoublyLinkedList
{
private:
    shared_ptr<Node> head;        // pierwszy node węzła
    shared_ptr<Node> tail;        // last node (wsm kod 1:1 z algorytmow w cpp z drugiego semu)

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty() const;
    //dodaj na poczatek
    void addFront(int value);
    // dodaj na koniec
    void addBack(int value);
    // usun poczatek
    void removeFront();
    // usun koniec
    void removeBack();
    void display() const;
};

#endif // DOUBLYLINKEDLIST_H
