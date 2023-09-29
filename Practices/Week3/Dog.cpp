#include <iostream>
#include "Animal.h"
#include "Dog.h"
using namespace std;

void Dog::move()
{
    cout << m_name << "The dog is moving \n";
}

void Dog::eat()
{
    cout << m_name << " should not eat. Too fat \n";
}