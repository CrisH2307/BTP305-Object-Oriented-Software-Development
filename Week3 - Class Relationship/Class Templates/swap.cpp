// Function Template
// swap.cpp

#include <iostream>
#include "swap.h"

int main(int argc, char* argv[])
{
    if (argc > 4)
    {
        double a = atof(argv[1]);
        double b = atof(argv[2]);
        long   d = atol(argv[3]);
        long   e = atol(argv[4]);

        swap(a, b);

        std::cout << "Swapped values are " <<  a << " and " << b << std::endl;

        swap(d, e);

        std::cout << "Swapped values are " << d << " and " << e << std::endl;
    }
}

/*
Input
> swap 2.3 4.5 78 567

Output
Swapped values are 4.5 and 2.3
Swapped values are 567 and 78
*/