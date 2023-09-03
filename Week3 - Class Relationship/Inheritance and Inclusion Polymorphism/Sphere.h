 // A Sphere
 // Sphere.h

 #include "Shape.h"

 class Sphere : public Shape {
     double rad;
 public:
     Sphere(double);
     double volume() const;
     Shape* clone() const;
     void display() const;
     bool operator==(const Shape&) const;
 };