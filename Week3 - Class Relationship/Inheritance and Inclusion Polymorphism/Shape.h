 #ifndef SHAPE_H  //! THIS IS AN ABSTRACT CLASS
 #define SHAPE_H
 // A Shape
 // Shape.h

 class Shape {
   public:
     virtual double volume() const = 0; 
     virtual Shape* clone()  const = 0;  //! Each query creates a copy of the object by calling the copy constructor for its own class' dynamic type.
     virtual bool operator==(const Shape&) const = 0; 
     virtual void display() const = 0;
 };
 #endif