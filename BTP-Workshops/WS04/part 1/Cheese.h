/*
*****************************************************************************
                              Chesse.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <string>

#ifndef SDDS_CHESSE_H
#define SDDS_CHEESE_H

namespace sdds 
{
    class Cheese
    {
        std::string m_name;
        int m_weight;
        double m_price;
        std::string m_features;
    
    public:
        Cheese();
        Cheese(const std::string& str);
        Cheese slice(size_t weight);
        
        std::string getName() const;
        int getWeight() const;
        double getPrice()const;
        std::string getFeature()const;

        friend std::ostream& operator<<(std::ostream& oo, const Cheese& that);
    };


}

#endif