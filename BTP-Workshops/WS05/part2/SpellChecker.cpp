/*
*****************************************************************************
								SpellChecker.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Book.h"
#include "SpellChecker.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;
namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		/*
		SpellChecker(const char* filename): receives the address of a C-style null-terminated string
		that holds the name of the file that contains the misspelled words. If the file exists, this
		constructor loads its contents. If the file is missing, this constructor throws an exception 
		of type const char*, with the message Bad file name!. Each line in the file has the format 
		BAD_WORD  GOOD_WORD; the two fields can be separated by any number of spaces.
		*/

		// If its filename, load it
		ifstream f(filename);
		if (not(f.is_open()))
		{
			throw "Bad file name!";
		}

		// Sorting into array
		string bad;
		string good;
		int cnt = 0;

		while (f >> bad >> good)
		/*
		Explaination:
		_ while (file >> bad >> good): reads the data from the file in pair using >>.
		_ because each line has the format bad good --> so we read bad first and good after
		*/
		{
			m_badWords[cnt] = bad;
			m_goodWords[cnt] = good;
			//--> When the instruction said that loads each line, using the array to load it
			cnt++;
		}

		//Close
		f.close();

	}

	void SpellChecker::operator()(std::string& text)
	{
		/*
		void operator()(std::string& text): this operator searches text and replaces any misspelled 
		word with the correct version. It should also count how many times each misspelled word has been replaced.

		When implementing this operator, consider the following functions:

		std::string::find()
		std::string::replace()
		*/

		// Find all instances of the bad word in the text received and replace all of them. Loop within the line.
		size_t start;

		for (size_t i = 0; i < 6; ++i)
		{
			start = 0;
			while ((start = text.find(m_badWords[i], start)) != string::npos)
				// Search from the position start (start is 0 and then increase it
				// Find function is used to search for a substring within another string
				// formula n = s.find("is", n);
				// npos represents the largest possible for the string size type
				// if the result is = to npos, it means the search string was not found in the given text
			{
				text.replace(start, m_badWords[i].length(), m_goodWords[i]);
				start += m_goodWords[i].length();
				m_replacements[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		/*
		void showStatistics(std::ostream& out) const: inserts into the parameter how many times each misspelled word 
		has been replaced by the correct word using the current instance. The format of the output is:

		BAD_WORD: CNT replacements<endl>
		where BAD_WORD is to be printed on a field of size 15, aligned to the right.
		*/

		out << "Spellchecker Statistics" << endl;
		size_t i = 0;
		for (auto& badW : this->m_badWords)
		{
			out.width(15);
			out << right << badW;
			out << ": ";
			out << this->m_replacements[i] << " replacements";
			out << endl;
			i++;
		}
	}

}