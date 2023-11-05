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

	void CovidCollection::display(std::ostream& out, const std::string& country) const
	{
		//todo: This function represents Task #1 -- 
		//? DO NOT USE MANUAL LOOPS!
		/*
		+ Update this function's prototype to receive a second parameter country. This parameter 
		should have the default value ALL if the client doesn't provide it (don't overload the function).
		+ Implement the function to print only the information about the country specified in the 
		second parameter. If the parameter has the value ALL, then print information for all countries.
		+ This function should also calculate the percentage of cases/deaths in the specified country 
		from the world total. If the second parameter is ALL, then this function should print the number 
		of cases/deaths in the world. See the sample output for the format.
		*/

		// To define if the param calls the world or country
		auto isCountry = [country](const Covid& covid) 
		{
			return country == "ALL" || covid.m_country == country;
		};

		auto totalCases = std::accumulate(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), 0u,
			[isCountry](unsigned int sum, const Covid& covid) 
			{
				return sum + (isCountry(covid) ? covid.m_numofCases : 0u);
			});

		auto totalDeaths = std::accumulate(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), 0u,
			[isCountry](unsigned int sum, const Covid& covid) 
			{
				return sum + (isCountry(covid) ? covid.m_numofDeaths : 0u);
			});


		auto worldTotalCases = std::accumulate(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), 0u,
												[](unsigned int sum, const Covid& theCovid)
												{
													return sum += theCovid.m_numofCases;	
												});

		auto worldTotalDeaths = std::accumulate(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), 0u,
												[](unsigned int sum, const Covid& theCovid)
												{
													return sum += theCovid.m_numofDeaths;
												});

		double PerCases = (totalCases / static_cast<double>(worldTotalCases)) * 100;
		double PerDeaths = (totalDeaths / static_cast<double>(worldTotalDeaths)) * 100;


		if (country != "ALL")
			out << "Displaying information of country = " << country << endl;
		std::for_each(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(),
			[&out, isCountry, country](const Covid& theCovid)
			{
				if ((isCountry(theCovid) || country == "ALL"))
				{
					out << theCovid;
					out << endl;
				}
			});

		// CASES
		string TotalCasesFormat{};
		TotalCasesFormat += "Total cases ";
		if (country == "ALL")
		{
			TotalCasesFormat += "around the world: ";
			TotalCasesFormat += std::to_string(worldTotalCases);
		}
		else
		{
			TotalCasesFormat += "in ";
			TotalCasesFormat += country;
			TotalCasesFormat += ": ";
			TotalCasesFormat += std::to_string(totalCases);
		}

		out.setf(ios::right);
		out << "| ";
		out.width(84);
		out << TotalCasesFormat;
		out << " |" << endl;

		//DEATH
		string TotalDeathsFormat{};
		TotalDeathsFormat += "Total cases ";
		if (country == "ALL")
		{
			TotalDeathsFormat += "around the world: ";
			TotalDeathsFormat += std::to_string(worldTotalDeaths);
		}
		else
		{
			TotalDeathsFormat += "in ";
			TotalDeathsFormat += country;
			TotalDeathsFormat += ": ";
			TotalDeathsFormat += std::to_string(totalDeaths);
		}


		out << "| ";
		out.width(84);
		out << TotalDeathsFormat;
		out << " |" << endl;

		// Percentage summary
		if (!country.empty() and country != "ALL")
		{
			string percentageFormat{};
			percentageFormat += country;
			percentageFormat += " has ";
			percentageFormat += std::to_string(PerCases);
			percentageFormat += "% of global cases and ";
			percentageFormat += std::to_string(PerDeaths);
			percentageFormat += "% ";
			percentageFormat += "of global deaths";


			out << "| ";
			out.width(84);
			out << percentageFormat;
			out << " |" << endl;
			out.unsetf(ios::right);
		}

	}

	void CovidCollection::sort(const std::string& field)
	{
		//todo: This function represents Task #2 -- 
		//? DO NOT USE MANUAL LOOPS!
		/*
		+ Sort the collection of Covid objects in ascending order based on the field received as parameter.
		+ The parameter should have a default value of country (do not overload this function).
		+ If two Covid objects have the same value for the specified field, then the object
		with lower deaths is considered smaller.
		*/

		if (field == "country")
		{
			std::sort(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), 
				[](const Covid& thisCovid, const Covid& thatCovid)
				{
					//If two Covid objects have the same value for the specified field, then the object with lower deaths is considered smaller.
					if (thisCovid.m_variant != thatCovid.m_variant)
					{
						return thisCovid.m_variant < thatCovid.m_variant;
					}
					else
					{
						return thisCovid.m_numofDeaths < thatCovid.m_numofDeaths;
					}
				});
		}


	}

	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const
	{
		//todo: This function represents Task #3 -- 
		//? DO NOT USE MANUAL LOOPS!
		/*
		Search in the collection for a city in the specified country where the variant from the first parameter has caused more 
		deaths than the last parameter. Return true if such an object exists, false otherwise.
		*/


		return std::any_of(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(),
			[variant, country, deaths](const Covid& that)
			{
				if (that.m_variant == variant and that.m_country == country and that.m_numofDeaths > deaths)
				{
					return true;
				}
			});
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const
	{
		//todo: This function represents Task #4 -- 
		//? DO NOT USE MANUAL LOOPS!
		/*
		Create and return a collection of Covid objects from the current instance where the number of deaths 
		is at least as the value specified as parameter.
		*/

		std::list<Covid>res;

		std::copy_if(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), std::back_inserter(res),
			[deaths](const Covid& that)
			{
				return that.m_numofDeaths >= deaths;
			});

		return res;
	}

	void CovidCollection::updateStatus()
	{
		//todo: This function represents Task #5 -- 
		//? DO NOT USE MANUAL LOOPS!
		/*
		Updates the status of each city. If the number of deaths is greater than 300, the status should be EPIDEMIC, 
		if it is less than 50, it should be EARLY; for anything else, the status should be MILD.
		*/
		auto updateStatus = [](Covid& that) -> Covid& 
		{
			if (that.m_numofDeaths > 300) 
			{
				that.UPDATE = "EPIDEMIC";
			}
			else if (that.m_numofDeaths < 50) 
			{
				that.UPDATE = "EARLY";
			}
			else 
			{
				that.UPDATE = "MILD";
			}
			return that;
		};

		// Use std::transform to update status for each city
		std::transform(this->m_pCovidisHere.begin(), this->m_pCovidisHere.end(), this->m_pCovidisHere.begin(), updateStatus);
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
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
			out << " | ";
			out << "| ";
			out.width(8);
			if (theCovid.UPDATE.empty())
			{
				out << "General";
			}
			else
			{
				out << theCovid.UPDATE;
			}
			out << " |";
		}
		return out;
	}

}
