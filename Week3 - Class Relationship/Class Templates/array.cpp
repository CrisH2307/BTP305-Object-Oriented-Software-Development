// Class Template
// array.cpp

#include <iostream>
#include "array.h"

int main()
{
    Array<long> a, b;

    for (int i = 0; i < 5; i++)
        a[i] = i * i;

    b = a;

    for (int i = 0; i < 5; i++)
        std::cout << b[i] << ' ';
    std::cout << std::endl;
}
// Output: 0 1 4 9 16