#include "bufferarr.h"

using namespace std;


BufferArr::BufferArr(size_t size) : size(size), count(0)
{
    arr = new int[size];
    cout << "Konstruktor klasy BufferArr" << endl;
};

BufferArr::~BufferArr()
{
    delete[] arr; // Zwalnianie pamięci
    cout << "Destruktor klasy BufferArr" << endl;
}

void BufferArr::add(int a)
{
    if (count < size)
    {
        arr[count++] = a;
    }
    else
    {
        cout << "Tablica jest pelna, nie mozna dodac elementu: " << a << endl;
    }
}

void BufferArr::write()
{
    cout << "Elementy w BufferArr: ";
    for (size_t i = 0; i < count; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
