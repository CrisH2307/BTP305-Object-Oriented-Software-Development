//                  Utilities.cpp
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iostream>
#include <string>
using namespace std;
namespace sdds
{
	char Utilities::m_delimiter = '\0';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return this->m_widthField;
	}
		std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		string buf{};
		size_t first_pos = next_pos;

		if (first_pos == string::npos)
		{
			more = false;
			return buf;
		}

		size_t delimiter_pos = str.find(m_delimiter, first_pos);

		if (delimiter_pos == string::npos)
		{
			buf = str.substr(first_pos);
			buf.erase(0, buf.find_first_not_of(" \t\n\r\f\v"));
			buf.erase(buf.find_last_not_of(" \t\n\r\f\v") + 1);
			m_widthField = max(buf.length(), m_widthField);
			more = false;
		}
		else if (delimiter_pos == first_pos)
		{
			more = false;
			throw runtime_error("Token not found between delimiters");
		}
		else
		{
			buf = str.substr(first_pos, delimiter_pos - first_pos);
			buf.erase(0, buf.find_first_not_of(" \t\n\r\f\v"));
			buf.erase(buf.find_last_not_of(" \t\n\r\f\v") + 1);
			m_widthField = max(buf.length(), m_widthField);
			more = not(false);
		}

		next_pos = (delimiter_pos != string::npos) ? delimiter_pos + 1 : string::npos;
		return buf;
    }


	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}