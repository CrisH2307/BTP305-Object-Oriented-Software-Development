#include <iostream>
#include "Animal.h"
#include "Dog.h"
using namespace std;

int main()
{
    Animal* fuck = new Dog;
    fuck->move();
    fuck->eat();
}