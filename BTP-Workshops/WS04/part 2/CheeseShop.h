/*
*****************************************************************************
                              ChesseShop.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <string>
#include "Cheese.h"

#ifndef SDDS_CHESSESHOP_H
#define SDDS_CHEESESHOP_H

namespace sdds 
{
    class CheeseShop  //*--> Delete and manage the array and obj
    {
        std::string m_shop{};
        const Cheese** m_cheeses{}; // Array of pointers to Cheese objects
        size_t m_numCheeses{}; // Number of cheeses in the shop
    
    public:
        CheeseShop(const std::string& name = "No Name");
        CheeseShop& addCheese(const sdds::Cheese& that);

        //?  Rule of 6
        CheeseShop();
        CheeseShop(const CheeseShop& that);
        CheeseShop& operator=(const CheeseShop& that);
        ~CheeseShop();
        CheeseShop(CheeseShop&& that);
        CheeseShop& operator=(CheeseShop&& that);


        friend std::ostream& operator<<(std::ostream& oo, const CheeseShop& that);
    };
}

#endif