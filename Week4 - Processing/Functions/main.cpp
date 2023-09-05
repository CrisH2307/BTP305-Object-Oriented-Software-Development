//! FUNCTIONS
/*
+ Describe function linkage and recursion
+ Introduce function ptrs, func objs and lambda expressions

_ Object-oriented languages use function types to represent behavior
_ Function types implement cohesive blocks of logic
_ Function types may be overloaded, inherited, derived, templated, and nested
_ Nested types can access variables within the scope of their host function.
_ Such types couple their logic to their nesting environment and are known as closures.
*/

//? Function Syntax
/*
_ Introduced syntax to specify program instructions in as simple and least-repetitive way as possible.
    + type-inference declaration
    + trailing return type declaration

* Trailing Return-Type Declaration
_ A C++ compiler needs sufficient information about a function to infer its return type
_ Sometimes this information is in the identifier and sometimes in the parameter list itself.
todo    |      auto identifier(parameter-type-list) -> return-type;

_ The auto keyword identifies the declaration as one with a return type inference. 
_ The return-type follows the closing parenthesis and depends on the identifier or the parameter list. 
1. Enumerations that have been defined within a class
_ Consider auto_return.cpp

2. Templated functions
_ Consider decltype.cpp
*/

//? Linkage
/*
_ A function type can have either external or internal linkage. A function with external linkage
is visible outside its translation unit, while a function with internal linkage is invisible outside 
its translation unit.
_ The default linkage for a function type in C++ is external. That is, the keyword extern is redundant. 
The main() function of every application must have external linkage.
*/


//? Recursion
/*
_ A recursive function is a function that calls itself from within its own body.
_ Recursive functions require an exit condition that defines when the recursion terminates
_ Once it terminates control begins stepping back through the function call stack to the initial caller. 
_ The exit condition prevents stack overflow caused by an ever increasing set of recursive calls.

* Stack Space Alternative
_ Stack space is a precious resource. The alternative to highly recursive logic is an iteration construct. 
*/

//? Function Pointer
/*
_ Because functions reside in memory, they are addressable and their addresses can be stored in pointers.
_ A function pointer holds the address of a function type.
_ The address identifies the location in memory where control is transferred to start execution of the function's code
todo  |      return-type (*identifier)(parameter-type-list) [= fn];
    + return-type is the return type of the function, 
    + identifier is the name of the pointer to the function and (= fn) is the initial address, which is optional

    T* ptrToObject;         // 1
    T (*ptrToFunction)(T&); // 2
    T* function(T&);        // 3

_ ptrToObject is the name of a pointer that holds the address of a region of type T
_ ptrToFunction is the name of a pointer that holds the address of a region of type T (*)(T&)
_ function is the name of a function that receives a reference to an object of type T& 
and returns the address of a region that holds an object of type T

_ A function pointer can hold the address of any region of memory that contains instructions for a 
function that receives a reference to an object of type T and returns the value of an object of type T.

_ To define the pointer ptrToFunction and initialize it to the address of function fn, we simply write
    T (*ptrToFunction)(T&) = fn;
    T (*ptrToFunction)(T&) = &fn;
    The & is optional since fn implicitly converts to &fn.

_ To change the function pointed to by ptrToFunction to gn, we simply write
    T (*ptrToFunction)(T&) = fn;
    ptrToFunction = gn;

*/

//? Arrays of Pointers to Functions
/*
_ If several functions share the same return types and the same ordered set of parameter types, we may store 
their addresses in an array of pointers to functions. Each element of such an array points to one of the 
functions in the set or to nullptr address.
todo  |     return-type (*identifier[n])(parameter-type-list) = { initialization-list };
_ where n is the number of elements in the array and the optional = { initialization-list } 
is a comma separated list of function addresses enclosed within braces.
*/

//? Function Objects
/*
_ A function object is an object-oriented representation of a function. A function object is also called a functor.
_ The term originates in mathematics, specifically category theory, and may be interpreted as the pattern for 
a type that allows a function without changing the structure of the type
_ The class that defines the structure of a function object in C++ overloads the function call operator.
- The constructor for that class accepts the state for the function object.
_ Like an instance of a class and unlike a function pointer, a function object can store state, 
which may affect the result of a call to the represented function
*/

//? Lambda Expressions
/*
_ A function object that is only used in a local area of an application can be represented by a lambda expression
_ A lambda expression does not require an identifier and is shorthand for a function object
_ If the expression is used more than once it can be given a name and referred to by that name within the body of its host func
_ A lambda expression can capture variables within the scope of its host function
todo|     [capture-list](parameter-declaration-clause) -> optional-return-type
         {
            function body
         }

*/

//? Capture List
/*
_ The capture list of a lambda expression is the mechanism for passing all non-local variables to the body of the lambda expression.

* Empty List
_ The simplest lambda expressions do not rely on variables within their environment. They have empty capture lists.
_ [] denotes no capture.
---> Consider lambda.cpp

* Capture by Value
_ [=] denotes capture by value.
_ The template syntax provides the mechanism for receiving a lambda expression in a function definition
---> Consider capture_by_value.cpp

* Capture by Reference
_ [&] denotes capture by reference.

* Exceptions to Capture Defaults
_ Exceptions to the capture list defaults can be added to a capture-list. 
    + [=](...) - captures all non-local variables by value
    + [&](...) - captures all non-local variables by reference
    + [=,&x,&y](...) - captures x and y by reference, all else by value
    + [&,x,y](...) - captures x and y by value, all else by reference
    + [x,&y](...) - captures x by value and y by reference
    + [this](...) - captures this by value

_ The keyword mutable allows modification of non-local variables captured by value. 
A lambda expression that allows such modification takes the form

todo |  [capture-list](parameter-declaration-clause) mutable -> optional-return-type
        {
            function body
        }
*/

