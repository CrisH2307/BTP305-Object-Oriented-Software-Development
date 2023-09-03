// Liskov Substitution Principle - Square from Rectangle
 // liskov_square__.cpp
 #include <iostream>

 class Rectangle {
     double width;
     double height;
   public:
     virtual void setWidth(double w)  { width = w; }
     virtual void setHeight(double h) { height = h; }
     double getWidth() const  { return width; }
     double getHeight() const { return height; }
 };

 class Square : public Rectangle {
   public:
     void setWidth(double s) {
         Rectangle::setWidth(s);
         Rectangle::setHeight(s);
     }
     void setHeight(double s) {
         Rectangle::setWidth(s);
         Rectangle::setHeight(s);
     }
 };

 void set(Rectangle& r) {
     r.setWidth(3);
     r.setHeight(4);
     if(r.getWidth() * r.getHeight() != 12)
         std::cerr << "* volume isn\'t 12 *\n";
 }

 int main() {
     Square s;
     s.setWidth(20.0);
     std::cout << "Square : " << s.getWidth() << std::endl;
     Rectangle r;
     r.setWidth(10.0);
     r.setHeight(30.0);
     std::cout << "Rectangle : " << r.getWidth()
      << ", " << r.getHeight() << std::endl;
     set(s);
     std::cout << "Square : " << s.getWidth() << std::endl; 
     set(r);
     std::cout << "Rectangle : " << r.getWidth()
      << ", " << r.getHeight() << std::endl;
 }