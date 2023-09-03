// Composition
// composition.cpp

#include "person-pointer.h"

int main()
{
    Person p("Harvey", 23);
    Person q = p;
    p.display();
    q.display();

    q.set("Lawrence");
    p.display();
    q.display();

    p = q;
    p.display();
}

/*
Output
23 Harvey
23 Harvey

23 Harvey
23 Lawrence

23 Lawrence
*/