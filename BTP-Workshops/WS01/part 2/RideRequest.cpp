/*
*****************************************************************************
                              RideRequest.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "RideRequest.h"
using namespace std;
double g_taxrate = 0.0; 
double g_discount = 0.0; 
namespace sdds
{
    int RideRequest::counter = 0;


    RideRequest::RideRequest() : m_customer(), m_detail(nullptr), m_price(0.0), m_discount(false) {}

    void RideRequest::read(istream& is)
    {
        //todo: read(): a modifier that receives an istream reference.
        /*
        + If the istream is in a good state, this function will attempt to read from the istream and store the
        information read into the current object. The data read in will be in the following format:
            <Customer Name>,<Ride Description>,<Rate>,<Discount Status>[newline]
        The discount status can be of two values: 'Y' if a discount should be applied and 'N' otherwise.
        
        If the istream object is not in a good state then this function will do nothing.
        */

         // Initialize variables
          strcpy(m_customer, ""); // Initialize m_customer to an empty string
          char discount = 'N';    // Initialize discount to 'N' by default

          // Read data from the stream
          if (!is.fail())
          {
               std::string detailString;

               is.getline(this->m_customer, 11, ',');
               getline(is, detailString, ',');

               if (m_detail != nullptr)
               {
                    delete[] m_detail;
               }
               m_detail = new char[detailString.length() + 1];
               strcpy(m_detail, detailString.c_str());

               is >> m_price;
               is.ignore(1);

               is.get(discount);

               if (discount == 'Y')
               {
                    m_discount = true;
               }
               else if (discount == 'N')
               {
                    m_discount = false;
               }
          }
     }

    void RideRequest::display() const
    {
        //todo: a query that displays to the screen the content of an Ride Request instance in the following format:
        /*
        COUNTER. CUSTOMER_NAME|RIDE_DESCRIPTION|PRICE_WITH_TAX|PRICE_WITH_DISCOUNT

        If no customer name has been stored in the current object, this query should print:
        COUNTER. No Ride Request

        where

        + COUNTER is a left aligned field of size 2, that holds the number of times that this function has been called 
        (use a local-to-function variable that remains in memory for the lifetime of the program) Do not use global/member 
        variables to store the counter!
        + CUSTOMER_NAME is a left aligned field of size 10 that represents the name of the customer that made the order.
        + RIDE_DESCRIPTION is a left aligned field of size 25 that represents the description of the ride requested.
        + PRICE_WITH_TAX is a left aligned field of size 12 with 2 decimal point precision that represents the rate of the 
        ride requested with tax calculated based on the current tax rate.
        + PRICE_WITH_DISCOUNT is a right aligned field of size 13 that represents the taxed price of the ride request with the 
        discount applied on top for special customers. If the ride isn't discounted, then nothing is printed here.
        */

       static int counter {1};
       const int COUNTER = 2;
       const int CUSTOMER_NAME = 10;
       const int RIDE_DESCRIPTION = 25;
       const int PRICE_WITH_TAX = 12;
       const int PRICE_WITH_DISCOUNT = 13;

       cout.setf(ios::left);
       cout.width(COUNTER);
       cout << counter << ". ";


       if (m_customer[0] == '\0') 
       {
            cout << "No Ride Request" << std::endl;
       }
       else
       {
            double priceWithTax = m_price * (1.0 + g_taxrate);
   
            cout.width(CUSTOMER_NAME);
            cout << m_customer;
            cout << "|";

            cout.width(RIDE_DESCRIPTION);
            cout << m_detail;
            cout << "|";

            cout.width(PRICE_WITH_TAX);
            cout << fixed;
            cout.precision(2);
            cout << priceWithTax;
            cout << "|";
            cout.unsetf(ios::left);
            
           if (m_discount)
           {
                cout.setf(ios::right);
                cout.width(PRICE_WITH_DISCOUNT);
                cout << fixed;
                cout.precision(2);
                cout << m_price + ((m_price * g_taxrate) - g_discount);
                cout.unsetf(ios::right);
           }
            cout << endl;
       }
       counter++;
    }

    RideRequest& RideRequest::operator=(const RideRequest& that)
    {
          if (this != &that)
          {
               delete [] this->m_detail; 
               strcpy(this->m_customer, that.m_customer); 
               this->m_discount = that.m_discount; 
               this->m_price = that.m_price; 


               if (that.m_detail != nullptr)
               {
                    this->m_detail = new char [strlen(that.m_detail) +1]; 
                    strcpy(this->m_detail, that.m_detail); 
               }
               else 
               {
                    this->m_detail = nullptr; 
               }

          }
          return *this;
    }

     RideRequest::RideRequest(const RideRequest& that):  m_customer(), m_detail(nullptr), m_price(0.0), m_discount(false) 
     {  
          *this = that;
     }

     RideRequest::~RideRequest()
     {
        delete[] m_detail;
        m_detail = nullptr;
        m_customer[0] = '\0';
        m_price = 0.0;
        m_discount = false;
     }
}