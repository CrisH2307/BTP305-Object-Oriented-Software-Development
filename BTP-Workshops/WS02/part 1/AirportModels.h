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
#include <fstream>
#include <string>

namespace sdds
{
    class Airport
    {
    public:
        std::string m_code{};
        std::string m_name{};
        std::string m_city{};
        std::string m_state{};
        std::string m_country{};
        double m_latitude{};
        double m_longitude{};
    };
         std::ostream& operator<<(std::ostream& oo, const Airport& that);


    class AirportLog
    {
        Airport* airport;
        size_t capacity;    // Capacity of the dynamic array

    public:
        AirportLog();
        AirportLog(std::string filename);
        
         //* Rules of 5
        AirportLog(const AirportLog &that);
        AirportLog& operator=(const AirportLog &that);
        ~AirportLog();
        AirportLog(AirportLog&& that);
        AirportLog& operator=(AirportLog&& that);

        void addAirport(const Airport& that);
        AirportLog findAirport(std::string state, std::string country) const;
        Airport operator[](size_t index) const;
        operator size_t() const;
    };
}
#endif