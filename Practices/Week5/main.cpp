// recursive function: a function that calls itselt
// FIbonacci Sequance: 0 1 1 1 2 3 4 8 13 21 34 55
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
unsigned int fibI(unsigned int n)
{
    if (n == 0)
    {
        throw "index too small";
    }
    if (n >= 7)
    {
        throw n; // raise an exception (throw/ generate)
    }

    if (n == 30)
    {
        std::string error = "Index [";
        error += std::to_string(n);
        error += "] is secret.";
        throw error;
    }

    unsigned int val1 = 1, val2 = 0;
    for (auto i = 0u; i < n; ++i)
    {
        auto temp = val1 + val2;
        val2 = val1;
        val1 = temp;
    }
    return val1;
}

unsigned int fibR(unsigned int n)
{
    // remember exit condition
    if (n <= 1)
    {
        return n;
    }
    return fibR(n - 1) + fibR(n-2);
}

int main()
{
    for (auto i = 0u; i < 21; ++i)
    {
        try
        {
            // Try to execut the code, something might go wrong
            // Here I write like everything is perfect
            cout << i << ". " << fibI(i) << endl;
        }

        catch(unsigned int error)
        {
            //deal with exceptions of the type 'unsigned int'
            cerr << "Exception: index [" << error << "] cannot be calculated - it's too big." << endl;
            break;
        }

        catch (std::string& error)
        {
            //deal with exceptions of type 'unsigned int'
            // string literals are safe for catching by address
            cerr << error << endl;
        }
        catch (...)
        {
            // This handle all other exceptions
            cerr << "Unknown error." << endl;
        }
        cout << "Main function is finished" << endl;
    }

}