//! Raw Pointer
/*
String Literals: 
_ A sequence of characters surrounded by double quotes. This is an lvalue that
holds global variables. 
*/

// C++ program to demonstrate working of raw string literal
#include <iostream>
using namespace std;

int main()
{
	// Normal String
	string s1 = "Cornel.\nCris.\nSean.\n";

	// Raw string
	string s2 = R"(Cornel.\nCris.\nSean.\n)";

	cout << s1;
	cout << endl;
	cout << s2;
}