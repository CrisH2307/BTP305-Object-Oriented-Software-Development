/*
*****************************************************************************
                              Book.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include "SpellChecker.h"

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{
    class Book
    {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_des{};

    public:
        Book() = default;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();


        Book(const std::string& strBook);

        friend std::ostream& operator<<(std::ostream& o, const Book& that);


        //! PART 2
        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_des);
        }

    };
}


#endif