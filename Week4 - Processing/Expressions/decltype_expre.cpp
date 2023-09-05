// decltype with expressions
// decltype_expre.cpp

#include <iostream>

int main()
{
    int i = 3, j = 6;
    double x = 4.5;
    double& r = x;

    decltype(i + j) y = i + j; // int y
    decltype(i + x) z = i + x; // double z
    decltype(r) s = r;         // double& s

    std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::cout << s << std::endl;
}

/*
Output:
9
7.5
4.5

*/