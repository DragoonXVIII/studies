#ifndef PRINT_H
#define PRINT_H

#include <iostream>

class Print
{
public:

    template <typename T>

    void operator()(T t)
    {
        std::cout << t <<std::endl;
    }
};

#endif // PRINT_H
