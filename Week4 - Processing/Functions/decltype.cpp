// decltype with templates
// decltype.cpp

/*
The trailing return type syntax is particularly useful with templated functions. 
In the following program, the return type of the function add() is unknown to 
the compiler when it starts processing the definition and is only known after the 
compiler has finished processing the parameter list (const T& t, const U& u). 
The return type is the type of the result of evaluating expression t + u. To obtain 
the type of this result, we use the decltype() specifier:
*/

#include <iostream>

template<typename T, typename U>
auto add(const T& t, const U& u) -> decltype(t + u)
{
    return t + u;
}

int main()
{
    int i = 3, j = 6;
    double x = 4.5;

    std::cout << add(i, j) << std::endl;
    std::cout << add(i, x) << std::endl;
}

/*
Output:

9
7.5


*/