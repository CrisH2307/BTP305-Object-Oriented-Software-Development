// Recursive Functions
// fibonacci.cpp

#include <iostream>

unsigned factorial(unsigned x)
{
    return (x > 2u) ? x * factorial(x - 1) : x;
}

int main ()
{
    std::cout << "2! = " << factorial(2) << std::endl;      // 2! = 2
    std::cout << "3! = " << factorial(3) << std::endl;      // 3! = 6
    std::cout << "4! = " << factorial(4) << std::endl;      // 4! = 24
}