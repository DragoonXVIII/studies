#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


struct Element
{
    int number;
    Element* next;
};


struct SingleList
{
    Element* head;
    Element* tail;
    int counter;
};


SingleList l;


bool isEmpty()
{
    return l.head == nullptr;
}

void addTail(int value)
{
    Element* el = new Element;
    el->number = value;
    el->next = nullptr;
    if(isEmpty())
    {
        l.head = el;
        l.tail = el;
    }
    else
    {
        l.tail->next = el;
        l.tail = el;
    }
    l.counter++;
}

void addHead(int value)
{
    Element* el = new Element;
    el->number = value;
    el->next = l.head;
    l.head = el;
    if(isEmpty())
    {
        l.tail = el;
    }
    l.counter++;
}

void addPosition(int value, int position)
{
    if(position<0 || position>l.counter)
    {
        cout << "Invalid position." << endl;
        return;
    }
    if(position == 0)
    {
        addHead(value);
        return;
    }
    if(position == l.counter)
    {
        addTail(value);
        return;
    }
    Element* el = new Element;
    el->number = value;
    Element* temp = l.head;
    for(int i=0; i<position-1; i++)
    {
        temp = temp->next;
    }
    el->next = temp->next;
    temp->next = el;
    l.counter++;
}

void deleteTail()
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if(l.counter == 1)
    {
        delete l.tail;
        l.head = nullptr;
        l.tail = nullptr;
    }
    else
    {
        Element* prev = l.head;
        while(prev->next != l.tail)
        {
            prev = prev->next;
        }
        delete l.tail;
        prev->next = nullptr;
        l.tail = prev;
    }
    l.counter--;
}

void deleteHead()
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    Element* temp = l.head;
    l.head = l.head->next;
    delete temp;
    if(l.counter == 1)
    {
        l.tail = nullptr;
    }
    l.counter--;
}

void deletePosition(int position)
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    if(position < 0 || position >= l.counter)
    {
        cout << "Invalid position." << endl;
        return;
    }
    if(position == 0)
    {
        deleteHead();
        return;
    }
    if(position == l.counter - 1)
    {
        deleteTail();
        return;
    }
    Element* prev = l.head;
    for (int i = 0; i < position - 1; i++)
    {
        prev = prev->next;
    }
    Element* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    l.counter--;
}

int getFirstElement()
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return -1;
    }
    return l.head->number;
}

int getLastElement()
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return -1;
    }
    return l.tail->number;
}

float calculateAverage()
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return 0.0f;
    }
    int sum = 0;
    Element* temp = l.head;
    while(temp != nullptr)
    {
        sum += temp->number;
        temp = temp->next;
    }
    return static_cast<float>(sum)/l.counter;
}

void findMaxElement()
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    Element* temp = l.head;
    int maxElement = temp->number;
    int position = 0;
    int maxPosition = 0;
    while(temp != nullptr)
    {
        if (temp->number > maxElement)
        {
            maxElement = temp->number;
            maxPosition = position;
        }
        temp = temp->next;
        position++;
    }
    cout << "Max element: " << maxElement << " at position: " << maxPosition << endl;
}

