/*
*****************************************************************************
                              RideRequest.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>
using namespace std;
    // Global variables for tax rate and discount
    extern double g_taxrate;
    extern double g_discount;
namespace sdds
{
    class RideRequest
    {
    private: 
        char m_customer[11];
        char* m_detail;
        double m_price;
        bool m_discount;

        static int counter; // Static counter to keep track of instances
    
    public:
        RideRequest();
        void read(istream& is);
        void display() const;
    };
    
} // namespace sdds

#endif