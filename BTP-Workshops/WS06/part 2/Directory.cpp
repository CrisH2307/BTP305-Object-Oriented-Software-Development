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
                    if (found)
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

    void Directory::remove(const std::string& that, const std::vector<OpFlags>& redFlag)
    {
        //todo: deletes a resource from the directory whose name matches the first argument (removing it from its contents and deallocating memory for it).
        /*
        + If the matched resource is a directory, the RECURSIVE flag must be set, otherwise this member reports 
        an std::invalid_argument exception with the message NAME is a directory. Pass the recursive flag to delete directories.".
        + If no matching resource is found, report an exception of type std::string with the message NAME 
        does not exist in DIRECTORY_NAME.
        + The second argument is optional, with a default value an empty collection.
        */

        auto removeItem = find(that, redFlag);

        if (that.empty()) 
        {
            throw std::invalid_argument("Invalid argument: empty resource name");
        }

        if (!removeItem) 
        {
            throw std::invalid_argument(that + " does not exist in " + m_name);
        }

        if (removeItem->type() == NodeType::DIR) 
        {
            if (std::find(redFlag.begin(), redFlag.end(), OpFlags::RECURSIVE) == redFlag.end()) 
            {
                throw std::invalid_argument(that + " is a directory. Pass the recursive flag to delete directories.");
            }
        }

        m_contents.erase(std::remove(m_contents.begin(), m_contents.end(), removeItem), m_contents.end());

        delete removeItem; 
    }

    void Directory::display(std::ostream& o, const std::vector<FormatFlags>& redFlag) const
    {
        /*
        First inserts Total size: XX bytes and a newline into the output stream where XX is the size of the directory.

        For each resource in the directory, first add F or D to the output stream based on the resource type, 
        then add the resource information to the output stream in the following format:

        D | DIR_NAME |
        or

        F | FILE_NAME |
        where the name of the resource is left-aligned within a field width of 15 characters.

        If the LONG flag is in the second parameter, insert into the output stream additional information about the resource:

        D | DIR_NAME | COUNT | XX bytes |
        or

        F | FILE_NAME |    | XX bytes |
        where COUNT (right-aligned field with width of 2) is the number of resources in a directory, and XX bytes 
        (right-aligned with a width of 10) is the size of the resource in bytes.

        The second argument is optional, with a default value an empty collection.   
        */
        size_t totalSize = 0;
        for (const auto& thatRes : this->m_contents)
        {
            totalSize += thatRes->size();
        }

        o << "Total size: " << totalSize << " bytes" << endl;

        for (const auto& thatRes : this->m_contents)
        {
            o << (dynamic_cast<Directory*>(thatRes) ? "D" : "F");
            o << " | ";
            o << left;
            o.width(15);
            o << thatRes->name();
            o << " |";

            // For LONG flag
            if (std::find(redFlag.begin(), redFlag.end(), FormatFlags::LONG) != redFlag.end())
            {
                if (dynamic_cast<Directory*>(thatRes))
                {
                    o.width(3);
                    o << right << dynamic_cast<Directory*>(thatRes)->count();
                    o << " |";
                    
                    o.width(5);
                    o << right << thatRes->size() << " bytes";
                    o << " | ";
                }
                else
                {
                    o << "    |";
                    o.width(5);
                    o << right << thatRes->size() << " bytes";
                    o << " | ";
                }
            }
            o << endl;
        }
    }
}