#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr)
{
    cout << "Konstruktor DoublyLinkedList" << endl;
}

DoublyLinkedList::~DoublyLinkedList()
{
    cout << "Destruktor DoublyLinkedList" << endl;
    while (!isEmpty())
    {
        removeFront(); //usuwanie frontu uwala reszte wsm troche logiczne
    }
}

bool DoublyLinkedList::isEmpty() const
{
    return head == nullptr;
}

void DoublyLinkedList::addFront(int value)
{
    auto newNode = make_shared<Node>(value);
    if (isEmpty())
    {
        head = tail = newNode; // pierwszy i git
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void DoublyLinkedList::addBack(int value)
{
    auto newNode = make_shared<Node>(value);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::removeFront()
{
    if (isEmpty())
    {
        cout << "Lista jest pusta, nie mozna usunac elementu." << endl;
        return;
    }
    cout << "Usunieto z przodu: " << head->data << endl;
    head = head->next;
    if (head)
    {
        head->prev.reset();
    }
    else
    {
        tail.reset();
    }
}

void DoublyLinkedList::removeBack()
{
    if (isEmpty())
    {
        cout << "Lista jest pusta, nie mozna usunac elementu." << endl;
        return;
    }
    cout << "Usunieto z tylu: " << tail->data << endl;
    tail = tail->prev.lock();
    if (tail)
    {
        tail->next.reset();
    }
    else
    {
        head.reset();
    }
}

void DoublyLinkedList::display() const
{
    if (isEmpty())
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    cout << "Zawartosc listy: ";
    shared_ptr<Node> current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
