/*
*****************************************************************************
								FileSystem.cpp
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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Resource.h"
#include "File.h"
#include "Flags.h"
#include "Directory.h"
#include "Filesystem.h"
using namespace std;

namespace sdds
{
    Filesystem::Filesystem(const std::string& filename, const std::string& rootName) : m_root(new Directory(rootName)), m_current(m_root)
    {
        /*
        A custom constructor that receives the name of a file as its first argument, and an optional string 
        containing the name of the root directory (defaults to an empty string). This member first creates 
        a dynamically allocated Directory object to set as the root directory and the current working directory. 
        Then loads the content of the file: each line in the file represents a resource in the filesystem that 
        you must create using the appropriate class (File or Directory) and has one of the following formats:

        FILE_PATH | FILE_CONTENTS

        if the resource is a file, or

        DIRECTORY_PATH
        
        if the resource is a directory.

        FILE_PATH, is a path to a file from the root directory, e.g. images/file.png or file.png.
        FILE_CONTENTS, is a text representation of the contents of the file
        DIRECTORY_PATH, is a path to a directory from the root directory, e.g. documents/docs/.
        For each line, the constructor dynamically creates a new Directory for each component of the path 
        (separated by /) and links them together, with the first directory object being added to the root 
        directory. You must not create duplicates of the directories.

        For example, for images/pngs/file.png, if images already exists on the root directory, do not create a new one 
        (HINT: use the find() function for directories.). Then create pngs and add it as a resource to images and finally 
        create file.png and add it as a resource to pngs. You should also make sure to update the absolute location 
        path of each resource as you create them.

        NOTE: You must remove leading and trailing spaces from all paths and FILE_CONTENTS
        */
        ifstream file(filename);
        if (!file)
        {
            delete m_root;
            throw invalid_argument("Cannot open file!");
        }

        string temp{};
        while (getline(file, temp))
        {
            istringstream ig(temp);
            string PATH_NAME{};
            getline(ig, PATH_NAME, '|');
            PATH_NAME.erase(0, PATH_NAME.find_first_not_of(" "));
            PATH_NAME.erase(PATH_NAME.find_last_not_of(" ") + 1);

            if (PATH_NAME.empty())
            {
                continue;
            }

            string content{};
            if (ig)
            {
                getline(ig, content);
                content.erase(0, content.find_first_not_of(" "));
                content.erase(content.find_last_not_of(" ") + 1);
            }

            vector<string> components;
            stringstream c_ig(PATH_NAME);
            string item{};
            while (getline(c_ig, item, '/'))
            {
                (item.find(".") != string::npos) ? item = item : item += '/';
                components.push_back(item);
            }
            Directory *curDir = m_root;
            for (size_t i = 0; i < components.size() - 1; i++)
            {
                string dirName = components[i];
                Resource *dir = curDir->find(dirName, {});
                if (dir == nullptr) 
                {
                    dir = new Directory(dirName);
                    *curDir += dir;
                }
                curDir = dynamic_cast<Directory *>(dir);
            }

            string name = components.back();
            if (content.empty())
            {
                Resource *dir = curDir->find(name, {});
                if (dir == nullptr)
                {
                    dir = new Directory(name);
                    *curDir += dir;
                }
            }
            else
            {
                Resource *file = curDir->find(name, {});
                if (file == nullptr)
                {
                    file = new File(name, content);
                    *curDir += file;
                }
            }
        }
    }

    Filesystem::Filesystem(Filesystem&& that) noexcept
    {
        *this = move(that);
    }

    Filesystem& Filesystem::operator=(Filesystem&& that) noexcept   
    {
        if (this != &that)
        {
            delete m_root;

            this->m_root = that.m_root;
            this->m_current = that.m_current;

            that.m_root = nullptr;
            that.m_current = nullptr;
        }
        return *this;
    }

    Filesystem::~Filesystem()
    {
        //todo: A destructor that deallocates memory for the root directory.
        delete this->m_root;
    }

    Filesystem& Filesystem::operator+=(Resource* that)
    {
        //todo: Adds a resource to the current directory.
        if (that)
        {
            *this->m_current += that;
        }
        return *this;
    }

    Directory* Filesystem::change_directory(const std::string& that)
    {
        //todo: changes the current directory to the directory (located in the current directory) whose name matches argument.
        /*
        + the parameter is optional (defaults to an empty string).
        + if an empty string is passed, change the current directory to the root directory.
        + if no directory with the specified name exists (useDirectory::find() to locate the directory), 
        report an std::invalid_argument exception with the message Cannot change directory! DIR_NAME not found!".
        
        */
        if (that.empty())
        {
            this->m_current = this->m_root;
        }
        else
        {
            Directory* newDir = dynamic_cast<Directory*>((m_current->find(that)));

            if(newDir)
            {
                this->m_current = newDir;
            }
            else
            {
                throw std::invalid_argument("Cannot chnage directory! " + that + " not found!");
            }
        }
        return this->m_current;
    }

    Directory* Filesystem::get_current_directory() const
    {
        //todo: A query that returns the current directory.
        return this->m_current;
    }

}
