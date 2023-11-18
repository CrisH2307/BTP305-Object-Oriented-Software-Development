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
	//todo: separates the tokens in any given std::string object. All Utilities objects in the system share the same delimiter.
	char Utilities::m_delimiter = '\0';

	//todo: sets the field width of the current object to the value of parameter newWidth
	void Utilities::setFieldWidth(size_t newWidth) { this->m_widthField = newWidth; }

	//todo: returns the field width of the current object
	size_t Utilities::getFieldWidth() const { return this->m_widthField; }

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		//todo: extracts a token from string str referred to by the first parameter.
		/*
		This function:
		+ Uses the delimiter to extract the next token from str starting at position next_pos.
			* If successful, return a copy of the extracted token found (without spaces at the beginning/end),
			update next_pos with the position of the next token, and set more to true (false otherwise).
		+ Reports an exception if a delimiter is found at next_pos.
		+ Updates the current object's m_widthField data member if its current value is less than the size of the token extracted.

		Note: in this application, str represents a single line that has been read from an input file.
		*/

		
        auto trim = [](const std::string& str) {
            const std::string whitespace = " \t\n\r\f\v";
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return std::string{}; // no content
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        };

        std::string buf{};
        size_t first_pos = next_pos;

        if (first_pos == std::string::npos)
        {
            more = false;
            return buf;
        }

        char ch = str[first_pos];  // Initialize ch with the first character

        while (ch != m_delimiter && ch != '\0') {
            buf += ch;
            ch = str[++next_pos];
        }

        size_t delimiter_pos = str.find(m_delimiter, first_pos);

        if (delimiter_pos == std::string::npos)
        {
            buf = trim(str.substr(first_pos));
            m_widthField = std::max(buf.length(), m_widthField);
            more = false;
        }
        else if (delimiter_pos == first_pos)
        {
            more = false;
            throw std::runtime_error("Token not found between delimiters");
        }
        else
        {
            buf = trim(str.substr(first_pos, delimiter_pos - first_pos));
            m_widthField = std::max(buf.length(), m_widthField);
            more = true;
        }

        next_pos = (delimiter_pos != std::string::npos) ? delimiter_pos + 1 : std::string::npos;
        return buf;

		/*
		
		auto trim = [](const std::string& str) -> std::string {
            const std::string whitespace = " \t\n\r\f\v";
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; // no content
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        };

        std::string ret{};
        char ch = str[next_pos];

        // check if delimiter is at 'next_pos'
		if (ch == ',' /) {
			more = false;
		}

		// build 'ret' until a delimiter or the end of 'str' is found
		while (ch != ',' && ch != '\0') {
			ret += ch;
			ch = str[++next_pos];
		}

		// update width for output
		if (m_widthField < ret.length())
			m_widthField = ret.length();

		// if we reached the end of the 'str', change 'more' so
		// the client won't try to extract again
		if (ch == '\0')
			more = false;
		else
			++next_pos; // skip delimiter

		return trim(ret);
		
		*/
	}

	//todo: sets the delimiter for this class to the character received
	void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

	//todo: returns the delimiter for this class.
	char Utilities::getDelimiter() { return m_delimiter; }
}