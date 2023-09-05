// Pre-Fix Operators
// prefix.cpp

#include <iostream>

int main()
{
    int i = 10;

    std::cout << ++i << std::endl;
    ++(++i);           // OK (++i) is an lvalue
    std::cout << i << std::endl;
}

/*
Output
11
13
*/