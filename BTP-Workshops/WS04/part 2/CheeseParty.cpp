/*
*****************************************************************************
                              ChesseParty.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Cheese.h"
#include "CheeseParty.h"
#include "CheeseShop.h"

using namespace std;

namespace sdds 
{
    CheeseParty::CheeseParty(): m_cheeses(nullptr), m_numCheeses(0) {}

    CheeseParty& CheeseParty::addCheese(const sdds::Cheese& that)
    {
        //todo: CheeseParty& addCheese(const Cheese&)
        /*
        A modifier that adds a cheese object to the array of pointers.

        search in the array of already stored cheeses to find if the parameter is already in there 
        (compare the address of the parameter with the addresses stored in the array).
        if the parameter is already in the array, this function does nothing.
        if the parameter is not in the array, this function resizes the array to make room for the 
        parameter (if necessary) and stores the address of the parameter in the array 
        (your function should not make a copy of the parameter).return current instance.
        */

        for (size_t i = 0; i < m_numCheeses; ++i)
        {
            if (m_cheeses[i] == &that) // Cheese is already in the array, do nothing
            {
                return *this;
            }
        }

        const Cheese** newCheese = new const Cheese*[m_numCheeses + 1];

        for (size_t i = 0; i < m_numCheeses; ++i) 
        {
            newCheese[i] = m_cheeses[i];
        }
        newCheese[m_numCheeses] = &that;

        // Deallocate old one and update
        delete[] m_cheeses;
        m_cheeses = newCheese;
        ++m_numCheeses;

        return *this;
    }

    CheeseParty& CheeseParty::removeCheese()
    {
        //todo: CheeseParty& removeCheese()
        /*
        A modifier that removes any cheeses from the array that have a 0 weight.
        Searches the array for 0 weight cheeses and sets the pointer in the array to nullptr if such a cheese is found.
        To challenge yourself, try to actually resize the array.
        */

        size_t n = 0;
        // Count the non-null pointers
        for (size_t i = 0; i < m_numCheeses; ++i)
        {
            if (m_cheeses[i] && m_cheeses[i]->getWeight() != 0)
            {
                n++;
            }
        }

        // Create a new array with non-null pointers
        const Cheese** newCheeses = new const Cheese*[n];
        size_t newIndex = 0;
        for (size_t i = 0; i < m_numCheeses; ++i)
        {
            if (m_cheeses[i] and m_cheeses[i]->getWeight() != 0)
            {
                newCheeses[newIndex] = m_cheeses[i];
                newIndex++;
            }
        }

        // Delete the old array
        delete[] m_cheeses;

        // Update the member variables
        m_cheeses = newCheeses;
        m_numCheeses = n;

        return *this;
    }

    //*----------------------- RULES OF 6 --------------------------------//
    CheeseParty::CheeseParty(const CheeseParty& that) : CheeseParty()
    {
        *this = that;
    }

    CheeseParty& CheeseParty::operator=(const CheeseParty& that)
    {
        if (this != &that)
        {
            const Cheese** anotherCheesePartyisHere = new const Cheese*[that.m_numCheeses];

            this->m_numCheeses = that.m_numCheeses;

            for (size_t i = 0; i < m_numCheeses; ++i)
            {
                anotherCheesePartyisHere[i] = that.m_cheeses[i];
                //or
                //anotherCheeseisHere[i] = new Cheese(*that.m_cheeses[i]);
            }
            delete[]m_cheeses;
            this->m_cheeses = anotherCheesePartyisHere;
        }
        return *this;

    }
    CheeseParty::~CheeseParty()
    {
        delete[]m_cheeses;
        m_numCheeses = 0;
    }

    CheeseParty::CheeseParty(CheeseParty&& that): CheeseParty()
    {
        *this = move(that);
    }

    CheeseParty& CheeseParty::operator=(CheeseParty&& that)
    {
        if (this != &that)
        {
            delete[]m_cheeses;

            this->m_cheeses = that.m_cheeses;
            this->m_numCheeses = that.m_numCheeses;

            that.m_cheeses = nullptr;
            that.m_numCheeses = 0;
        }
        return *this;
    }

    //*----------------------- END OF RULES OF 6 --------------------------------//    


    ostream& operator<<(ostream& oo, const CheeseParty& that)
    {
        //todo: overload the insertion operator to insert the content of a CheeseParty object into an ostream object
        /*
            if there is no cheese at the party:
            --------------------------
            Cheese Party
            --------------------------
            This party is just getting started!
            --------------------------
            if the party has cheese, print out each cheese pointed to by the pointers in the array where it isn't nullptr
            --------------------------
            Cheese Party
            --------------------------
            CHEESE1 DETAILS
            CHEESE2 DETAILS
            ...
            --------------------------
        */

        oo << "--------------------------" << endl;
        oo << "Cheese Party" << endl;
        oo << "--------------------------" << endl;
        if(!that.m_numCheeses == 0)
        {
            for (size_t i = 0; i < that.m_numCheeses; ++i)
            {
                if(that.m_cheeses[i] != nullptr)
                    oo << *that.m_cheeses[i];
            }
        }
        else
        {
           oo << "This party is just getting started!" << endl;
        }
        oo << "--------------------------" << endl;
        return oo;
    }
}