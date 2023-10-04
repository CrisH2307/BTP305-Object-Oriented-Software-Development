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
        //TODO
        /*
        Cheese(const std::string& str): A constructor that receives the cheese's details as a string; this 
        constructor is responsible for extracting information about the cheese from the string and storing the 
        tokens in the instance's attributes. The string will always have the following format:

        Name,Weight,Price,Features
        Every token that follows the price is a feature of the cheese (e.g., for "Cheddar, 1200, 2.99, Hard, Sharp, Smooth" 
        the features are Hard, Sharp, and Smooth). Each of extracted tokens should be stored in the respective data member; 
        the features should be stored as a space separated list of strings (e.g., "Hard Sharp Smooth").

        This constructor should remove all leading and trailing spaces from the beginning and end of any token extracted from parameter.

        When implementing the constructor, consider these following functions:

        std::string::substr()
        std::string::find()
        std::string::find_first_of()
        std::string::erase()
        std::stoul()
        std::stod()
        */

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
        //TODO
        /*
        Cheese slice(size_t weight): a modifier that receives as a parameter a weight/amount of cheese
        to slice from the current cheese object.

        If there is enough cheese to make this slice (weight <= weight of the cheese in current object), 
        then return a copy of current cheese with the desired weight. Update the current object's weight after slicing.

        If there isn't enough cheese, then return a cheese object that is in an empty state instead.
        */

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
        
    //TODO: A set of queries to retrieve the value of each attribute of the cheese.
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
        //TODO: Overload the insertion operator to insert the contents of a Cheese object into an ostream object in the following format:
        /*
        A vertical bar "|"
        The name of the cheese in left alignment and a field width of 21
        A vertical bar "|"
        The weight of the cheese with a field width of 5
        A vertical bar "|"
        The price of the cheese in fixed format, 2 decimal place precision and a field width of 5
        A vertical bar "|"
        The features of the cheese in right alignment and a field width of 34
        A vertical bar "|"
        A newline
        Look in the sample output file for hints about formatting
        */
       
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