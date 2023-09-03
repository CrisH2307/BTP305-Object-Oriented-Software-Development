// A Cube
 // Cube.cpp
 #include <iostream>
 #include "Cube.h"

 Cube::Cube(double l) : len{l} {}

 Shape* Cube::clone() const {
     return new Cube(*this);
 }
 double Cube::volume() const {
     return len * len * len;
 }

 void Cube::display() const {
     std::cout << "length = " <<
      len << std::endl; 
 }


bool Cube::operator==(const Shape& s) const {
     const Cube* c =
      dynamic_cast<const Cube*>(&s);
     return c ? len == c->len : false;
 }