#include <iostream>
#include "ultils.h"
using namespace std;

int g_data = 10;

static int g_secret = 789; //internal, no access

void sayHello()
{
    static int cnt{};   // This variable will be received the memory, it survives the end of the function
    ++cnt;

    cout << cnt << "Hello from ultils.cpp\n";
    cout << "g_data is: [" << g_data << "]\n";
    cout << "g_secret is: [" << g_secret << "]\n";
}