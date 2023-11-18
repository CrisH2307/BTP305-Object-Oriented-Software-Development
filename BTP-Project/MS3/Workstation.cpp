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
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& thatWorkstation) : Station(thatWorkstation){}

    void Workstation::fill(std::ostream& os)
    {
        /*
        This modifier fills the order at the front of the queue if there are CustomerOrders in the queue; 
        otherwise, does nothing.
        */

        if (not(m_order).empty())
        {
            this->m_order.front().fillItem(*this, os);
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

        // Check if there is an order at the current station
        if (not(this->m_order.empty()))
        {
            // Check if the order requires no more service at this station or cannot be filled
            if (this->m_order.front().isItemFilled(this->getItemName()) or this->getQuantity() <= 0)
            {
                // Check if there is a next station
                if (m_pNextStation)
                {
                    // Move the order to the next station
                    *m_pNextStation += std::move(this->m_order.front());
                    this->m_order.pop_front();
                }
                else
                {
                    // Check if the order is completed or incomplete
                    if (this->m_order.front().isOrderFilled())
                    {
                        g_completed.push_back(std::move(this->m_order.front()));
                    }
                    else
                    {
                        g_incomplete.push_back(std::move(this->m_order.front()));
                    }

                    // Remove the order from the current station
                    this->m_order.pop_front();
                }

                // Set the flag to indicate success
                ok = true;
            }
        }

        // Return the result
        return ok;

    }

    void Workstation::setNextStation(Workstation* station)
    {
        /*
        This modifier stores the address of the referenced Workstation object in the pointer to the 
        m_pNextStation. Parameter defaults to nullptr.
        */

        this->m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        //todo: This query returns the address of next Workstation
        return this->m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        //todo: This query inserts the name of the Item for which the current object is responsible into stream os following the format: 
        /*
                            ITEM_NAME --> NEXT_ITEM_NAME
        If the current object is the last Workstation in the assembly line this query inserts: ITEM_NAME --> End of Line.
        In either case, the message is terminated with \n
        
        */
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
        //todo: Moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
        this->m_order.push_back(std::move(newOrder));
        return *this;
    }
}