/*
*****************************************************************************
								Book.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Book.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
namespace sdds
{
	//Book::Book(): m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_des(""){}

	const std::string& Book::title() const
	{
		return this->m_title;
	}

	const std::string& Book::country() const
	{
		return this->m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return this->m_price;
	}

	Book::Book(const std::string& strBook)
	{
		// Initializing the start and the end index
		size_t startIndex{ 0 };
		size_t endIndex = strBook.find(',');

		// Storing the author
		m_author = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		// Erasing trailing and leading white spaces
		m_author.erase(0, m_author.find_first_not_of(" \t\r\n"));
		m_author.erase(m_author.find_last_not_of(" \t\r\n") + 1);

		// Storing the title
		m_title = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		// Erasing trailing and leading white spaces
		m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
		m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

		// Storing the country of publication
		m_country = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		// Erasing trailing and leading white spaces
		m_country.erase(0, m_country.find_first_not_of(" \t\r\n"));
		m_country.erase(m_country.find_last_not_of(" \t\r\n") + 1);

		// Storing the price of the book
		m_price = std::stod(strBook.substr(startIndex, (endIndex - startIndex)));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);

		// Storing the year of publication
		m_year = std::stoi(strBook.substr(startIndex, (endIndex - startIndex)));
		startIndex = endIndex + 1;
		endIndex = strBook.find('\n', startIndex);

		// Storing the description of the book
		m_des = strBook.substr(startIndex, endIndex);
		// Erasing trailing and leading white spaces
		m_des.erase(0, m_des.find_first_not_of(" \t\r\n"));
		m_des.erase(m_des.find_last_not_of(" \t\r\n") + 1);

	}

	std::ostream& operator<<(std::ostream& o, const Book& that)
	{
		if (!that.m_author.empty())
		{
			o.width(20);
			o << right <<that.m_author;
			o << " | ";
			
			o.width(22);
			o << right<<that.m_title;
			o << " | ";

			o.width(5);
			o << right << that.m_country;
			o << " | ";

			o.width(4);
			o << right << that.m_year;
			o << " | ";

			o.width(6);
			o << right << fixed << setprecision(2) << that.m_price;
			o << " | ";

			o << left << that.m_des;

			o << endl;
		}

		return o;
	}
}
