//! CLASS TEMPLATES 
/*
_ Model polymorphic behavior using templates(generics)
_ Specialize a template for a particular type

Three categories of Polymorphism by ad-hoc, inclusion and parametic. The structure of each templated class
of function is independent of the type(s) involved. By defining that structure in a feneric form we can 
reduce code duplication significantly
*/

//* Template Syntax
/*
A template defines one of the following
+ A family of functions, classes or nested classes
+ A family of member functions, member classes, member enumerations or variables
+ An alias to a family of types

            template < template-parameter-list > // template header
            return-type function-name( ... )
            {
                / template body for a family of functions
                / ...
            }

            template < template-parameter-list > // template header
            class-key Class-name
            {
                / template body for a family of classes
                / ...
            };

            template < template-parameter-list > // template header
            type variable_name; // template body for a family of variables
_ The template parameter list consists of a comma-separated set of template parameters
*/

//* Template Parameters
/*
A template parameter may be:

1. A type template parameter
_ A type template parameter declaration takes the form
    typename identifier[=default]
    class identifier[=default]

+ typename keyword identifies a template type.
+ class keyword is an alternatice identifier for a template type.
+ identifier is a placeholder for the parameter type throughout the template body
+ default is an optional default value for the parameter type.
+ [] identifies an optional element
_ An argument corresponding to a type template parameter in a template instantiation should be a recognized type

2. A non-type template parameter
_ A template parameter that is not a placeholder for a type. That is, its type is declared explicitly.
A non-type template parameter declaration takes the form
    type identifier[=default]

_ A non-type template parameter may be one of the following types
    + An integral or enumeration type - a non-floating-point fundamental type
    + A ptr to a obj or a function
    + an lvalue reference to an obj or a function
    + A ptr to a member 
    + std::nullptr_t
    + auto
_ An argument corresponding to a non-type template parameter in a templated instantiation should be a 
constant or constant expression

3. A template template parameter
_ A template that is a placeholder for a template. The declaration of a template template param takes the form
    template< parameter-list > typename identifier[=default]
    template< parameter-list > class identifier[=default]
*/


//! Template Body
/*
Using the parameter names declared in the template header. The identifiers serve as placeholders throughout the template
body for the arguments specified in the templete instantiation. For every instantiation, the compiler generates code
in which it replaces the placeholders with the arguments specified in the instantiation
*/

#include <iostream>

template <typename T> // template header
// T is a type template parameter. The compiler replaces T with the type speicfied in the instantiation
// A template identifier or name has linkage. A non-member function template can have internal linkage. 
// Any other template name has external linkage.
void foo()
{
    T value;
    value = 1.5;
    std::cout << value << '\n';
}

int main()
{                                                   //Output
    foo<int>();    // template instantiation            1
    foo<double>(); // template instantiation            1.5
}


//! Specialization
/*
A template specialization of a function defines an exception to a template definition of that function
*/

//! Class Templates
/*
A template declaration for a family of classes follows the same rules as a template declaration for a family of functions.
*/

//! Template and Inheritance
/*
A class can be derived directly from a templated family of classes. All the usual rules of inheritance and polymorphism apply
*/

//! Variadic Templates
/*
A templete that accepts an arbitrary number of arguments is called a varadic template. A declaration of a variadic
template includes a parameter-pack as one of its parameters. An ellipsis to the left of the parameter name identifies
a parameter-pack. A parameter-pack is either a template parameter-pack or a function parameter-pack

            template <typename T, typename... parameter-pack>
            class Variadic;

All of the following are valid instantiations of this class template:
            Variadic<double> a;                      // 1 argument (minimum)
            Variadic<double, int> b;                 // 2 arguments
            Variadic<double, int, int> c;            // 3 arguments
            Variadic<double, double, int, double> d; // 4 arguments

Variadic templates are used with inheritance hierarchies
            template <typename... BaseClasses>
            class Variadic : public BaseClasses...
            {

            };

and with initialization lists
            template <typename... TT>
            void foo(TT... args)
            {
                const int size = sizeof...(args) + 1; // number of arguments + 1
                int x[size] = {args..., 0};
                // ...
            };

An ellipsis to the right of the parameter name identifies a pack-expansion. 
A pack-expansion consists of a pattern and an ellipsis
*/