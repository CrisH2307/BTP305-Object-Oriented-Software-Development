// Indirection
// indirection.cpp

#include <iostream>
#include <iomanip>

int main()
{
    int x = 3;
    int* p = &x;
    std::cout << x << std::setw(11) << p << std::endl;

    *&x = 4;
    std::cout << x << std::setw(11) << p << std::endl;
}

/*
Output:
3   002BF824
4   002BF824
*/