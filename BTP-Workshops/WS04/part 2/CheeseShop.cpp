/*
*****************************************************************************
                              Chesse.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "CheeseShop.h"
#include "Cheese.h"

using namespace std;

namespace sdds 
{
    CheeseShop::CheeseShop(const string& name)
    {
        //TODO: CheeseShop(const std::string& name)
        /*
        A constructor that receives as a parameter the name of 
        the shop. The default value for the parameter is "No Name".
        */

        m_shop = name;
    }

    CheeseShop& CheeseShop::addCheese(const sdds::Cheese& that)
    {
        //todo: CheeseShop& addCheese(const Cheese&)
        /*
        A modifier that adds a cheese object to the array of pointers.

        In order to add another cheese, this class should resize the array of pointers using DMA (dynamic memory allocation). 
        The CheeseShop will be adding/storing copies of the Cheese passed through the parameter.

        HINT: It may be helpful to review the w4_p1/p2.cpp files as they have examples on how to work with a dynamic 
        array of Cheese pointers (i.e., a double pointer).

        If you need a refresher on arrays of pointers, re-read the material from the last term 
        (chapter Abstract Base Classes, section Array of Pointers).
        */

        // Allocate memory for a new array of ptr with increased size
        const Cheese** CheeseisAdding = new const Cheese*[m_numCheeses + 1];
        for (size_t i = 0; i < m_numCheeses; ++i)
        {
            CheeseisAdding[i] = new Cheese(*m_cheeses[i]);
            //! Use const to copy through const pointer of array
        }
        // Allocate memory for the new Cheese object and add it to the array
        //* Assuming Cheese has a copy constructor
        CheeseisAdding[m_numCheeses] = new Cheese(that);
        // Deallocate old one and update
        for(size_t i = 0; i < m_numCheeses; ++i)
        {
            delete m_cheeses[i];
        }
        delete[]m_cheeses;
        m_cheeses = CheeseisAdding;
        ++m_numCheeses;

        return *this;
    }


    //*----------------------- RULES OF 6 --------------------------------//
    CheeseShop::CheeseShop(const CheeseShop& that)
    {
        *this = that;
    }

    CheeseShop& CheeseShop::operator=(const CheeseShop& that)
    {
        if (this != &that)
        {
            for (size_t i = 0; i < m_numCheeses; ++i)
            {
                delete m_cheeses[i];
            }

            delete[]m_cheeses;

            this->m_numCheeses = that.m_numCheeses;
            this->m_shop = that.m_shop;

            m_cheeses = new const Cheese*[that.m_numCheeses];
            /*
            !Explain:
            Since m_cheese seems to be the name of the member variable representing
            the dynamic alloccated array of const Cheese**.
            */

            for (size_t i = 0; i < m_numCheeses; ++i)
            {
                m_cheeses[i] = new Cheese(*(that.m_cheeses[i]));
                //or
                //anotherCheeseisHere[i] = new Cheese(*that.m_cheeses[i]);
            }          
        }
        return *this;

    }

    CheeseShop::~CheeseShop()
    {
        m_shop = "";
        
        for(size_t i = 0; i < m_numCheeses; ++i)
        {
            delete m_cheeses[i];
        }
        delete[]m_cheeses;

        m_numCheeses = 0;
    }

    CheeseShop::CheeseShop(CheeseShop&& that)
    {
        *this = move(that);
    }

    CheeseShop& CheeseShop::operator=(CheeseShop&& that)
    {
        if (this != &that)
        {
            for (size_t i = 0; i < m_numCheeses; ++i)
            {
                delete m_cheeses[i];
            }
            delete[]m_cheeses;

            this->m_shop = that.m_shop;
            this->m_cheeses = that.m_cheeses;
            this->m_numCheeses = that.m_numCheeses;

            that.m_shop = "";
            that.m_cheeses = nullptr;
            that.m_numCheeses = 0;
        }
        return *this;
    }

    //*----------------------- END OF RULES OF 6 --------------------------------//    

    ostream& operator<<(ostream& oo, const CheeseShop& that)
    {
        //todo: overload the insertion operator to insert the content of a CheeseShop object into an ostream object
        /*
            if the shop is out of cheese:
            --------------------------
            SHOP_NAME 
            --------------------------
            This shop is out of cheese!
            --------------------------
            if the shop has some cheese:
            --------------------------
            SHOP_NAME 
            --------------------------
            CHEESE1 DETAILS
            CHEESE2 DETAILS
            ...
            --------------------------
        */
        oo << "--------------------------" << endl;
        oo << that.m_shop << endl;
        oo << "--------------------------"<< endl;
        
        if(!that.m_numCheeses == 0)
        {
            for (size_t i = 0; i < that.m_numCheeses; ++i)
            {
                 oo << *that.m_cheeses[i];
            }
        }
        else
        {
           oo << "This shop is out of cheese!" << endl;
        }
        oo << "--------------------------" <<endl;
        return oo;
    }
    
}