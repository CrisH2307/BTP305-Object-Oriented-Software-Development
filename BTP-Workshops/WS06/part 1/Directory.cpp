/*
*****************************************************************************
								Directory.cpp
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
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Resource.h"
#include "File.h"
#include "Flags.h"
#include "Directory.h"
using namespace std;

namespace sdds
{
    Directory::Directory(const std::string& contents)
    {
        m_name = contents;
    }

    void Directory::update_parent_path(const std::string& that)
    {
        m_parent_path = that;
        for (auto &res : m_contents)
        {
            res->update_parent_path(this->path());
        }
    }

    NodeType Directory::type() const
    {
        return NodeType::DIR;
    }

    std::string Directory::path() const
    {
        return m_parent_path + m_name;
    }

    std::string Directory::name() const
    {
        return this->m_name;
    }

    int Directory::count() const
    {
        return static_cast<int>((m_contents).size());
    }

    size_t Directory::size() const
    {
        size_t SIZE = 0;
        for (Resource* res : this->m_contents)
        {
            SIZE += res->size();
        }
        return SIZE;        
    }

    Directory& Directory::operator+=(Resource* that)
    {
        for (const auto& res: this->m_contents)
        {
            if (res->name() == that->name())
            {
                throw "ERROR";
            }
        }

        that->update_parent_path(this->path());
        this->m_contents.push_back(that);       
        return *this;
    }

    Resource* Directory::find(const std::string& anotherOne , const std::vector<OpFlags>&redFlag)
    {
        for (auto& that : m_contents)
        {
            if (that->name() == anotherOne)
            {
                return that;
            }
            if (std::find(redFlag.begin(), redFlag.end(), OpFlags::RECURSIVE) != redFlag.end()) 
            {
                if (that->type() == NodeType::DIR)
                {
                    Resource* found = dynamic_cast<Directory*>(that)->find(anotherOne, redFlag);
                    return found;       
                }
            }
        }
        return nullptr;
    }

    Directory::~Directory()
    {
        for (auto &res: this->m_contents)
            delete res;
    }

}