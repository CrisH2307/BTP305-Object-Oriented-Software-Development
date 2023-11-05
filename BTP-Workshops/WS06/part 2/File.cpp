/*
*****************************************************************************
								File.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include "File.h"

using namespace std;
namespace sdds
{
        File::File(const std::string& filename, const std::string& contents): m_name (filename) , m_contents(contents) {}

        void File::update_parent_path(const std::string& that) { m_parent_path = that; }

        NodeType File::type() const { return NodeType::FILE; }

        std::string File::path() const { return m_parent_path + m_name; }

        std::string File::name() const { return m_name; }

        int File::count() const { return -1; }

        size_t File::size() const { return (this->m_contents).size(); }
}