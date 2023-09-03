// Non-Type Template Parameters
// array.h

template <typename T, int SIZE>
class Array
{
    T a[SIZE];
    unsigned n;
    T dummy;
public:
    Array() : n{0u}, dummy{} {}
    T& operator[](unsigned i)
    {
        return i < SIZE ? a[i] : dummy;
    }
};