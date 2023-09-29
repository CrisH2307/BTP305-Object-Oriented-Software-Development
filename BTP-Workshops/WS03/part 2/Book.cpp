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
#include <iomanip>
#include "Book.h"
#include <string>
using namespace std;

namespace sdds
{
    Book::Book() : m_title(""), m_numChapters(0.0), m_numPages(0.0)
    {

    }

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
    :  m_title(title), m_numChapters(nChapters), m_numPages(nPages)
    {
        
    }


    std::ostream& Book::print(std::ostream& os) const
    {
        double avg = double(m_numPages) / double(m_numChapters);
        if (!m_title.empty())
        {
            if (m_numChapters > 9)
            {
                os.width(49);
            }
            else
            {
                os.width(50);
            }
                os.setf(ios::right);
                os << m_title << "," << m_numChapters << "," << m_numPages;
                os << " | ";
                os.unsetf(ios::right);
                os.setf(ios::left);
                os.setf(ios::fixed);

                string average;
                average = "(";
                average += std::to_string(avg);
                average += ")";

                os << setw(15) << average;
                os.unsetf(ios::left); 
                os.unsetf(ios::fixed);  
        }
        else
        {
            os << "| Invalid book data";
        }
        return os;
    }

    bool Book::operator<(const Book& that) const 
    {
        return double(m_numPages) / double(m_numChapters) < (double)that.m_numPages/(double)that.m_numChapters;
    }

    bool Book::operator>(const Book& that) const 
    {
        return double(m_numPages) / double(m_numChapters) > (double)that.m_numPages / (double)that.m_numChapters;
    }
        

    std::ostream& operator<<(std::ostream& os, const Book& bk)
    {
        return bk.print(os);
    }
}