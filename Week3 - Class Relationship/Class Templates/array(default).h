// Default Template Parameter Values
// array.h

template <typename T = int, int SIZE = 50>
class Array
{
    T a[SIZE];
    unsigned n;
    T dummy;
public:
    Array() : n(0), dummy() {}
    T& operator[](unsigned i)
    {
        return i < SIZE ? a[i] : dummy;
    }
};