// Resolving Ambiguities
// ambiguities.cpp

/*
If the arguments in a function call are ambiguous in type, the compiler requires an explicit 
specification of the type for which to generate the definition. We specify the type explicitly
before the opening parenthesis of the function call
*/
#include <iostream>
#include "swap.h"
#include "maximum.h"

int main(int argc, char* argv[])
{
    if (argc > 4)
    {
        double a = atof(argv[1]);
        double b = atof(argv[2]);
        float  d = atof(argv[3]);
        float  e = atof(argv[4]);

        double c = maximum<double>(a, d);

        std::cout << "Greater of " << a << ", " << d << " is " << c << std::endl;

        float f = maximum<float>(b, e);

        std::cout << "Greater of " << b << ", " << e << " is " << f << std::endl;
    }
}

/*
Input
>ambiguities 2.3 4.5 3.4 2.1

Output
Greater of 2.3, 3.4 is 3.4
Greater of 4.5, 2.1 is 4.5
*/