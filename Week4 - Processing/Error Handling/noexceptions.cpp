// No Exceptions - compile on GCC
// noexceptions.cpp

/*
_ If a function marked noexcept allows an uncaught exception to escape at runtime
the program terminates immediately.
_ g() calls e(), which calls d(), which throws an exception. e() catches this exception 
and terminates normally. h() calls f(), which throws an exception. Since this exception 
is not caught before control reverts to h() and h() has been marked as a function that 
will not throw an exception; execution terminates abnormally at this point.
*/

#include <iostream>

void d() { throw "d() throws\n"; }
void e()
{
    try
    {
        d();
    }
    catch(const char* msg)
    {
        std::cout << msg;
    }
}
void f() { throw "f() throws\n"; }
void g() noexcept { e(); }
void h() noexcept { f(); }

int main()
{
    std::cout << "Calling g:";
    g();
    std::cout << "Calling h:";
    h();
    std::cout << "Normal exit\n";
}

/*
Output: 

Calling g: d() throws
Calling h:

*/