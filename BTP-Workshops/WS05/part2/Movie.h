/*
*****************************************************************************
							Movie.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds
{
	class Movie
	{
	private:
		std::string m_title{};
		int m_yearRelease{};
		std::string m_movieDes{};

	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			/*
			void fixSpelling(T& spellChecker): a templated function. This function calls the overloaded 
			operator() on instance spellChecker, passing to it the movie title and description.

			ASSUMPTION: In this design, type T must have an overload of the operator() that accepts a string as a parameter.
			*/

			spellChecker(m_title);
			spellChecker(m_movieDes);
		}

		friend std::ostream& operator<<(std::ostream& o, const Movie& that);

	};

}

#endif

