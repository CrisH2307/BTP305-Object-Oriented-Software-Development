// Post-Fix Operators
// postfix.cpp

#include <iostream>

int main()
{
    int i = 10;

    std::cout << i++ << std::endl;
   // (i++)++;           // ERROR (i++) is a prvalue, not an lvalue
    std::cout << i << std::endl;
}