//! EXPRESSIONS
/*
+ Classify operations into categories under rules of precedence
+ Categorize expressions as lvalues, xvalues and prvalues
+ Describle the features of expressions for each type-wise operator

_ Expression specify computations. They consist of sequences of operators and operands and may
produce a result, possible with side effects.

                                        Operand
                                           |
    Expression   <--------- Operator <-----|----------- Operand
                                           |
                                         Operand
*/

//? Value Categories
/*
_ Are the basis for rules that compilers follow when creating, copying, and moving temporary objs
during the evaluation of expressions.
+ prvalue - a value that does not occupy a location in storage
+ xvalue - an expiring value that does occupy a location in storage (an object near the end of its lifetime)
+ lvalue - a locator value that occupies a location in storage
_ When the compiler creates a temp obj it converts a prvalue into an x value, which is temporary located in memory
--> Called Temporary Materialization Conversion

* lvalue Operands
+ a name that is not an array name
+ an array element - a[i]
+ (expression) - where expression is itself an lvalue
+ a direct member selection - expression.member - where expression is itself an lvalue
+ an indirect member selection - expression->member - where expression points to an lvalue
+ a dereferenced address - *expression
+ a string literal (actually an array of characters)
*/

//? Operator Precendence
/*
_ Expressions are divided into six operand-related classifications:
+ primary
+ postfix
+ prefix
+ unary
+ binary
+ ternary
*/

//? Postfix Expressions
/*
_ Postfix expressions are expressions in which a postfix operator follows a single operand or the first operand of two operands. 
_ Postfix operators include the subscripting operator, the function call operator, the member selection operator, the postfix
 increment operator, and the postfix decrement operator.

* Subscripting Operator
_ The subscripting operator takes as its left operand a pointer of type T and as its right operand a value of integral type.
*/
#include <iostream>
int main()
{
    double a[10];
    int i = 2;

    a[i] = 6; // lvalue
//! a holds the address of array a[10], i is an integral type, and a[i] refers to the i-th element beyond the start of a.

    char  name[] = "Jane Doe";
    char* surname = nullptr;

    surname = &name[5];
    surname[-1] = '.';  // changes "Jane Doe" to "Jane.Doe"
}

//? Member Selection
/*
_ The member selection operators identify an object by their left operand and the name of a member by their right operand. 
*1. Direct selection
_ The direct selection operator (.) takes an object of complete class type as its left operand and the member name as its right operand:

*2. Indirect selection.
_ The indirect selection operator (->) takes a pointer to an object of complete class type as its left operand and the member name as its right operand
*/

//? Postfix Increment and Decrement
/*
_ The postfix increment and decrement operators change an lvalue by one unit after accessing the value. 
_ The operand is of integral, floating-point, or pointer type and followed by the increment (++) or decrement (--) operator. 
_ The operand must be a modifiable lvalue and the expression itself is a prvalue.

* Results at Integer Limits
_ If the operand is of unsigned type and its value is 0u, the decrement operator changes the lvalue to the largest
storable value. If the operand is of unsigned type and its value is the largest storable value, the increment 
operator changes the lvalue to 0u.
*/

//? Constrained Cast Operators
/*
* static_cast Operator
_ The static_cast<T>(v) operator converts expression v to type T. If T is an lvalue reference type or an rvalue reference
to a function type, the result is an lvalue. If T is an rvalue reference to an object type, the result is an xvalue. 
Otherwise, the result is a prvalue.
+ Standard (Implicit) Conversions and their opposite
    ~ lvalue to rvalue
    ~ integral or floating-point promotions
    ~ conversions: integral, floating-point, floating-point to integral, integral to floating-point, pointer, pointer to member, boolean
    ~ void* to pointer type
+ between related classes
+ enumerator to integral or floating-point
+ scoped enumerator to integral or floating-point
+ rvalue references
+ any type to void discarding the value
_ The static_cast<T>(v) operator cannot cast away const-ness.

* reinterpret_cast Operator
_ The reinterpret_cast<T>(v) operator converts expression v to type T. If T is an lvalue reference type or an rvalue 
reference to a function type, the result is an lvalue. If T is an rvalue reference to an object type, the result is
an xvalue. Otherwise, the result is a prvalue. 

_ The reinterpret_cast<T>(v) operator can perform the following conversions
+ pointer to member to pointer to member of different type
+ pointer to integral, integral or enumeration type to pointer
+ function pointer to function pointer of different type
+ object pointer to an object pointer of different type
+ function pointer to object pointer (conditionally supported)
_ The reinterpret_cast<T>(v) operator cannot cast away const-ness.

* const_cast Operator
_ The const_cast<T>(v) operator converts expression v to type T. If T is an lvalue reference to an object type, the result is an lvalue. 
If T is an rvalue reference to an object type, the result is an xvalue. Otherwise, the result is a prvalue.

* dynamic_cast Operator
_ The dynamic_cast<T>(v) operator converts expression v to type T. T is a pointer or reference to a complete type. 
If T is a pointer type, v shall be an lvalue of a complete class and the result is an lvalue of the type referred to by T.
If T is an rvalue reference to an object type, v shall be an glvalue of a complete class and the result is an xvalue 
of the type referred to by T.

_ The dynamic_cast<T>(v) operator cannot cast away const-ness.
*/

