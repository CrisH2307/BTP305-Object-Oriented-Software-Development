//! ERROR HANDLING
/*
_ Introduce exceptions and describe how to report them and how to handle them
_ Describe different ways of terminating an application prematurely

_ The modularity of object-oriented programs give rise to a separation of the cause
of an error from the place where that error can be handled properly. Object-oriented 
languages require a specialized mechanism for identifying and handling errors
*/

//? Exceptions
/*
_ An exception is something that is not done as one would normally expect it to be done. 
It may be a response to an initial attempt at a solution, a calculation that triggers a 
hardware error, or a warning about a questionable outcome

* Reporting and Handling
_ Exception processing has two distinct parts:
1. Reporting an Exception
     throw expression;
_ Expression is an expression of a previously defined type. 
_ A function that includes this statement cannot be identified as a noexcept function

2. Handling the Exception
_ The code for handling an exception consists of two parts: 
+ the set of statements that initiated the process
+ the set of statements that respond to an exception. 

_ The keywords try and catch identify these complementary parts:
+ a try block contains all of the code that initiates whatever might throw the exception
+ one or more catch blocks contain the code that handles any exception that was thrown as
a result of executing any statement within the try block
    try
    {
        code that might generate exceptions
    }
    catch (Type_1 identifier)
    {
        handler code for a specific type of exception
    }
    catch (Type_2 identifier)
    {
        handler code for another specific type of exception
    }
    catch (...)
    {
        handler code for all other types of exception
    }
_ Type_1 and Type_2 refers to the type of the expression being handled
_ identifier is the name used within the catch block to refer to the expression that has been thrown
_ The first catch block that receives the type matching the reporting type handles the exception
_ The ellipsis (...) denotes any type not caught by the preceding catch blocks.

* Detecting an Exception
_ If an exception has been thrown, but has not yet entered a catch, the function int std::uncaught_exceptions()
utility returns the number of uncaught exceptions in the current thread, during stack unwinding.
*/

//? Standard Exceptions
/*
_ The base class for the hierarchy of these classes is called exception and is defined in the <exception> header file
_ Classes derived from this base class include:
+ logic_error - handles problems in a program's internal logic, which in theory are preventable. 
The following classes are derived from logic_error:
    ~ length_error
    ~ domain_error
    ~ out_of_range
    ~ invalid_argument
+ runtime_error - handles problems that can only be caught during execution. 
The following classes are derived from runtime_error:
    ~ range_error
    ~ overflow_error
    ~ underflow_error
+ bad_alloc - handles the allocation exception thrown by new. This class needs the <new> header file
+ bad_cast - handles the exception thrown by dynamic_cast. This class needs the <typeinfo> header file

    try
    {
        p = new char[std::strlen(s) + 1];
        std::strcpy(p, s);
    }
    catch (std::bad_alloc)
    {
        std::cout << "Insufficient memory\n";
    }
    catch (std::exception& e)
    {
        std::cout << "Standard Exception\n";
    }

_ The following handles all exceptions including the std:::bad_alloc exception under the first catch block

    try
    {
        p = new char[std::strlen(s) + 1];
        std::strcpy(p, s);
    }
    catch (std::exception& e) // called by std::bad_alloc also
    {
        std::cout << "Standard Exception\n";
    }
    catch (std::bad_alloc) // UNREACHABLE!
    {
        std::cout << "Insufficient memory\n";
    }

*/

//? Expressions that Throw Exceptions
/*
_ Exceptions may be thrown by the following expressions:
    + a throw expression
    + a dynamic_cast expression
    + a type_id expression
    + a new expression

* noexcept
_ The noexcept keyword identifies a function as one that will not throw an exception. 
_ This keyword informs the compiler that it can perform certain optimizations
that would not be possible if uncaught exceptions could pass through the function.
*/

//? Standard Exits
/*
_ The main() function of a program serves as its entry point and returns an integer to the operating system that
 conveys the program's status at exit time. This integer is the value of the expression in the return statement

 _ The library functions that augment this normal termination mechanism include functions for:
1. Normal exits
_ Normal exits involve calling the destructors that would be called at the end of each object's lifetime, 
flushing and closing all input and output streams and returning a status integer to the operating system.
    + int atexit(void (*)(void)): The atexit() function registers a function to be called during any 
    termination initiated by a call to the void exit(int) function
    + int exit(int):
    _ The void exit(int) function initiates a termination process that:
        + destroys objects with thread storage duration and associated with the current thread
        + destroys objects with static storage duration
        + calls functions that have been registered by atexit()
        + flushes and closes all open C streams
        + returns control to the operating system

2. Abnormal exits
_ Two functions initiate abnormal termination:
    *+ void std::terminate(): 
    _ The terminate() function terminates program execution as result of an error related to exception handling. 
        + the mechanism cannot find a handler for a thrown exception
        + the handler encounters the body of a function with a noexcept specification
        + the destruction of an object exits via an exception
        + throw with no operand attempts to throw an exception when none exits
    _ This function does not execute destructors for objects of automatic, thread,
    or static storage duration or call functions at addresses passed to atexit().
    
    *+ void std::abort():
    _ The abort() function terminates program execution by a SIGABRT signal. This function, like terminate(), 
    does not execute destructors for objects of automatic, thread, or static storage duration or call functions 
    at addresses passed to atexit().
*/