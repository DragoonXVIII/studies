#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>

using namespace std;

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

#endif // NODE_H
