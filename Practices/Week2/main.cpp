#include <iostream>

using namespace std; 
// type: set of possible value + operations possible on those values
// type indicates what you can do with the variables

/*
Fundamental type:
_ Integer types: char   short     int     long    long long
_ Floating point nums: float     double     long double

Build-in types
_ Ptrs, array, references

*/
struct Foo1
{
    double m_data = 123.321;
    operator int() const
    {
        return static_cast<int>(m_data);
    }
    Foo1(){cout << "[" << this << "] is built." << endl; }
    ~Foo1(){cout << "[" << this << "] is removed." << endl; }

};

Foo1 getData()
{
    Foo1 aFoo;

    aFoo.m_data=5;

    return aFoo; // a Foo is at the end of its life
}

using namespace std;

class foo
{

};
int main(int, char**)
{
    wchar_t str[] { L"HelloWorld"};
    char16_t str1[] {u"hi"};
    char32_t str1[] {U"hi"};

    auto data = 'a';

    double* p;

    char* str;

    int data1 = 10;
    int data2 = 323;

    // lvalue: Something that has memory
    int& refInt = data1; 

    // rvalue: A reference that are temporary
    int&& refVal = 10; // 10 is  avalue, temporary materialization

    data1 += Foo1(); // Foo1 create temp instance of type Foo1


    //C++ doesnt allow: reference to reference, ptr to ref, array to ref

    reference_wrapper<int> refArr[2]
    {
        std::ref(data1),std::ref(data2)
    };

    for (auto& item : refArr)
    {
        cout << " " << item;
    }
    cout << endl;





}