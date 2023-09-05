// Post-Fix Operators on Unsigned Values
// unsigned.cpp

#include <iostream>

int main()
{
    unsigned i = 0u;

    i--;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;
}
/*
Output:
4294967295
0
*/