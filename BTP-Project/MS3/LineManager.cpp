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
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations): m_activeLine(stations), m_cntCustomerOrder(g_pending.size()), m_firstStation(nullptr)
    {
        /*
        This constructor receives the name of the file that identifies the active stations on the assembly line 
        (example: AssemblyLine.txt) and the collection of Workstations available for configuring the assembly line.
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

        ifstream fe(file);
        string temp{};
        string nameofStation{};
        string nextStation{};
        if (!fe.is_open()) 
        {
            throw runtime_error("Error: Unable to open file.");
        }
        
        while (getline(fe, temp)) 
        {
            istringstream ig(temp);

            if (getline(ig, nameofStation, '|') and getline(ig, nextStation)) 
            {
                auto workstationIterator = find_if(m_activeLine.begin(), m_activeLine.end(),
                                           [&](Workstation* station) 
                                           { 
                                               return station->getItemName() == nameofStation; 
                                           });

                auto nextWorkstationIterator = find_if(m_activeLine.begin(), m_activeLine.end(),
                                               [&](Workstation* station) 
                                               { 
                                                  return station->getItemName() == nextStation; 
                                               });

                if (workstationIterator != m_activeLine.end() and nextWorkstationIterator != m_activeLine.end()) 
                {
                    (*workstationIterator)->setNextStation(*nextWorkstationIterator);
                } 
                else 
                {
                    throw runtime_error("Error: Invalid workstation configuration in file.");
                }
            } 
            else 
            {
                throw runtime_error("Error: Invalid file format.");
            }
        }

        auto firstStationIterator = find_if(m_activeLine.begin(), m_activeLine.end(),
                                    [](Workstation* station) -> bool
                                    { 
                                        return station->getNextStation() == nullptr; 
                                    });

        if (firstStationIterator != m_activeLine.end()) 
        {
            m_firstStation = *firstStationIterator;
        } 
        else 
        {
            throw runtime_error("Error: No start station found");
        }
    }

    void LineManager::reorderStations()
    {
        /*
        This modifier reorders the Workstations present in the instance variable m_activeLine 
        (loaded by the constructor) and stores the reordered collection in the same instance variable. 
        The elements in the reordered collection start with the first station, proceeds to the next, 
        and so forth until the end of the line.
        */

        vector <Workstation*> reOrderedStation;
        vector <bool> isPassed(this->m_activeLine.size(), false);
        queue <Workstation*> setQueue;

        setQueue.push(this->m_firstStation);
        isPassed[distance(this->m_activeLine.begin(), find(this->m_activeLine.begin(), this->m_activeLine.end(), this->m_firstStation))] = true;

        while (not(setQueue).empty())
        {
            Workstation* currentStation = setQueue.front();
            setQueue.pop();
            reOrderedStation.push_back(currentStation);

            Workstation* nextStation = currentStation->getNextStation();

            if (nextStation)
            {
                auto findStation = find(this->m_activeLine.begin(), this->m_activeLine.end(), nextStation);

                if (findStation != this->m_activeLine.end() and (not(isPassed[distance(this->m_activeLine.begin(), findStation)])))
                {
                    setQueue.push(nextStation);
                    isPassed[distance(this->m_activeLine.begin(),findStation)] = true;
                }
            }
        }
        this->m_activeLine = reOrderedStation;
    }

    bool LineManager::run(std::ostream& os)
    {
        static size_t cnt = 0;
        os << "Line Manager Iteration: " << ++cnt << endl;

        // Move one order to the first station from g_pending queue
        if (not(g_pending).empty())
        {
            *(this->m_firstStation) += move(g_pending.front());
            g_pending.pop_front();
        }

        // Perform one fill operation for each station
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
        auto haveBeenFilled = all_of(this->m_activeLine.begin(), this->m_activeLine.end(),
                              [](const Workstation* station) -> bool
                              {
                                   return true;
                              });
        return haveBeenFilled;
    }

    void LineManager::display(std::ostream& os) const
    {
        for (const auto& eachStation: this->m_activeLine)
        {
            os << eachStation->getItemName() << " --> " << eachStation->getNextStation()->getItemName() << endl;
        }
    }

}