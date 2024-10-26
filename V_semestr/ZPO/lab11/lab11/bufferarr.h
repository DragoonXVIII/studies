#ifndef BUFFERARR_H
#define BUFFERARR_H

#include <iostream>

#include "buffer.h"

using namespace std;

class BufferArr : public Buffer
{
private:
    int* arr;
    size_t size;
    size_t count;

public:
    BufferArr(size_t size);
    ~BufferArr() override;

    void add(int a) override;
    void write() override;
};
#endif // BUFFERARR_H
