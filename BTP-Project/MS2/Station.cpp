//                  Station.cpp
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
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
namespace sdds
{
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(std::string& thatStation)
	{
		Utilities U;
		size_t posn = 0;
		bool ok = true;

		this->m_stationID = ++id_generator;
		this->m_stationName = U.extractToken(thatStation, posn, ok);
		this->m_stationSeri = stoi(U.extractToken(thatStation, posn, ok));
		this->m_stationItem = stoi(U.extractToken(thatStation, posn, ok));
		this->m_widthField = max(U.getFieldWidth(), m_widthField);
		this->m_stationDes = U.extractToken(thatStation, posn, ok);

	}
	
	const std::string& Station::getItemName() const
	{
		return this->m_stationName;
	}
	size_t Station::getNextSerialNumber()
	{
		return this->m_stationSeri++;
	}
	size_t Station::getQuantity() const
	{
		return m_stationItem;
	}
	void Station::updateQuantity()
	{
		if (this->m_stationItem > 0)
		{
			m_stationItem--;
		}

	}
	void Station::display(std::ostream& os, bool full) const
	{
		//if (not(this->getItemName.empty()))
			os << right;
			os.width(3);
			os.fill('0');
			os << this->m_stationID;
			os << " | ";

			os << left;
			os.width(this->m_widthField);
			os.fill(' ');
			os << this->m_stationName;
			os << " | ";

			os.width(6);
			os.fill('0');
			os << this->m_stationSeri;
			os << " | ";
			os << left;

		if (not(!full))
		{
			os.width(4);
			os.fill(' ');
			os << right << this->m_stationItem;
			os << " | ";
			os << this->m_stationDes;
		}
		os << endl;
	}
}