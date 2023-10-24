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
		// const std::string& title() const: a query that returns the title of the book
		return this->m_title;
	}

	const std::string& Book::country() const
	{
		//const std::string& country() const: a query that returns the publication country
		return this->m_country;
	}

	const size_t& Book::year() const
	{
		// const size_t& year() const: a query that returns the publication year
		return m_year;
	}

	double& Book::price()
	{
		// double& price(): a function that returns the price by reference, allowing the client code to update the price
		return this->m_price;
	}

	Book::Book(const std::string& strBook)
	{
		/*
		Book(const std::string& strBook): a constructor that receives a reference to an unmodifiable string that contains 
		information about the book; this constructor extracts the information about the book from the string by parsing it 
		and stores the tokens in the object's attributes. The string always has the following format:
		
		AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		*/

		// Initializing the start and the end index
		size_t start{ 0 };
		size_t end = strBook.find(',');

		// Storing the author
		m_author = strBook.substr(start, (end - start));
		start = end + 1;
		end = strBook.find(',', start);
		// Erasing trailing and leading white spaces
		m_author.erase(0, m_author.find_first_not_of(" \t\r\n"));
		m_author.erase(m_author.find_last_not_of(" \t\r\n") + 1);

		// Storing the title
		m_title = strBook.substr(start, (end - start));
		start = end + 1;
		end = strBook.find(',', start);
		// Erasing trailing and leading white spaces
		m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
		m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

		// Storing the country of publication
		m_country = strBook.substr(start, (end - start));
		start = end + 1;
		end = strBook.find(',', start);
		// Erasing trailing and leading white spaces
		m_country.erase(0, m_country.find_first_not_of(" \t\r\n"));
		m_country.erase(m_country.find_last_not_of(" \t\r\n") + 1);

		// Storing the price of the book
		m_price = std::stod(strBook.substr(start, (end - start)));
		start = end + 1;
		end = strBook.find(',', start);

		// Storing the year of publication
		m_year = std::stoi(strBook.substr(start, (end - start)));
		start = end + 1;
		end = strBook.find('\n', start);

		// Storing the description of the book
		m_des = strBook.substr(start, end);
		// Erasing trailing and leading white spaces
		m_des.erase(0, m_des.find_first_not_of(" \t\r\n"));
		m_des.erase(m_des.find_last_not_of(" \t\r\n") + 1);

	}

	std::ostream& operator<<(std::ostream& o, const Book& that)
	{
		/*
		overload the insertion operator to insert the content of a book object 
		into an ostream object, in the following format:
		AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
		the author printed on a field of size 20;
		the title printed on a field of size 22;
		the country printed on a field of size 5;
		the year printed on a field of size 4;
		the price printed on a field of size 6, with 2 decimal digits;
		see alignment in the sample output.
		*/

		if (not(that.m_author.empty()))
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
