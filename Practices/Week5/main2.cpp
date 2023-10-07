#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>

using namespace std;

// Function and things that look like functions
bool asc(int a, int b) { return a >b;}
bool desc(int a, int b) { return a <b;}
bool oddEven(int a, int b) { 
    // all odd value should appear before even value
    if (a%2 == 0 && b% 2 == 0)
    {
        return false;
    }

    if (a%2 == 0 && b% 2 != 0)
    {
        return true;
    }

    if (a%2 != 0 && b% 2 == 0)
    {
        return false;
    }

    if (a%2 != 0 && b% 2 != 0)
    {
        return false;
    }
}

//typedef bool (*compare_t) (int,int); // compare_t is an C-style alias for a ptr to a function 
using comparator_t = bool(*)(int, int); // compare_t is an C-style alias for a ptr to a function 

// ptr to function -- call back

// function objs (functors)
enum class Order
{
    Ascending,
    Descending,
    oddEven,
};

class Comparator
{
    private:
    Order m_order = Order::Ascending;
    int m_cnt = 0;
public:
    void setOrder(Order newOrder)
    {
        m_order = newOrder;
    }

// any calls that overloads operator()
    bool operator()(int a, int b)
    {
        ++m_cnt;
        if (m_order == Order::Ascending)
        {
            return asc(a,b);
        }
        else if(m_order == Order::Descending)
        {
            return desc(a,b);
        }
        return oddEven(a,b);
    }

    friend ostream& operator<<(ostream& o, const Comparator& that)
    {
        return o << "# of comparisions [" << that.m_cnt << "]" << endl;
    }

};

// Assumptions about "Comp_t"
// - i can use operator() with prototype bool(int, int)
template<typename Comp_t>
void bubbleSort(int* arr, size_t n, Comp_t& comp)
{
    for (auto i = 0u; i < n - 1; ++i)
    {
        for (auto j = i + 1; j < n; ++j)
        {
            if(comp(arr[i],arr[j]))  // should I switch the numbers at index i and j
            {
                auto temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}

void display(const int* arr, size_t n)
{
    cout << arr[0];
    for (auto i = 0; i < n; ++i)
    {
        cout << ", " << arr[i];
    }
    cout << endl;
}

int main()
{
    int arr[]{23,11,87,9,32,44,112,2,-42};
    display(arr, 8);

    // Create a ptr that stores the address of a function with prototype
    comparator_t compare_func = nullptr;

    char choice{};

    cout << "Compare how? (a/d/o)";
    cin >> choice;

    switch (choice)
    {
    case 'a':
        compare_func = &asc;
        break;
    case 'd':
        compare_func = &desc;
        break;
    default:
        compare_func = &oddEven;
        break;
    }

    bubbleSort(arr, 8, compare_func);
    display(arr,8);
    {
        //use function obj
        Comparator comp_fo;
        comp_fo.setOrder(Order::Descending);
        cout << comp_fo;
        bubbleSort(arr, 8, comp_fo);
        display(arr, 8);
        cout << comp_fo;
    }

    size_t cnt{};
    // Mechanical Annoymous Function called Lambda Expression
    auto comp_lambda= [&cnt](int a, int b)-> bool {
        cout << "Cnt [" << cnt <<  "]" << endl;
        ++cnt;
        return asc(a,b);
    };

    cout << typeid(comp_lambda).name() << endl;

    cout << "The counter as seen by main ["<<  cnt << "]" << endl;
    bubbleSort(arr, 8, comp_lambda);
    display(arr,8);
    cout << "The counter as seen by main ["<<  cnt << "]" << endl;

    //bubbleSort(arr, 8, [](int a, int b) {return a < b;});

}