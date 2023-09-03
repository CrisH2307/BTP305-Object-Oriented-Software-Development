// Static Data Member Declaration
// array.h

template <typename T = int, int SIZE = 50>
class Array
{
    T a[SIZE];
    unsigned n;
    T dummy;
    static unsigned m_count;               // <-- class member (aka type member)

public:
    Array() : n{0}, dummy{} { ++m_count; }
    ~Array() { --m_count; }

    T& operator[](unsigned i)
    {
        return i < SIZE ? a[i] : dummy;
    }

    static unsigned getCount();           // <-- class member (aka type member)
};

template <typename T, int SIZE>
unsigned Array<T, SIZE>::m_count = 0u;

template <typename T, int SIZE>
unsigned Array<T, SIZE>::getCount()
{
    return Array<T, SIZE>::m_count;
}