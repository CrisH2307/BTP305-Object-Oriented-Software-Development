// Exception Handling
// exceptions.cpp

/*
_ In the following example, the divide() function identifies two possible exceptions to a normal simple 
division of an element in an array. The two catch blocks in the main() function handle these exceptions:
    + an array index that is out of bounds
    + an attempt to divide by zero

_ The code within the try block is executed statement by statement as long as an exception is not thrown. 
Once divide() throws an exception, control leaves the try block. The throw statement transfers control 
to the first catch block that receives the type thrown.
*/

#include <iostream>

void divide(double a[], int i, int n, double divisor)
{
    if(i < 0 || i >= n)
        throw "Outside bounds";
    else if(divisor == 0)
        throw divisor;
    else
        a[i] = i / divisor;
}

int main()
{
    bool keepdividing = true;
    double a[] = {1.1,2.2,3.3,4.4,5.5,6.6}, divisor;
    int i, n = sizeof a / sizeof a[0];

    do
    {
        try
        {
            std::cout << "Index: ";
            std::cin >> i;
            std::cout << "Divisor: ";
            std::cin >> divisor;
            divide(a, i, n, divisor);
            std::cout << "a[i] = " << a[i] << std::endl;
            std::cout << "Continuing ..." << std::endl;
        }
        catch(const char* msg)
        {
            std::cout << msg << std::endl;
            keepdividing = false;
        }
        catch(...)
        {
            std::cout << "Zero Division!" << std::endl;
            std::cout << "a[i] = " << a[i] << std::endl;
            std::cout << "Continuing ..." << std::endl;
        }
    }
    while (keepdividing);
}


/*

Output:

Index: 1
Divisor: -1
a[i] = -1
Continuing ...

Index: 4
Divisor: 2
a[i] = 2
Continuing ...

Index: 5
Divisor: 0
Zero Division!
a[i] = 6.6
Continuing ...

Index: 45
Divisor: 3
Outside bounds

*/