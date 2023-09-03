//* LINKAGE
/*
The notion of Linkage is somewhat as it sounds, it is the idea of whether or not a identifier
or name refers to another identical name in another scope 
+ External: Where two connected names are in different scopes in different modules
    _ Imagine two neighbor farms that share butter with each other.
      While they're not the same plot of land, the butter is linked
    _ To enable extern linkage, we can use extern keywoed
    Module A: int shared_int = 0;
        |
    Module B: extern shared_int;


+ Internal: Where two connected names are in different scopes in the same modules
    _ Imagine two households where the family members share a house key.
      This is only for those in their family
    _ Enabling internal means that a given identifier will become invisible outside
      of its own translation but will be visible to only those within
    _ Using static before an identifier
    Module A: static int shared_int = 0;
        |
    Module B: static int shared_int;

_ Anonymous Namespaces: Similar to internal linkage, it offer another method of localizing
an entity to only one translation unit/module using 'namespace'

_ Main program 
+ The entry point to C++ programs is the main() function and the form we've mostly used up
to this point, default main with no argument, returns an int
    int main(){
        return 0;
    }

+ There is a secondary form(overload) that takes in two parameters and with these parameters 
allows us to make use of command-line argiments with our program:
    int main (int argc, char* argv[])
    {
        return 0;
    }

    (int argc, char* argv[])
    + The first param argc here is an int that represents the num or arguments passed to the program
    + The second param argv is an array of character ptrs that represent the actual arguments themselves

_ Compile Time Evaluations - Constant Expressions:
+ Constant expressions are much like what they sound like in the they're expressions that the
compiler can evaluate at compile-time
+ Using constexpr to indicate that this entity should be evaluated at compilet-time
+ constexpt can be applied to both variables and functions to establish constant variables and constant functions

_ Lifetime in Memory
+ Automatic: Lasts from its declaration till the end of the scope - no keyword used(default)
+ Dynamic: Create using 'new' keyboard - lasts until deallocated using the 'delete' keyword 
+ Thread: Lasts in life time of thread - uses 'thread_local' keyword
+ Static: lasts the entire lifetime of the program - use 'static'
*/


#include <iostream>

using namespace std;

constexpr int x = 10;

constexpr long int sumUp(long int x)
{
    if (x > 0)
    {
        return x + sumUp(x - 1);
    }
    return 0;
}

int main()
{

}