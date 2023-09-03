// Composition - Pointer Version
// Person-pointer.h

#include "Name.h"

class Person
{
    Name* name { nullptr }; // pointer
    int age;
public:
    Person(const char*, int);

    // special functions to manage the resource
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    void display() const;
    void set(const char*);
    //...
};