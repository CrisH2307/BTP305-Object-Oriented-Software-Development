// Arithmetic Negation
// minus.cpp

#include <iostream>
#include <iomanip>

int main()
{
    unsigned a = 2u;
    unsigned c = 1u;
    unsigned e = 0u;

    std::cout << a << std::setw(11) << -a << std::endl;
    std::cout << c << std::setw(11) << -c << std::endl;
    std::cout << e << std::setw(11) << -e << std::endl;
}

/* 
Output:

2 4294967294
1 4294967295
0          0


*/