
// Template Specialization
// maximum.h

#include <iostream>
#include <cstring>

// Template definition for finding the maximum of two values of the same type
template <typename T>
T maximum(T a, T b)
{
    std::cout << "in template body\n";
    return a > b ? a : b;
}

// Specialization for const char* types
template <>
const char* maximum<const char*>(const char* a, const char* b)
{
    std::cout << "in specialization\n";
    return std::strcmp(a, b) > 0 ? a : b;
}
