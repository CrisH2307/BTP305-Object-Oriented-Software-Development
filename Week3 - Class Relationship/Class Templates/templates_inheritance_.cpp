// Templates and Inheritance
// templates_inheritance_.cpp

#include "templates_inheritance.h"

int main()
{
    Derived<int, double> d(4);
    d.set(12);
    d.display();
}