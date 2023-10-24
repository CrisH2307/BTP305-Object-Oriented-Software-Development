/*
*****************************************************************************
							Movie.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Movie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
namespace sdds
{
	const std::string& Movie::title() const
	{
		// const std::string& title() const: a query that returns the title of the movie
		return this->m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		/*
		Movie(const std::string& strMovie): receives the movie through a reference to a string. 
		This constructor extracts the information about the movie from the string and stores the 
		tokens in the attributes. The received string always has the following format:

		TITLE,YEAR,DESCRIPTION
		This constructor removes all spaces from the beginning and end of any token in the string.
		*/

		if (not(strMovie.empty()))
		{
			// Initializing the start and the end index
			size_t start = 0;
			size_t end = strMovie.find(','); 

			// Store the title
			this->m_title = strMovie.substr(start, (end - start));
			start = end + 1;
			end = strMovie.find(',', start);

			// Erasing the trailing and leading white spaces
			this->m_title.erase(0, this->m_title.find_first_not_of(" \t\r\n"));
			this->m_title.erase(this->m_title.find_last_not_of(" \t\r\n") + 1);

			// Storing the year of release
			this->m_yearRelease = stoi(strMovie.substr(start, (end - start)));
			start = end + 1;
			end = strMovie.find('\n', start);

			// Storing the description of the movie
			this->m_movieDes = strMovie.substr(start, end);

			// Erasing trailing and leading white spaces
			this->m_movieDes.erase(0, this->m_movieDes.find_first_not_of(" \t\r\n"));
			this->m_movieDes.erase(this->m_movieDes.find_last_not_of(" \t\r\n") + 1);
		}
	}

	std::ostream& operator<<(std::ostream& o, const Movie& that)
	{
		/*
		overload the insertion operator to insert the content of a movie object into an 
		ostream object, in the following format:
		TITLE | YEAR | DESCRIPTION
		the title printed on a field of size 40;
		the year printed on a field of size 4;
		*/

		if (not(that.title().empty()))
		{
			o.width(40);
			o << right<< that.title();
			o << " | ";
			o.width(4);
			o << right << that.m_yearRelease;
			o << " | ";
			o.width(40);
			o << left << that.m_movieDes;
			o << endl;
		}
		return o;
	}
}