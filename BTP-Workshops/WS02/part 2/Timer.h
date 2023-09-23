/*
*****************************************************************************
                             Timer.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
#include <chrono>

namespace sdds
{
    class Timer
    {
        std::chrono::time_point<std::chrono::steady_clock> m_start{};
        std::chrono::time_point<std::chrono::steady_clock> m_finish{};
    public:
        void start();
        long long stop();
    };
}

#endif