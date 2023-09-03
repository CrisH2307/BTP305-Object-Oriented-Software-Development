// Template Specialization
// maximum_overload.cpp

#include <iostream>
#include "maximum.h"

const char* maximum(const char* a, const char* b)
{
    std::cout << "in overloaded function\n";
    return std::strcmp(a, b) > 0 ? a : b;
}

int main(int argc, char* argv[])
{
    if (argc > 4)
    {
        double a = atof(argv[1]);
        double b = atof(argv[2]);
        const char* d = argv[3];
        const char* e = argv[4];

        double c = maximum(a, b);

        std::cout << "Greater of " << a << ", " << b << " is " << c << std::endl;

        const char* f = maximum(d, e);

        std::cout << "Greater of " << d << ", " << e << " is " << f << std::endl;
    }
}

/*
Input
>maximum 2.3 4.5 abc def

Output
in template
Greater of 2.3, 4.5 is 4.5
in overloaded function
Greater of abc, def is def
*/