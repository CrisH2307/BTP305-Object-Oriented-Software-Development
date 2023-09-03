// Templates and Inheritance
// templates_inheritance_.h
#include <iostream>

template<typename T>
class Base
{
    T value;
public:
    void set(const T& v) { value = v; }
    void display() const { std::cout << value << std::endl; }
};

template<typename S, typename T>
class Derived : public Base<T>
{
    S value;
public:
    Derived(const S& v) : value{v}{}
    void set(const T& v) { Base<T>::set(v + value); }
};