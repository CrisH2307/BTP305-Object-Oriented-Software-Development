// sizeof Operator
// sizeof2.cpp

#include <iostream>

int main()
{
    int j = 1;

    std::cout << sizeof j++ << std::endl;
    std::cout << j << std::endl; // j is still 1
}

/*
Output
4
1
*/