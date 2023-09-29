#include <iostream>

using namespace std;

template <typename T>

struct ValueCategory
{
    static constexpr char const* value = "prvalue";
};

template <typename T>
struct ValueCategory<T&>
{
    static constexpr char const* value = "lvalue";
};

template <typename T>
struct ValueCategory<T&&>
{
    static constexpr char const* value = "xvalue";
};

#define PRINT_VALUE(expr)     cout << #expr << " is a" << ValueCategory<decltype((expr))>::value;    //

struct S { int i;};

int main()
{
    int data;
    PRINT_VALUE(0);         // is  a prvalue
    PRINT_VALUE(data);      // is a lvalue
    PRINT_VALUE(data + 0);  // is a prvalue
    PRINT_VALUE(data =+ 0); // is a lvalue
    PRINT_VALUE(++data);    // is  a lvalue
    PRINT_VALUE(data++);    // is a prvalue
    PRINT_VALUE(S{ 0 });    // is a prvalue
    PRINT_VALUE(S{ 0 }.i);    // is a xvalue
    cout << "0 is a" << ValueCategory<decltype((0))>::value;    //
    cout << "data is a" << ValueCategory<decltype((data))>::value;
    cout << "data + 0 is a" << ValueCategory<decltype((data + 0))>::value;
    cout << "data += is a" << ValueCategory<decltype((data =+ 0))>::value;

}