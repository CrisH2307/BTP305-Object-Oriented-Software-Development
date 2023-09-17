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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AirportModels.h"
#include <fstream>
#include <sstream>

using namespace std;

namespace sdds
{
    //*------------------------------- AIRPORT MODULE ----------------------------------------//
    Airport::Airport() : a_code(nullptr), a_name(nullptr), a_city(nullptr), a_state(nullptr), a_country(nullptr), a_latitude(0.0), a_longitude(0.0)
    {
        
    }

    Airport::Airport(const Airport& that) : a_code(nullptr), a_name(nullptr), a_city(nullptr),
      a_state(nullptr), a_country(nullptr), a_latitude(0.0), a_longitude(0.0) 
    {
        *this = that;
    }

    Airport& Airport::operator=(const Airport& that)
    {
        if(this != &that)
        {
            this->a_latitude = that.a_latitude;
            this->a_longitude = that.a_longitude;

            delete[] this->a_code;
            delete[] this->a_name;
            delete[] this->a_city;
            delete[] this->a_state;
            delete[] this->a_country;

            if (that.a_code)
            {
                this->a_code = new char[strlen(that.a_code) + 1];
                strcpy(this->a_code, that.a_code);
            }

            if (that.a_name)
            {
                this->a_name = new char[strlen(that.a_name) + 1];
                strcpy(this->a_name, that.a_name);
            }

            if (that.a_city)
            {
                this->a_city = new char[strlen(that.a_city) + 1];
                strcpy(this->a_city, that.a_city);
            }

            if (that.a_state)
            {
                this->a_state = new char[strlen(that.a_state) + 1];
                strcpy(this->a_state, that.a_state);
            }

            if (that.a_country)
            {
                this->a_state = new char[strlen(that.a_state) + 1];
                strcpy(this->a_country, that.a_country);
            }
        }
        return *this;
    }

    Airport::~Airport()
    {
        delete[] this->a_code;
        delete[] this->a_name;
        delete[] this->a_city;
        delete[] this->a_state;
        delete[] this->a_country;
    }

    ostream& operator<<(std::ostream& oo, const Airport& that)
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

        if(that.a_name)
        {
            // Code
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport Code: ";
            oo << left;
            oo.width(30);
            oo << that.a_code;
            oo << endl;

            // Name
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport Name: ";
            oo << left;
            oo.width(30);
            oo << that.a_name;
            oo << endl;

            // City
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport City: ";
            oo << left;
            oo.width(30);
            oo << that.a_city;
            oo << endl;

            // State
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport State: ";
            oo << left;
            oo.width(30);
            oo << that.a_code;
            oo << endl;

            // Country
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport State: ";
            oo << left;
            oo.width(30);
            oo << that.a_state;
            oo << endl;

            // Latitude
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport Latitude: ";
            oo << left;
            oo.width(30);
            oo << that.a_latitude;
            oo << endl;

            // Longtitude
            oo.fill('.');
            oo << right;
            oo.width(20);
            oo << "Airport Longtitude: ";
            oo << left;
            oo.width(30);
            oo << that.a_longitude;
            oo << endl;
        }
        else
        {
            oo << "Empty Airport";
        }
        return oo;
    }

    Airport::operator bool()const
    {
        if (a_code != nullptr && 
            a_name != nullptr && 
            a_city != nullptr && 
            a_state != nullptr && 
            a_country != nullptr)
            {
                return true;
            }
        else
        {
            return false;
        }
    }

    //*------------------------------- AIRPORTLOG MODULE ----------------------------------------//
    AirportLog::AirportLog()
    {
        airport = nullptr;
        size = capacity = 0;
    }

    AirportLog::AirportLog(const char* filename) : airport(nullptr), size(0), capacity(0)
    {
        ifstream f(filename);

        if(!f.is_open())
        {  
            cout << "Error " << endl;
            return;
        }

        // Count the number of airports in the file (excluding the header)
        size_t airportCnt = 0;
        char line[256];

        // Skip header line
        f.getline(line, sizeof(line));

        while (f.getline(line, sizeof(line)))
        {
            airportCnt++;
        }

        // Close the file and reset the file position to the beginning
        f.close();
        f.open(filename);

        airport = new Airport[airportCnt];
        capacity = airportCnt;
        size = 0;

         // Read data into the dynamic array
        while (f.getline(line, sizeof(line))) 
        {
            if (size >= capacity) 
            {
                // Handle potential overflow
                cout << "Error: Too many airports in the file." << endl;
                break;
            }
            // Parse the CSV line and set attributes of the Airport object at 'size'
            istringstream is(line);
            // Assuming data is comma-separated, modify this part based on your file format
            is.getline(airport[size].a_code, sizeof(airport[size].a_code), ',');
            is.getline(airport[size].a_name, sizeof(airport[size].a_name), ',');
            is.getline(airport[size].a_city, sizeof(airport[size].a_city), ',');
            is.getline(airport[size].a_state, sizeof(airport[size].a_state), ',');
            is.getline(airport[size].a_country, sizeof(airport[size].a_country), ',');
            is >> airport[size].a_latitude;
            is >> airport[size].a_longitude;
            size++;  
        }

        // Close the file
        f.close();

    }
    AirportLog::~AirportLog()
    {
        delete[] airport;
    }
        
    void AirportLog::addAirport(const Airport& that)
    {
        if (size >= capacity)
        {
            capacity *= 2;
            Airport* newAirport = new Airport[capacity];

            for (auto i = 0u; i < size; ++i)
            {
                newAirport[i] = airport[i];
            }

            delete[] airport;

            airport = newAirport;
        }
        airport[size] = that;
        size++;
    } 
    
    AirportLog AirportLog::findAirport(const char* state, const char* country)
    {
        AirportLog result;
   
        for (auto i = 0u; i < size; i++) 
        {
            if (strcmp(airport[i].a_state, state) == 0 && strcmp(airport[i].a_country, country) == 0) 
            {
                result.addAirport(airport[i]);
            }
        }
        return result;
    }
    
    Airport AirportLog::operator[](size_t index) const
    {
        if (index < size) 
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
        return this->size;
    }


}