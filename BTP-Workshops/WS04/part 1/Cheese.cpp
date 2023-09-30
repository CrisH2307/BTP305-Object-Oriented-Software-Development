/*
*****************************************************************************
                              Chesse.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Cheese.h"

using namespace std;

namespace sdds 
{
    Cheese::Cheese(): m_name("NaC"), m_weight(0), m_price(0.0), m_features("") { }

    Cheese::Cheese(const string& str) 
    {
        istringstream iss(str);
        string trash;

        getline(iss, trash, ',');
        size_t start = trash.find_first_not_of(' ');
        size_t end = trash.find_last_not_of(' ');
        m_name = trash.substr(start, end - start + 1);

        getline(iss, trash, ',');
        start = trash.find_first_not_of(' ');
        end = trash.find_last_not_of(' ');
        m_weight = stoul(trash.substr(start, end - start + 1));

        getline(iss, trash, ',');
        start = trash.find_first_not_of(' ');
        end = trash.find_last_not_of(' ');
        m_price = stod(trash.substr(start, end - start + 1));

        getline(iss, trash);
        start = trash.find_first_not_of(' ');
        end = trash.find_last_not_of(' ');

        getline(iss, trash);
                // Clean up features
        std::string cleanedFeatures;
        bool spaceEncountered = false;

        for (char c : trash) {
            if (c != ',' && c != ' ') {
                // If character is not a comma or space, add it to cleanedFeatures
                cleanedFeatures.push_back(c);
                spaceEncountered = false;
            } else if (c == ' ') {
                // If character is a space, add it only if it's not preceded by another space or a comma
                if (!spaceEncountered && !cleanedFeatures.empty() && cleanedFeatures.back() != ',') {
                    cleanedFeatures.push_back(c);
                }
                spaceEncountered = true;
            } else if (c == ',') {
                // If character is a comma, add a single space
                cleanedFeatures.push_back(' ');
                spaceEncountered = true;
            }
        }

        // Remove leading and trailing spaces from features
        start = cleanedFeatures.find_first_not_of(' ');
        end = cleanedFeatures.find_last_not_of(' ');
        cleanedFeatures = cleanedFeatures.substr(start, end - start + 1);

        // Remove extra spaces between words
        size_t i = 0;
        while (i < cleanedFeatures.size()) {
            if (cleanedFeatures[i] == ' ' && cleanedFeatures[i + 1] == ' ') {
                cleanedFeatures.erase(i, 1);
            } else {
                ++i;
            }
        }

        m_features = cleanedFeatures;
    }

    Cheese Cheese::slice(size_t weight)
    {
        if(weight <= static_cast<size_t>(this->m_weight))
        {
            Cheese newCheese;
            newCheese.m_name = m_name;
            newCheese.m_weight = weight;
            newCheese.m_price = m_price;
            newCheese.m_features = m_features;
            m_weight -= weight;

            return newCheese;
        }
        else
        {
            return Cheese();
        }

    }
        
    string Cheese::getName() const
    {
        return m_name;
    }

    int Cheese::getWeight() const
    {
        return m_weight;
    }

    double Cheese::getPrice()const
    {
        return m_price;
    }

    string Cheese::getFeature()const
    {
        return m_features;
    }

    ostream& operator<<(ostream& oo, const Cheese& that)
    {
        if(!that.getName().empty())
        {
            oo << "|";
            oo.width(21);
            oo << left << that.getName();
            oo << "|";
            oo.width(5);
            oo << that.getWeight();
            oo << "|";
            oo.width(5);
            oo << fixed << setprecision(2) << that.getPrice();
            oo << "|";
            oo.width(33);
            oo << right << that.getFeature();
            oo << " |";
            oo << endl;
        }
        return oo;
    }   
}
