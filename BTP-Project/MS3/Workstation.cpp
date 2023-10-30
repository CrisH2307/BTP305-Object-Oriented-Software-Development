//                  Workstation.cpp
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include "Workstation.h"
#include "LineManager.h"
#include "CustomerOrder.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
namespace sdds
{
    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_incomplete;

    Workstation::Workstation(std::string& thatWorkstation) : Station(thatWorkstation), m_pNextStation(nullptr) {}

    void Workstation::fill(std::ostream& os)
    {
        /*
        This modifier fills the order at the front of the queue if there are CustomerOrders in the queue; 
        otherwise, does nothing.
        */

        if (not(m_order).empty())
        {
            CustomerOrder& that = m_order.back();
            that.fillItem(*this, os);
            m_order.pop_back();
        }
    }

    bool Workstation::attemptToMoveOrder()
    {
    /*
    attempts to move the order order at the front of the queue to the next station in the assembly line:
    + if the order requires no more service at this station or cannot be filled (not enough inventory), 
    move it to the next station; otherwise do nothing
    + if there is no next station in the assembly line, then the order is moved into 
    g_completed or g_incomplete queue
    + if an order has been moved, return true; false otherwise.
    */

        bool ok = false;
    
        if (not(m_order).empty())
        {
            // Check if the order requires no more service at this station or cannot be filled
            if (this->m_pNextStation and this->m_order.back().isItemFilled(getItemName()))
            {
                // Move the order to the next station if available
                this->m_pNextStation->operator+=(move(this->m_order.back()));
            }
            else if (not(m_pNextStation))
            {
                // If there is no next station, move the order to appropriate global queue
                if (this->m_order.back().isItemFilled(getItemName()))
                {
                    g_completed.push_back(move(this->m_order.back()));
                }
                else
                {
                    g_incomplete.push_back(move(this->m_order.back()));
                }
            }
            // Remove the processed order from the queue
            m_order.pop_back();
            ok = true;
        }
        return ok;  
    }

    void Workstation::setNextStation(Workstation* station)
    {
        this->m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        return this->m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        os << this->getItemName() << " --> ";
        
        if (this->m_pNextStation)
        {
            os << this->m_pNextStation->getItemName();
        }
        else
        {
            os << "End of Line";
        }

        os << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
        this->m_order.push_front(move(newOrder));
        return *this;
    }
}