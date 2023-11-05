/*
*****************************************************************************
								File.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef _SDDS_FILE_H
#define _SDDS_FILE_H

#include <iostream>
#include <string>
#include "Resource.h"
#include "Flags.h"

namespace sdds 
{
    class File : public Resource
    {
        std::string m_name{};
        std::string m_contents{};
        std::string m_parent_path{};
    
    public:
        File(const std::string& filename, const std::string& contents = "");
        void update_parent_path(const std::string& that) override;
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;
    };
}
#endif