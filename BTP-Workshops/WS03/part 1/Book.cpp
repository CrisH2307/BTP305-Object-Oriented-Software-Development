/*
*****************************************************************************
                              Book.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

namespace sdds
{
    Book::Book() : m_title(nullptr), m_numChapters(0.0), m_numPages(0.0)
    {

    }

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
    :  m_title(title), m_numChapters(nChapters), m_numPages(nPages)
    {
        
    }


    std::ostream& Book::print(std::ostream& os) const
    {
        double avg = m_numPages / m_numChapters;
        if (!m_title.empty())
        {
            os.width(50);//
            os.setf(ios::right);
            os << right << m_title;
            os << "," << m_numChapters << "," << m_numPages;
            os << " | ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os << "(" << fixed << os.precision(6) << avg << ")";
            os.unsetf(ios::left);
            os.width(4);
        }
        return os;
    }
        

    std::ostream& operator<<(std::ostream& os, const Book& bk)
    {
        return bk.print(os);
    }
}