//                  lineManager.cpp
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
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;
namespace sdds
{    
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        /*
        
        This constructor receives the name of the file that identifies the active stations on the assembly line 
        (example: AssemblyLine. txt) and the collection of Workstations available for configuring the assembly line.
        The file contains the linkage between Workstation pairs. The format of each record in the file is 
        Workstation|NEXT_Workstation. The records themselves are not in any particular order.
        This function stores the Workstations in the order received from the file in the m_activeLine instance variable. 
        It loads the contents of the file, stores the address of the next Workstation in each element of the collection, 
        identifies the first station in the assembly line and stores its address in the m_firstStation attribute. 
        This function also updates the attribute that holds the total number of orders in the g_pending queue. 
        If something goes wrong, this constructor reports an error.

        ! Note:
        To receive full marks, use STL algorithms throughout this function, except for iterating through the file records 
        (one while loop); marks will be deducted if you use any of for, while or do-while loops except for iterating through the file records.
    
         */
        
        std::ifstream oy(file, std::ios::in | std::ios::out);
        Utilities u;
        std::string line{};
        std::string thisItem{};
        std::string nextItem{};

        // I will use the ptr to move the station
        Workstation* thisWorkStation{};
        Workstation* nextWorkStation{};

        auto ok = [&oy]() { return oy.is_open(); };
        
        if (ok())
        {
            while (getline(oy, line))
            {
                bool more = true;
                size_t posn = 0;
                thisItem = u.extractToken(line, posn, more);

                // I will search the station to find the correct station that matches the thisItem

                auto thisStationIteration = std::find_if(stations.begin(), stations.end(),
                    [&](Workstation* that)
                    {
                        return that->getItemName() == thisItem;
                    });

                if (thisStationIteration != stations.end())
                {
                    thisWorkStation = *thisStationIteration;
                }
                this->m_activeLine.push_back(thisWorkStation);

                // Now as long as there is still bool to read from file, set the nextStation
                if (more)
                {
                    nextItem = u.extractToken(line, posn, more);
                    auto nextStationIteration = std::find_if(stations.begin(), stations.end(),
                        [&](Workstation* that)
                        {
                            return that->getItemName() == nextItem;
                        });

                    if (nextStationIteration != stations.end())
                    {
                        nextWorkStation = *nextStationIteration;
                    }
                    thisWorkStation->setNextStation(nextWorkStation);
                }
            }

            // Now we have to find the lastStation and set them to the first
            auto lastStationIteration = std::find_if(stations.begin(), stations.end(),
                [&](Workstation* that) 
                {
                    return std::find_if(m_activeLine.begin(), m_activeLine.end(),
                    [&](Workstation* station) 
                        {
                            return station->getNextStation() == that;
                        }) == m_activeLine.end();
                });

            if (lastStationIteration != stations.end()) 
            {
                m_firstStation = *lastStationIteration;
            }
        }
        else
        {
            throw "Can find the file";
        }

        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations()
    {
        /*
        This modifier reorders the Workstations present in the instance variable m_activeLine 
        (loaded by the constructor) and stores the reordered collection in the same instance variable. 
        The elements in the reordered collection start with the first station, proceeds to the next, 
        and so forth until the end of the line.
        */
        
        std::vector <Workstation*> reOrderedStation;

        Workstation* p_Workstation = m_firstStation;

        while(p_Workstation != nullptr)
        {
            reOrderedStation.push_back(p_Workstation);
            p_Workstation = p_Workstation->getNextStation();
        }
        this->m_activeLine = reOrderedStation;
    }

    bool LineManager::run(std::ostream& os)
    {
        //todo: This modifier performs one iteration of operations on all of the workstations in the current assembly line by doing the following:
        /*
        
        + keeps track of the current iteration number (use a local variable)
        + inserts into stream os the iteration number (how many times this function has been called by the client) 
        in the format Line Manager Iteration: COUNT<endl>
        + moves the order at the front of the g_pending queue to the m_firstStation and remove it from the queue. 
        This function moves only one order to the line on a single iteration.
        + for each station on the line, executes one fill operation
        + for each station on the line, attempts to move an order down the line
        + return true if all customer orders have been filled or cannot be filled, otherwise returns false.
         
        */
        static size_t cnt = 0;
        os << "Line Manager Iteration: " << ++cnt << endl;

        // Move one order to the first station from g_pending queue, as long as orders are still pending move one onto the line
        if (not(g_pending).empty())
        {
            //*(this->m_activeLine).front() += std::move(g_pending.front());
            *(this->m_firstStation) += std::move(g_pending.front());
            g_pending.pop_front();
        }

        // Perform one fill operation for each station, attempt to fill then move an order along the line
        for (auto& eachStation: this->m_activeLine)
        {
            eachStation->fill(os);
        }

        // Attempt to move orders down the line for eachStation
        for (auto& eachStation: this->m_activeLine)
        {
            eachStation->attemptToMoveOrder();
        }

        // Check if all customer orders have been filled using lambda
        auto ok = [&]() -> bool
        {
            return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
        };
        return ok();
    }

    void LineManager::display(std::ostream& os) const
    {
        //todo: This query displays all active stations on the assembly line in their current order
        for (auto& eachStation : m_activeLine)  { eachStation->display(os); }
    }

}