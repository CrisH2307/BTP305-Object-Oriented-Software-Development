//                  Station.h
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include "Utilities.h"
#include <iostream>
#include <string>
namespace sdds
{
	class Station
	{
		int m_stationID{};
		std::string m_stationName{};
		std::string m_stationDes{};
		size_t m_stationSeri{};
		size_t m_stationItem{};
		static size_t m_widthField;
		static size_t id_generator;
		
	public:
		Station(std::string& thatStation);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif