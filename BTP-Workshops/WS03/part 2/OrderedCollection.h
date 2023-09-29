/*
*****************************************************************************
                              OrderedCollection.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include "Book.h"
#include "Collection.h"

namespace sdds
{
    template <typename T>
    class OrderedCollection : public Collection<T, 72> 
    {  
    public:

    bool operator+=(const T& thatItem)
    {
        if (this->size() < this->capacity())
        {
            unsigned int insertIndex = 0;

            OrderedCollection<T>& thisO = (*this);

            while (static_cast<int>(insertIndex) < static_cast<int>(this->size()) && thatItem > thisO[insertIndex])
            {
                ++insertIndex;
            }

            for (unsigned int i = this->size(); i > insertIndex; --i)
            {
                thisO[i] = thisO[i - 1];
            }

            thisO[insertIndex] = thatItem;
            this->setLargestItem(thatItem);
            this->setSmallestItem(thatItem);
            this->incrSize();

            return true;
        }

        return false;
    }

};
       
}

#endif