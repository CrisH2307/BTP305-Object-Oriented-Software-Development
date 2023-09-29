/*
*****************************************************************************
                              Collection.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds
{
    template <typename T, unsigned int C>
    class Collection
    {
        T m_items[C];
        static T m_smallestItem;
        static T m_largestItem;
        unsigned int m_size = 0;

    protected:
        void setSmallestItem(const T& that)
        {
            if (that < m_smallestItem)
            {
                m_smallestItem = that;
            }
        }

        void setLargestItem(const T& that)
        {
            if (that > m_largestItem)
            {
                m_largestItem = that;
            }
        }

    public:
        static T getSmallestItem()
        {
            return m_smallestItem;
        }

        static T getLargestItem()
        {
            return m_largestItem;
        }

        Collection() {}

        unsigned int size() const
        {
            return m_size;
        }

        unsigned int capacity() const
        {
            return C;
        }

        bool operator+=(const T& thatItem)
        {
            if (m_size < C)
            {
                m_items[m_size++] = thatItem;
                setSmallestItem(thatItem);
                setLargestItem(thatItem);
                return true;
            }
            else
            {
                return false;
            }
        }

        void print(std::ostream& ooo) const
        {
            ooo << "[";
            for (unsigned int i = 0; i < m_size; ++i)
            {
                if (i == m_size - 1)
                {
                    ooo << std::setprecision(1) << m_items[i];
                }
                else
                {
                    ooo << std::setprecision(1) << m_items[i] << ',';
                }
            }
            ooo << "]";
            ooo << std::endl;
        }
    };

    // Initialize static members for any type
    template <typename T, unsigned int C>
    T Collection<T, C>::m_smallestItem = T(9999);

    template <typename T, unsigned int C>
    T Collection<T, C>::m_largestItem = T(-9999);

    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
}

#endif
