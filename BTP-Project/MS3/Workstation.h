//                 WorkStation.h
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include "Station.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <deque>
#include <string>
namespace sdds
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;
 
    //! Each Workstation is-a-kind-of Station  --> WorkStation is the inheritance of Station
    class Workstation : public Station
    {
    private:
        std::deque<CustomerOrder> m_order;
        Workstation* m_pNextStation;

    public:
        Workstation(std::string& thatWorkstation);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif