/*
*****************************************************************************
								CovidCollection.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

namespace sdds
{
	struct Covid
	{
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		int m_year{};
		unsigned int m_numofCases{};
		unsigned int m_numofDeaths{};

		//PART 2
		std::string UPDATE;
	};

	class CovidCollection
	{
		std::vector<Covid> m_pCovidisHere{};

	public:
		CovidCollection(const std::string& filename);
		//void display(std::ostream& out) const;   // DO NOT OVERLOAD --> REMOVE

		//! part2
		void display(std::ostream& out, const std::string& country = "ALL") const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
	};

	// Prototype for the overloaded operator<<
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif

