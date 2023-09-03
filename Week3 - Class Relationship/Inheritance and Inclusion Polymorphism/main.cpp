//* INHERITANCE AND INCLUSION POLYMORPHISM
/*
Inheritance: A relationship between user-defined types
    + Concrete: Their representation is part of their definition and is known
    + Abstract: Their representation is not part of their definition and is unknown

_ Abstract class can serve as an interface to an inheritance hierachy. It is an 
incomplete class that cant create an instance of an abstract class. We complete its
implementation by deriving a new class that adds the missing definition. Completed class
is a concrete class
_ To instantiate an Abstract obj, we need to define a function that returns its volume. 
By deriving a concrete class from the Abstract class.

Polymorphic Objs: Is an obj that can have different dynamic types throughout its lifetime
Copying Operation: Copying a ploymorphic obj at run-time requires knowledge of its dynamic type.
In order to allocate memory for the copy, the executable needs to know the dynamic type.
Specializing an Operation: In expressions that involve operands of polymorphic type, the operator
functions require knowledge of the received obj's dynamic type. A dynamic cast returns this type

Liskov Substitution Principle:
_ Some confusion can arise in distinguishing type from subtypes in inheritance hierachies.
_ This principle provides guidance that avoids design ambiguity.
_ A function that uses ptrs or references to base classes must be able to use objs of derived classes without knowing it

*/
  

// Shape Hierarchy
 // Shape.cpp

 #include <iostream>
 #include "Cube.h"
 #include "Sphere.h"

 void displayVolume(const Shape* shape) {
     if (shape)
         std::cout << shape->volume() << std::endl; 
     else
         std::cout << "error" << std::endl;
 }

 Shape* select() {
     Shape* shape;
     double x;
     char c;
     std::cout << "s (sphere), c (cube) : ";
     std::cin >> c;
     if (c == 's') {
         std::cout << "dimension : ";
         std::cin >> x;
         shape = new Sphere(x);
     } else if (c == 'c') {
         std::cout << "dimension : ";
         std::cin >> x;
         shape = new Cube(x);
     } else
         shape = nullptr;
     return shape;
 }

 int main() {
     Shape* shape = select();
     displayVolume(shape);
     delete shape;
 }

 /* 
 Output
 
 First run :
 -----------
 s (sphere), c (cube) : s

 dimension : 1

 4.18879


 Second run :
 ------------
 s (sphere), c (cube) : c 

 dimension : 2

 8

 Third run :
 -----------
 s (sphere), c (cube) : d

 error
 
 */