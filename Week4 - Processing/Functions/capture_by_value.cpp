// Lambda Expressions
// capture_by_value.cpp

#include <iostream>

template<typename Func>
int add(int i, Func func)
{
    return func(i);
}

template<typename Func>
int sub(int i, Func func)
{
    return func(i);
}

int main()
{
    int k = 4;
    std::cout << add(10, [=](int i){ return i + k; }) << std::endl;
    std::cout << sub(10, [=](int i){ return i - k; }) << std::endl;
}
/*

Output:

14
6


*/