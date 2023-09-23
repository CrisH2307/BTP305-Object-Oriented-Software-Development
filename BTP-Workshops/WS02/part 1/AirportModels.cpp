/*
*****************************************************************************
                              AirportModels.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include "AirportModels.h"

using namespace std;

namespace sdds
{
    //*------------------------------- AIRPORT MODULE ----------------------------------------//
    ostream& operator<<(ostream& oo, const Airport& that)
    {
    //todo: Overload the insertion operator to output an Airport object to an output stream. 

       /*
        If a given Airport object is in an empty state then this overload will print out:

        Empty Airport
        If the object is not in an empty state then it will insert into the stream the content 
        of the object in the following format:

        Airport Code : <CODE>
        Airport Name : <NAME>
        Airport City : <CITY>
        Airport State : <STATE>
        Airport Country : <COUNTRY>
        Airport Latitude : <LATITUDE>
        Airport Longitude : <LONGITUDE>
        The formatting details for the attributes printed out are:

        All labels will be aligned to the right, on a field of exactly 20 characters wide
        All values will be aligned to the left, on a field of exactly 30 characters wide
        the label is separated from the value by : (space-colon-space)
        the filling character is a dot (.)
        */

        if(!that.m_code.empty())
        {
            
            // Code
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "Airport Code";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_code;
            oo << endl;

            // Name
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "Airport Name";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_name;
            oo << endl;

            // City
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "City";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_city;
            oo << endl;

            // State
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "State";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_state;
            oo << endl;

            // Country
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "Country";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_country;
            oo << endl;

            // Latitude
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "Latitude";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_latitude;
            oo << endl;

            // Longtitude
            oo.fill('.');
            oo.width(20);
            oo << right;
            oo << "Longitude";
            oo << " : ";
            oo << left;
            oo.width(30);
            oo << that.m_longitude;
            oo << endl;
        }
        else
        {
            oo << "Empty Airport";
        }
        return oo;
    }

    //*------------------------------- AIRPORTLOG MODULE ----------------------------------------//
    AirportLog::AirportLog()
    {
        airport = nullptr;
        capacity = 0;
    }

    AirportLog::AirportLog(string filename) : AirportLog()
    {
        if(!filename.empty())
        {
            ifstream f(filename);

            // Count the number of airports in the file (excluding the header)
            size_t airportCnt = 0;
            string line = "";

            // Skip header line
            getline(f, line);

            while (getline(f, line))
            {
                if (!line.empty())
                {
                    airportCnt++;
                }
            }

            // Close the file and reset the file position to the beginning
            f.clear();
            f.seekg(0, ios::beg);

            this->airport = new Airport[airportCnt];
            this->capacity = airportCnt;

            getline(f, line);
            // Read data into the dynamic array
            for (size_t i = 0; i < airportCnt; ++i)
            {
                // Assuming data is comma-separated, modify this part based on your file format
                getline(f, airport[i].m_code, ',');
                getline(f, airport[i].m_name, ',');
                getline(f, airport[i].m_city, ',');
                getline(f, airport[i].m_state, ',');
                getline(f, airport[i].m_country, ',');
                f >> airport[i].m_latitude;
                f.ignore(1, ',');
                f >> airport[i].m_longitude;
                f.ignore(1, '\n');
            }

            // Close the file
            f.close();
        }

    }

    AirportLog::AirportLog(const AirportLog &that) : AirportLog()
    {
        delete[] airport; // Delete the existing dynamic array
        *this = that; // Reuse the copy assignment operator
    }

    AirportLog& AirportLog::operator=(const AirportLog &that)
    {
        if (this != &that) 
        {
            delete[] airport;
            airport = nullptr;

            capacity = that.capacity;
            airport = new Airport[that.capacity];

            for (size_t i = 0; i < capacity; ++i) 
            {
                airport[i] = that.airport[i];
            }
        }
        else
        {
            capacity = 0;
            airport = nullptr;
        }
        return *this;
    }

    AirportLog::~AirportLog()
    {
        delete[] airport;
        capacity = 0;
    }

    AirportLog::AirportLog(AirportLog&& that) : AirportLog()
    {
        *this = std::move(that);
    }

    AirportLog& AirportLog::operator=(AirportLog&& that) 
    {
        if (this != &that)
        {
            delete[] airport;
            
            this->capacity = that.capacity;
            this->airport = that.airport;

            that.airport = nullptr; // Set the source's pointer to nullptr
            that.capacity = 0;
        }
        return *this;
    }
        
    void AirportLog::addAirport(const Airport& that)
    {
        if (!that.m_code.empty())
        {
            // Create a new dynamic array with increased capacity
            Airport* thoseAirport = new Airport[capacity + 1];

            // Copy existing airports to the new array
            for (size_t i = 0; i < capacity; ++i)
            {
                thoseAirport[i] = airport[i];
            }

            // Add the new airport
            thoseAirport[capacity] = that;

            // Delete the old array and update to the new one
            delete[] airport;
            airport = thoseAirport;
            capacity++;
        }
    }
    
    AirportLog AirportLog::findAirport(string state, string country) const
    {
        AirportLog result;
   
        for (size_t i = 0; i < capacity; i++) 
        {
            if (strcmp(airport[i].m_state.c_str(), state.c_str()) == 0 && strcmp(airport[i].m_country.c_str(), country.c_str()) == 0) 
            {
                result.addAirport(airport[i]);
            }
        }
        return result;
    }
    
    Airport AirportLog::operator[](size_t index) const
    {
        if (index < capacity) 
        {
            return airport[index];
        } 
        else 
        {
            // Return an empty Airport object or handle it as per your design
            Airport emptyAirport;
            return emptyAirport;
        }
    }
    
    AirportLog::operator size_t() const
    {
        return this->capacity;
    }

}