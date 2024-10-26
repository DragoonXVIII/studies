#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>


using namespace std;

class Buffer
{
public:
    Buffer()
    {
        cout << "Konstruktor Buffer" << endl;
    }
    virtual ~Buffer()
    {
        cout << "Destruktor Buffer" << endl;
    }
    virtual void add(int a) = 0;
    virtual void write() = 0;
};

#endif // BUFFER_H
