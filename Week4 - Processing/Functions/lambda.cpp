// Lambda Expressions
// lambda.cpp

#include <iostream>

int main()
{
    // lambda expressions
    auto hello = []() { return "Hello World"; };
    auto add4  = [](int i) { return i + 4; };
    auto sub4  = [](int i) { return i - 4; };

    // calls on the lambda expressions
    std::cout << hello()  << std::endl;
    std::cout << add4(10) << std::endl;
    std::cout << sub4(10) << std::endl;
}

/* 

Output:

Hello World
14
6

*/