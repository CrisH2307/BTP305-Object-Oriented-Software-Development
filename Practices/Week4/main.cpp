#include <iostream>

using namespace std;

/*
 Inheritance: Strongest classes relation  ("is-a"/"is a-kind-of")
 Composition: ("has-a")- Complete ownership. The composer is responsible for 
 life management of the owned obj
 Aggregation: ("has-a" )- Ownership, partial ownership, no life management
 Association: ("Uses-a")- No ownership, some dependency

Ex:
A college has departments, and each department has a number of professors. 
Professors come by bus at work.

College - Department: Composition (Responsible together)
Department - Professors: Aggregation (It need Professors, Department cant do anything to prof)
Professors - Bus: Association (They dont responsible, they can achieve without each other)

Ex2:
Compostion: Mom and Dad 'work' together to give birth
Aggregation: We cant 'deallocate' when we cant see a toilet
Association: Me and my EX (We dont give a fuck)
*/
class Foo
{

};

class Bar : public Foo //Inheritance
{
    Foo* aFoo;  // Composition
public:
    Bar(Foo* p)   // Composition, responsible for life management
    {
        aFoo = new Foo(*p); // This is life management
        aFoo = p;  // Bar take complete ownership
    }
    ~Bar()
    {
        delete aFoo;
    }
    void display(std::ostream& oo)  //Association, no ownership, no life management
    {
        oo << "Lo con cac";
    }

};

int main()
{

}