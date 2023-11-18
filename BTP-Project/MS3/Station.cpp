//                  Station.cpp
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
namespace sdds
{
	//todo: The maximum number of characters required to print to the screen the item name for any object of type Station. Initial value is 0.
	size_t Station::m_widthField = 0;

	//todo:
	/*
	A variable used to generate IDs for new instances of type Station. Every time a new instance is created,
	the current value of the id_generator is stored in that instance, and id_generator is incremented.
	Initial value is 0.
	*/
	size_t Station::id_generator = 0;

	Station::Station(const std::string& thatStation)
	{
		//todo: custom 1-argument constructor
		/*
		+ upon instantiation, a Station object receives a reference to an unmodifiable std::string.
		This string contains a single record (one line) that has been retrieved from the input file specified by the user.
		+ this constructor uses a Utilities object (defined locally) to extract each token from
		the record and populates the Station object accordingly.
		+ this constructor assumes that the string contains 4 fields separated by the delimiter, in the following order:
			* name of the item
			* starting serial number
			* quantity in stock
			* description
		+ the token delimiter is a single character, specified by the client and previously
		stored into the Utilities class of objects.
		+ this constructor extracts name, starting serial number, and quantity from the string first
		+ before extracting description, it updates Station::m_widthField to the maximum value of
		Station::m_widthField and Utilities::m_widthField.

		Note: the display(...) member function uses this field width to align the output across all the records retrieved from the file.
		*/

		Utilities U;
		size_t posn = 0;
		bool ok = true;


		this->m_stationID = ++id_generator;
		this->m_stationName = U.extractToken(thatStation, posn, ok);
		this->m_stationSeri = stoi(U.extractToken(thatStation, posn, ok));
		this->m_stationItem = stoi(U.extractToken(thatStation, posn, ok));
		this->m_widthField = max(U.getFieldWidth(), m_widthField);
		this->m_stationDes = U.extractToken(thatStation, posn, ok);
	}

	//todo: returns the name of the current Station object
	const std::string& Station::getItemName() const { return this->m_stationName; }

	//todo: returns the next serial number to be used on the assembly line and increments m_serialNumber
	size_t Station::getNextSerialNumber() { return this->m_stationSeri++; }

	//todo: returns the remaining quantity of items in the Station object
	size_t Station::getQuantity() const { return m_stationItem; }

	//todo: subtracts 1 from the available quantity; should not drop below 0.
	void Station::updateQuantity()
	{
		if (this->m_stationItem > 0)
		{
			m_stationItem--;
		}

	}


	void Station::display(std::ostream& os, bool full) const
	{
		//todo: inserts information about the current object into stream os.
		/*
		if the second parameter is false, this function inserts only the ID, name, and serial number in the format:
				ID | NAME | SERIAL |
		if the second parameter if true, this function inserts the information in the following format:
				ID | NAME | SERIAL | QUANTITY | DESCRIPTION

		the ID field uses 3 characters, the NAME field uses m_widthField characters,
		the QUANTITY field uses 4 characters,
		the SERIAL field uses 6 characters;
		the DESCRIPTION has no formatting options (see the sample output for other formatting options)

		this function terminates the printed message with an endline
		*/

		os << right;
		os.width(3);
		os.fill('0');
		os << this->m_stationID;
		os << " | ";

		os << left;
		os.width(this->m_widthField);
		os.fill(' ');
		os << this->m_stationName;
		os << " | ";

		os.width(6);
		os.fill('0');
		os << right;
		os << this->m_stationSeri;
		os << " | ";

		if (not(!full))
		{
			os.width(4);
			os.fill(' ');
			os << right << this->m_stationItem;
			os << " | ";
			os << this->m_stationDes;
		}
		os << endl;
	}
}