#include <iostream>

using namespace std;

// Array is not ptr

int main()
{
    int arr[] {2,5,9,0, -1,4};

    for (int index = 0; index < 6; ++index)
    {
        cout << arr[index] <<", ";
    }
    int* p = &arr[2];

    cout << endl;

    int* p = arr + 2; // move the index of the array
    
    for (int index = 0; index < 4; ++index)
    {
        cout << arr[-index] <<", ";   // reverse array
    }

    cout << sizeof(arr) << endl;  // 8 * 6 = 48

    //Count how many element
    cout << sizeof(arr) / sizeof(arr[0]) << endl;

}