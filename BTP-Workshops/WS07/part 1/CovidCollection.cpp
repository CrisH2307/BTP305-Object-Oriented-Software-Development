/*
*****************************************************************************
								FileSystem.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "CovidCollection.h"

using namespace std;

namespace sdds
{
	CovidCollection::CovidCollection(const std::string& filename)
	{
		//todo: A custom constructor
		/*
		That receives as a parameter the name of the file containing the information about the covid details 
		of various cities to be added to the collection. This function should load into the attributes all 
		the covid details in the file.
		If the filename is incorrect, this constructor should raise an exception.
		Each line from the file contains covid information about a single city in the following format:
				COUNTRY CITY VARIANT YEAR CASES DEATHS

		The fields are not separated by delimiters; each field has a fixed size: COUNTRY, CITY and VARIANT have 
		exactly 25 characters; while YEAR, CASES and DEATHS have exactly 5 characters.
		Any blank space at the beginning/end of a token is not part of the token and should be removed.	
		*/
		ifstream fe(filename);

		if (not(fe.is_open()))
		{
			throw invalid_argument("Error: Unable to open file.");
		}

		string thisLine{};
		
		while (getline(fe, thisLine))
		{
			if (thisLine.size() >= 65) {
				Covid thisCovidRecord{};
				thisCovidRecord.m_country = thisLine.substr(0, 25);
				thisCovidRecord.m_city = thisLine.substr(25, 25);
				thisCovidRecord.m_variant = thisLine.substr(50, 25);
				thisCovidRecord.m_year = stoi(thisLine.substr(75, 5));
				thisCovidRecord.m_numofCases = stoi(thisLine.substr(80, 5));
				thisCovidRecord.m_numofDeaths = stoi(thisLine.substr(85, 5));

				// Remove leading and trailing spaces from the tokens
				thisCovidRecord.m_country = thisCovidRecord.m_country.substr(thisCovidRecord.m_country.find_first_not_of(' '));
				thisCovidRecord.m_country = thisCovidRecord.m_country.substr(0, thisCovidRecord.m_country.find_last_not_of(' ') + 1);
				thisCovidRecord.m_city = thisCovidRecord.m_city.substr(thisCovidRecord.m_city.find_first_not_of(' '));
				thisCovidRecord.m_city = thisCovidRecord.m_city.substr(0, thisCovidRecord.m_city.find_last_not_of(' ') + 1);
				thisCovidRecord.m_variant = thisCovidRecord.m_variant.substr(thisCovidRecord.m_variant.find_first_not_of(' '));
				thisCovidRecord.m_variant = thisCovidRecord.m_variant.substr(0, thisCovidRecord.m_variant.find_last_not_of(' ') + 1);

				this->m_pCovidisHere.push_back(thisCovidRecord);
			}
			else
			{
				throw "Error: Invalid line format in the file.";
			}
		}
	}

	void CovidCollection::display(std::ostream& out) const
	{
		//todo: Print the content of the collection into the parameter (one city details / line). Use the insertion operator
		//? DO NOT USE MANUAL LOOPS! 

		std::for_each(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(),
			[&out](const Covid& theCovid)
			{
				out << "| ";
				out.width(21);
				out << left << theCovid.m_country;
				out << " | ";

				out.width(15);
				out << left << theCovid.m_city;
				out << " | ";

				out.width(20);
				out << left << theCovid.m_variant;
				out << " | ";

				out.width(6);
				if (theCovid.m_year < 0)
				{
					out << "      ";
				}
				else
				{
					out << right << theCovid.m_year;
				}
				out << " | ";

				out.width(4);
				out << right << theCovid.m_numofCases;
				out << " | ";

				out.width(3);
				out << theCovid.m_numofDeaths;
				out << " |";
				out << endl;
			});
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		{
			//todo: inserts one Covid object into the first parameter, using the following format 
			//			| COUNTRY(21) | CITY(15) | VARIANT(20) | YEAR(6) | CASES(4) | DEATHS(3) |
			if (not(theCovid.m_city.empty()))
			{
				out << "| ";
				out.width(21);
				out << left << theCovid.m_country;
				out << " | ";

				out.width(15);
				out << left << theCovid.m_city;
				out << " | ";

				out.width(20);
				out << left << theCovid.m_variant;
				out << " | ";

				out.width(6);
				out << right << theCovid.m_year;
				out << " | ";

				out.width(4);
				out << right << theCovid.m_numofCases;
				out << " | ";

				out.width(3);
				out << theCovid.m_numofDeaths;
				out << " |";
			}
			out << endl;
			return out;
		}
	}


}