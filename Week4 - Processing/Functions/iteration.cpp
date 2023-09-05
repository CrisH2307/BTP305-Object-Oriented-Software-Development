// Recursive Functions
// iteration.cpp

#include <iostream>

unsigned factorial(unsigned x)
{
    unsigned result = 1u;
    while (x > 1u)
        result = result * x--;
    return result;
}

int main ()
{
    std::cout << "2! = " << factorial(2) << std::endl;      // 2! = 2
    std::cout << "3! = " << factorial(3) << std::endl;      // 3! = 6
    std::cout << "4! = " << factorial(4) << std::endl;      // 4! = 24
}