void displayList()
{
    if(isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    Element* temp = l.head;
    while(temp != nullptr)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}

void clearList()
{
    while(!isEmpty())
    {
        deleteHead();
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    int choice;
    do
    {
        cout << "1. Check if the list is empty" << endl;
        cout << "2. Add an element at the end" << endl;
        cout << "3. Add an element at the beginning" << endl;
        cout << "4. Add an element at a specified position" << endl;
        cout << "5. Delete the last element" << endl;
        cout << "6. Delete the first element" << endl;
        cout << "7. Delete an element at a specified position" << endl;
        cout << "8. Get the first element" << endl;
        cout << "9. Get the last element" << endl;
        cout << "10. Calculate the average" << endl;
        cout << "11. Find the maximum element" << endl;
        cout << "12. Display the entire list" << endl;
        cout << "13. Clear the list" << endl;
        cout << "14. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            if(isEmpty())
            {
                cout << "List is empty." << endl;
            }
            else
            {
                cout << "List is not empty." << endl;
            }
            break;

        case 2:
        {
            int value = rand() % 50 + 1;
            addTail(value);
            cout << "Added element " << value << " at the end of the list." << endl;
            break;
        }

        case 3:
        {
            int value = rand() % 50 + 1;
            addHead(value);
            cout << "Added element " << value << " at the beginning of the list." << endl;
            break;
        }

        case 4:
        {
            int value, position;
            cout << "Enter the value: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> position;
            addPosition(value, position);
            cout << "Added element " << value << " at position " << position << " in the list." << endl;
            break;
        }

        case 5:
            deleteTail();
            cout << "Deleted the last element from the list." << endl;
            break;

        case 6:
            deleteHead();
            cout << "Deleted the first element from the list." << endl;
            break;

        case 7:
        {
            int position;
            cout << "Enter the position: ";
            cin >> position;
            deletePosition(position);
            cout << "Deleted element at position " << position << " from the list." << endl;
            break;
        }

        case 8:
            cout << "First element: " << getFirstElement() << endl;
            break;

        case 9:
            cout << "Last element: " << getLastElement() << endl;
            break;

        case 10:
            cout << "Average: " << calculateAverage() << endl;
            break;

        case 11:
            findMaxElement();
            break;

        case 12:
            cout << "List: ";
            displayList();
            break;

        case 13:
            clearList();
            cout << "List cleared." << endl;
            break;

        case 14:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;

        }
        cout << endl;

    }while(choice!=14);
    return 0;
}


/*
 * #include <iostream>
using namespace std;

struct Element {
    int number;
    Element* next;
};

struct SingleList {
    Element* head;
    Element* tail;
    int counter;
};

SingleList l;

void add_tail(SingleList& l, int value) {
    Element* el = new Element;
    el->number = value;
    el->next = nullptr;
    if (l.tail != nullptr) {
        l.tail->next = el;
    }
    else {
        l.head = el;
    }
    l.tail = el;
    l.counter++;
}

void add_head(SingleList& l, int value) {
    Element* el = new Element;
    el->number = value;
    el->next = l.head;
    l.head = el;
    if (l.tail == nullptr) {
        l.tail = el;
    }
    l.counter++;
}

void add_position(SingleList& l, int value, int position) {
    if (position <= 0 || position > l.counter + 1) {
        cout << "Nieprawidlowa pozycja." << endl;
        return;
    }

    if (position == 1) {
        add_head(l, value);
        return;
    }

    if (position == l.counter + 1) {
        add_tail(l, value);
        return;
    }

    Element* el = new Element;
    el->number = value;
    Element* temp = l.head;
    int i = 1;
    while (i < position - 1) {
        temp = temp->next;
        i++;
    }
    el->next = temp->next;
    temp->next = el;
    l.counter++;
}

void delete_tail(SingleList& l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    Element* temp = l.tail;
    if (l.counter == 1) {
        l.head = nullptr;
        l.tail = nullptr;
    }
    else {
        Element* bef_temp = l.head;
        int i = 1;
        while (i < l.counter - 1) {
            bef_temp = bef_temp->next;
            i++;
        }
        l.tail = bef_temp;
        l.tail->next = nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(SingleList& l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    Element* temp = l.head;
    l.head = l.head->next;
    if (l.counter == 1) {
        l.tail = nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(SingleList& l, int position) {
    if (position <= 0 || position > l.counter) {
        cout << "Nieprawidlowa pozycja." << endl;
        return;
    }

    if (position == 1) {
        delete_head(l);
        return;
    }

    if (position == l.counter) {
        delete_tail(l);
        return;
    }

    Element* prev = l.head;
    Element* temp;
    int i = 1;
    while (i < position - 1) {
        prev = prev->next;
        i++;
    }
    temp = prev->next;
    prev->next = temp->next;
    delete temp;
    l.counter--;
}

void show_first(SingleList l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    cout << "Pierwszy element: " << l.head->number << endl;
}

void show_last(SingleList l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    cout << "Ostatni element: " << l.tail->number << endl;
}

float calculate_average(SingleList l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return 0.0f;
    }

    int sum = 0;
    Element* temp = l.head;
    while (temp != nullptr) {
        sum += temp->number;
        temp = temp->next;
    }
    float average = static_cast<float>(sum) / l.counter;
    return average;
}

void find_max_element(SingleList l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    int max = l.head->number;
    int position = 1;
    int i = 2;
    Element* temp = l.head->next;
    while (temp != nullptr) {
        if (temp->number > max) {
            max = temp->number;
            position = i;
        }
        temp = temp->next;
        i++;
    }
    cout << "Najwiekszy element: " << max << " (pozycja: " << position << ")" << endl;
}

void display_list(SingleList l) {
    if (l.counter == 0) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    Element* temp = l.head;
    cout << "Lista: ";
    while (temp != nullptr) {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_list(SingleList& l) {
    Element* temp = l.head;
    while (temp != nullptr) {
        Element* next = temp->next;
        delete temp;
        temp = next;
    }
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;
}

int main() {
    int zmiana = 0;
    do {
        cout << "\n1. Sprawdzenie czy lista jest pusta" << endl;
        cout << "2. Dodanie na koniec" << endl;
        cout << "3. Dodanie na poczatek" << endl;
        cout << "4. Dodanie na okreslona pozycje" << endl;
        cout << "5. Usuwanie konca" << endl;
        cout << "6. Usuwanie poczatku" << endl;
        cout << "7. Usuwanie okreslonej pozycji" << endl;
        cout << "8. Wyswietlenie pierwszego" << endl;
        cout << "9. Wyswietlenie ostatniego" << endl;
        cout << "10. Srednia arytmetyczna" << endl;
        cout << "11. Element maksymalny" << endl;
        cout << "12. Wyswietlenie calej listy" << endl;
        cout << "13. Usuniecie calej listy" << endl;
        cout << "14. Wyjscie\n" << endl;
        cin >> zmiana;
        cout << "" << endl;
        switch (zmiana) {
            case 1:
                if (l.head == nullptr) {
                    cout << "Lista jest pusta." << endl;
                }
                else {
                    cout << "Lista nie jest pusta." << endl;
                }
                break;
            case 2:
                int value;
                cout << "Podaj liczbe do dodania na koniec listy: ";
                cin >> value;
                add_tail(l, value);
                break;
            case 3:
                cout << "Podaj liczbe do dodania na poczatek listy: ";
                cin >> value;
                add_head(l, value);
                break;
            case 4:
                int position;
                cout << "Podaj liczbe do dodania: ";
                cin >> value;
                cout << "Podaj pozycje: ";
                cin >> position;
                add_position(l, value, position);
                break;
            case 5:
                delete_tail(l);
                break;
            case 6:
                delete_head(l);
                break;
            case 7:
                cout << "Podaj pozycje elementu do usuniecia: ";
                cin >> position;
                delete_position(l, position);
                break;
            case 8:
                show_first(l);
                break;
            case 9:
                show_last(l);
                break;
            case 10:
                cout << "Srednia arytmetyczna: " << calculate_average(l) << endl;
                break;
            case 11:
                find_max_element(l);
                break;
            case 12:
                display_list(l);
                break;
            case 13:
                delete_list(l);
                break;
            case 14:
                // Wyjscie z programu
                break;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                break;
        }
    } while (zmiana != 14);

    return 0;
}
*/
