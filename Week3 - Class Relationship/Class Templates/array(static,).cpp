// Static Data Member Declaration
// array.cpp

#include <iostream>
#include "array(static).h"

int main()
{
    Array<> s, t;
    Array<double> u;
    Array<int, 40> v;

    std::cout << Array<>::getCount()        << std::endl;                   //2
    std::cout << Array<double>::getCount()  << std::endl;                   //1
    std::cout << Array<int, 40>::getCount() << std::endl;                   //1
}