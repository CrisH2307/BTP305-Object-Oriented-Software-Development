/*****************************************************************************
                              Timer.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <chrono>
#include "Timer.h"

using namespace std;
namespace sdds
{
    //*------------------------------- TIMER MODULE ----------------------------------------//

    void Timer::start()
    {
        m_start = std::chrono::steady_clock::now();
    }

    long long Timer::stop()
    {
        m_finish = std::chrono::steady_clock::now();
        auto end = (m_finish - m_start);
        return std::chrono::duration_cast<chrono::nanoseconds>(end).count();
    }

}