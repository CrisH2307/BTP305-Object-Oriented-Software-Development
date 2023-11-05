/*
*****************************************************************************
								Directory.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef _SDDS_DIRECTORY_H
#define _SDDS_DIRECTORY_H 

#include <iostream>
#include <string>
#include <vector>
#include "Resource.h"
#include "File.h"
#include "Flags.h"

namespace sdds 
{
    class Directory : public Resource
    {
        std::vector<Resource*> m_contents;

    public:
        explicit Directory(const std::string& contents);
        void update_parent_path(const std::string& that);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory& operator+=(Resource* that);
        Resource* find(const std::string& anotherOne, const std::vector<OpFlags>&redFlag = {});
        ~Directory();

        //! RULES OF FIVE
        Directory(const Directory& that) = delete;
        Directory& operator=(const Directory& that) = delete;
        Directory(Directory&& that) = delete;
        Directory& operator=(Directory&& that) = delete;

        //! Part 2
        void remove(const std::string& that, const std::vector<OpFlags>& redFlag = {});
        void display(std::ostream& o, const std::vector<FormatFlags>& redFlag = {}) const;
    };
}
#endif