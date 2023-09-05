// Function Linkage - Main Module
// linkage_a.cpp

#include <iostream>

static void display()  // internal linkage
{
    std::cout << "in module a\n";
}

void module_b(); // external linkage

int main() // external linkage
{
    display();          // in module a
    module_b();         // in module b

}

