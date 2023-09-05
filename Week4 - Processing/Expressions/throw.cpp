// Throw Operator
// throw.cpp

#include <iostream>

int divide(int x, int y)
{
    if (y == 0)
        throw "divide by zero inadmissible";
    else
        return x / y;
}

int main ()
{
    int dividend, divisor, quotient = 0;

    std::cout << "Enter dividend : ";
    std::cin >> dividend;
    std::cout << "Enter divisor  : ";
    std::cin >> divisor;

    //... execute function successfully or throw exception

    quotient = divide(dividend, divisor);

    // ... handle exception

    std::cout << "Quotient = " << quotient << std::endl;
}