// Liskov Substitution Principle
 // liskov_square.cpp
 #include <iostream>

/*
The classical example involves a square and a rectangle. Each is a kind of the other, but only one 
design ensures substitutability. That is, a rectangle is less abstract than a square: a rectangle 
should be derived from a square, since the rectangle adds a new measurement.
*/

 class Square {
     double width;
   public:
     void setWidth(double w) { width = w; }
     double getWidth() const { return width; }
 };

 void set(Square& s, double d) {
     s.setWidth(d);
 }

 int main() {
     Square s;
     s.setWidth(20.0);
     std::cout << "Square : " << s.getWidth() << std::endl; 
     set(s, 15.0);
     std::cout << "Square : " << s.getWidth() << std::endl;
 }