//? Prefix Expressions
/*
_ The prefix expressions are increment and decrement expressions in which the operator precedes the operand and associates from right to left.

* Prefix Increment and Decrement
_ The prefix increment (++) and decrement (--) operators change an lvalue by one unit before accessing the value. The result of the operation is an lvalue, 
unlike their post-fix counterparts. The operand may be of any integral type, floating-point type, or pointer type, but must be a modifiable lvalue.
_ The results of a prefix increment and decrement operation on upper and lower limit values of unsigned types and signed types are
 similar to those for postfix increment and decrement operations.
_ If the operand is of unsigned type and its value is 0, the decrement operation evaluates to the largest storable value.
_ If the operand in a prefix expression is of unsigned type and its value is the largest storable value, the increment 
operation evaluates to 0.
_ If the operand is of signed integral type, floating-point type, or pointer type, and the increment/decrement operation 
produces an overflow/underflow, the result is undefined.
*/

//? Unary Expressions
/*
_ The unary expressions are expressions in which the operator precedes a single operand. They include size evaluation, logical and bit-wise
 negation, arithmetic plus and negation, addressing, indirection, and type casting. Unary operators associate from right to left.

* sizeof(), sizeof
_ The sizeof() operator evaluates the type of its operand and returns its size in bytes. The sizeof operator (without the parentheses) returns
 the number of bytes used by a variable, object, or expression. 
_ The result of either sizeof operation is a constant of type size_t (an unsigned integral type).
_ sizeof() takes a type, while sizeof takes a variable, object, or expression. With some compilers, the syntax is interchangeable.
*/

//? Bit-Wise Negation
/*
* Arithmetic Negation
_ The unary negation operator (-) evaluates to its operand with its sign reversed. The result is a prvalue of the same type as
the operand after any promotions.

* Arithmetic Plus
_ The unary plus operator (+) evaluates to its operand. The result is a prvalue of the same type as the operand after any promotions.
The operator is present in the language for symmetry.
_ The address-of operator (&) returns a pointer to its operand: the value is the address of the operand. 
*/

//? Indirection
/*
_ The indirection operator (*) returns the value stored in the address that the operand contains. 
The expression is itself an lvalue.
_ The indirection and address-of operators are inverses of one another. The result of *&x is x.
*/

//? Cast
/*
_ The type-cast operator consists of a type name followed by an operand and converts the operand to the specified type. 
The operand may not be the name of an array. The expression is a prvalue.\
_ There are two styles of casting:
    + C-style casts - enclose the target type within parentheses
    + C++-function-style casts - enclose the operand within parentheses

* alignof() Operator
_ The alignof() operator returns the alignment requirement of its operand. The operand may be a type identifier representing
the type of a complete object, or an array or a reference to one of those types. The operation returns an integral constant 
of type std::size_t.

* decltype() Specifier
_ The decltype() specifier evaluates to the type and value category of its argument. The operand may be an entity or an expression. 
The value category of the expression affects the type:
    + if the value category of the expression is an xvalue, then the type is T&&
    + if the value category of the expression is an lvalue, then the type is T&
    + if the value category of the expression is a prvalue, then the type is T

* noexcept() Operator
_ The no exception operator (noexcept()) returns true if the argument does not throw an exception. This compile-time function evaluates to a prvalue of type bool. 
_ This operator does not evaluate the argument passed to it. This operator returns false if the expression contains:
    + a call to function that does not have a non-throwing exception specification (noexcept), unless it is a constant expression
    + a throw expression
    + a dynamic_cast expression when the target type is a reference type and conversion needs a run-time check
    + a typeid expression when the argument is a polymorphic type

* throw Operator
_ The throw operator (throw) identifies an exception to normal execution. The operator creates a temporary object from its operand and transfers control to the exception handler. 
_ The exception object is an lvalue of the type of the operand of the throw expression. This operand is analogous to an argument passed to a function and received in its parameter

*/

//? Logical
/*
_ Binary logical expressions evaluate the combined truthfulness of their operands. The operands may be of integral type, floating-point type, or pointer type. 

* Intersection and Union
_ The logical 'and' operator (&&) compares its operands and returns their intersection. The following rules apply:
    + true, if both operands are true
    + false, if either of the operands is false

_ The logical 'or' operator (||) compares its operands and returns their union. The following rules apply:
    + true, if either operand is true
    + false, if both of the operands are false

* Left to Right
_ Logical expressions evaluate their operands left-to-right as necessary. In this respect, they differ from other binary expressions. 
_ If the left operand determines the result, the right operand is not evaluated.
*/

//? Assignment Expressions
/*
_ An assignment expression copies from the right operand to the left operand. The left operand must be a modifiable lvalue. Because assignment 
expressions associate from right to left, cascading is possible. The expressions may be simple or compound.

* Simple Assignment
_ The simple assignment operator (=) copies the value of the right operand without modification into the left operand. 


* Sequential Expressions
_ The comma operator (,) divides expressions for separate evaluation in sequence from the left. The operands may be expressions themselves and may be of any type.

*/

void reverse(char *s)
{
    char t;

    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

/*
* The Unsigned Trap
_ If one of the operands is of unsigned integral type and the other is of a signed integral type, the compiler promotes the value of the signed type to a value of unsigned type.
*/

/*
* Sub-Divide Complex Binary Expressions
int x = 3;
x = x + ++x;  // the result may be either 7 or 8

int x = 3;
++x;
x = x + x;  // increment first = 8

int x = 3, y;
y = ++x;
x = x + y;  // add first = 7

*/