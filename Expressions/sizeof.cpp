// Size of a Type
// sizeof.cpp

#include <iostream>

int main()
{
    double x;

    std::cout << "On this machine, \n"
                 "the size of an int is " << sizeof(int)
              << "bytes,\nthe size of x is "
              << sizeof x << "bytes" << std::endl;
}

/*
Output:
On this machine,
the size of an int is 4 bytes,
the size of x is 8 bytes.
*/