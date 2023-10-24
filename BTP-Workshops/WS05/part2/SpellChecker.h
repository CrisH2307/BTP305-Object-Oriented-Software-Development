/*
*****************************************************************************
								SpellChecker.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

namespace sdds
{
	class SpellChecker
	{
	private:
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_replacements[6]{}; // Keep the track

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif
