#include <iostream>

using namespace std;

// submit 345_w1_p1 abc 123

/*
_ Memory Segments (zones)
+ Stack: Statically-allocated variables
+ Heap: Dynamic memory (expandable)
+ Code: functions/ executable (marked as read-only)
+ Data: Global variable

_ Segmentation fault/ access violation
*/

// int main() 
int main(int argc, char** argv)// this is a main function that can accept two params
       //(argument count, argument value)
{
    cout << "Received [" << argc << "} parameters.\n";
    for(int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }

    const int a = 12;  // class name // string N-name // name(const string&name const)
    // volatile means this variable can be changed the value unexpected
    // do not optimize the access to "a"; the variable can change unexpected

    int* constThis = const_cast<int*> (&a);
    *constThis = 69;  //hack

    cout << "Should be: " << a << "[" << (int*)&a << "]" << endl;

    cout << "Should be: " << *constThis << "[" <<  constThis << "]" << endl;

    cout << argv[0] << endl;
}
//todo: Const vs constexpr, external/internal linkage
// In C++, the main function does not require the return because it is default as return 0. 