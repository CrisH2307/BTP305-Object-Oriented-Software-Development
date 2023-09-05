// Function Linkage - Module B
// linkage_b.cpp

#include <iostream>

static void display() // internal linkage
{
    std::cout << "in module b\n";
}

void module_b() // external linkage
{
    display();
}