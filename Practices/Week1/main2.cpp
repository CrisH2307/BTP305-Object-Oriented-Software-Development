#include <iostream>
#include "ultils.h"
using namespace std;

extern int g_secret;
// The result of the expression can be known at compile time fot at least some params
constexpr int getSize(int seed)
{
    return 2 * seed;
}

//void sayHello();

int main(int argc, char** argv)
{
    sayHello();


    int size = -1;

    cout << "Size? ";
    cin >> size;

    const int SIZE = size;  // cant change
    constexpr int CE_SIZE = 10; // a constant + value must be known as compile time

    int arr[getSize(CE_SIZE)];  // size must be const, not change 
                    // know at compile time

    return 0;
}
