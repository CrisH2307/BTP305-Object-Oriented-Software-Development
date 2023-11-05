/*
*****************************************************************************
								FileSystem.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef _SDDS_FILESYSTEM_H
#define _SDDS_FILESYSTEM_H 

#include <iostream>
#include <string>
#include <vector>
#include "Resource.h"
#include "File.h"
#include "Flags.h"
#include "Directory.h"

namespace sdds 
{
    class Filesystem
    {
    private:
        Directory* m_root {};
        Directory* m_current{};
    public:
        Filesystem(const std::string& filename, const std::string& rootName = "");

        //! Rules of FIVE
        Filesystem(const Filesystem& that) = delete;
        Filesystem& operator=(const Filesystem& that) = delete;
        Filesystem(Filesystem&& that) noexcept;
        Filesystem& operator=(Filesystem&& that) noexcept;
        ~Filesystem();

        Filesystem& operator+=(Resource* that);
        Directory* change_directory(const std::string& that = "");
        Directory* get_current_directory() const;


    };
}

#endif