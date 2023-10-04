/*
*****************************************************************************
                              ChesseParty.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

/*
! Instruction:
This class should have attributes to store and manage a dynamically-allocated array of pointers to objects of type Cheese: const sdds::Cheese** 
(each element of the array points to an object of type Cheese). Very Important: This class is responsible for managing the array of pointers but 
is not managing the life of Cheese objects


! Road Map
_ The m_pCheeses attribute is a ptr that stores the address of an array of n ptrs
_ Each element of the array is a ptr to and obj of Cheese
_ Both CheeseShop and CheeseParty classes will create the array dynamically, that is a src that both classes will have to manage
    ?--> The CheeseShop dynamically create copies of the cheeses that the client provides
    ?    there is also resources that the class must manage ---> THIS IS COMPOSITION

    ?--> The CheeseParty will store the address of the cheeses that the client provides
    ?    The Cheese objs will be managed by the client  --> THIS IS AGGREGATION

    !  Explain:
    *    If CheeseShop is responsible for creating and managing its own Cheese objects, it is a composition relationship. 
    *    The Cheese objects are part of the essential structure of the CheeseShop class.

    *    If CheeseParty class only stores the addresses of Cheese objects provided by the 
    *    client without managing their creation or destruction, it is an aggregation relationship. 
    *    Cheese objects are related to the CheeseParty class, but they are not part of its essential 
    *    structure; they are merely associated with the class.
    * 
    *    CheeseShop will manage whole object of Cheese while CheeseParty will manage the array of CheeseShop

*/

#include <iostream>
#include <string>

#ifndef SDDS_CHESSEPARTY_H
#define SDDS_CHEESEPARTY_H

namespace sdds 
{
    class CheeseParty //*--> Only manage the array
    {
        const Cheese** m_cheeses{}; // Dynamically allocated array of pointers to Cheese objects
        size_t m_numCheeses{}; // Number of Cheese objects in the array

    public:
        CheeseParty();
        CheeseParty& addCheese(const sdds::Cheese& that);
        CheeseParty& removeCheese();

         //?  Rule of 6
        CheeseParty(const CheeseParty& that);
        CheeseParty& operator=(const CheeseParty& that);
        ~CheeseParty();
        CheeseParty(CheeseParty&& that);
        CheeseParty& operator=(CheeseParty&& that);

        friend std::ostream& operator<<(std::ostream& oo, const CheeseParty& that);

    };
}

#endif