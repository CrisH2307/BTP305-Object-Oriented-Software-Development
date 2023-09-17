/*
*****************************************************************************
                              AirportModels.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
using namespace std;

namespace sdds
{
    struct Airport
    {
        char* a_code;
        char* a_name;
        char* a_city;
        char* a_state;
        char* a_country;
        double a_latitude;
        double a_longitude;

    public:
        Airport();
        Airport(const Airport& that);
        Airport& operator=(const Airport& that);
        ~Airport();
        friend std::ostream& operator<<(std::ostream& os, const Airport& that);
        operator bool()const;
    };


    class AirportLog
    {
        Airport* airport;
        size_t size;        // Number of airports currently in the log
        size_t capacity;    // Capacity of the dynamic array

    public:
        AirportLog();
        AirportLog(const char* filename);
        ~AirportLog();
        void addAirport(const Airport& that);
        AirportLog findAirport(const char* state, const char* country);
        Airport operator[](size_t index) const;
        operator size_t() const;
    };

}
#endif