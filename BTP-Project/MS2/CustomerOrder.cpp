//                  CustomerOrder.cpp
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
#include "CustomerOrder.h"
#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
using namespace std;
namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {} //! Has already put into Default

	CustomerOrder::CustomerOrder(const std::string& thatOne)
	{
        Utilities U;
        size_t pos = 0;
        bool more = false;
        std::vector<Item*> vecItem;

        m_name = U.extractToken(thatOne, pos, more);
        m_product = U.extractToken(thatOne, pos, more);
        this->m_widthField = max(U.getFieldWidth(), m_widthField);

        while (more) 
        {
            vecItem.push_back(new Item(U.extractToken(thatOne, pos, more)));
        }

        m_cntItem = vecItem.size();
        m_lstItem = new Item*[m_cntItem];

        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = std::move(vecItem[i]);
        }

	}

	CustomerOrder::CustomerOrder(const CustomerOrder& that) { throw "Error";}

	CustomerOrder::CustomerOrder(CustomerOrder&& that) noexcept
	{
        *this = move(that);
	}
    
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& that) noexcept
	{
		if(this != &that)
        {
            for (size_t i = 0; i < m_cntItem; ++i)
            {
                delete m_lstItem[i];
            }
            delete[]m_lstItem;

            if(!that.m_name.empty())
            {
                this->m_name = that.m_name;
                this->m_product = that.m_product;
                this->m_cntItem = that.m_cntItem;
                this->m_lstItem = that.m_lstItem;
                
                that.m_name = "";
                that.m_product = "";
                that.m_cntItem = 0;
                that.m_lstItem = nullptr;
            }
        }
        return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            delete m_lstItem[i];
        }
        delete[]m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
        bool ok = false;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (m_lstItem[i]->m_isFilled)
            {
                ok = true;
            }
        }
		return ok;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (this->m_lstItem[i]->m_itemName == itemName)
            {
                return this->m_lstItem[i]->m_isFilled;
            }
        }
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if(station.getItemName() == m_lstItem[i]->m_itemName)
            {
                if (station.getQuantity() > 0 and not(m_lstItem[i]->m_isFilled))
                {
                    station.updateQuantity();
                    this->m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    this->m_lstItem[i]->m_isFilled = (!false);
                    os << "    Filled " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName <<  "]";
                    os << endl;
                }
                else if (station.getQuantity() == 0)
                {
                    os << "    Unable to fill " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName <<  "]";
                    os << endl;
                }
            }
        }
	}

	void CustomerOrder::display(std::ostream& os) const
	{
        os << this->m_name << " - " << this->m_product << endl;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            os << "[";
            os.width(6);
            os.fill('0');
            os << this->m_lstItem[i]->m_serialNumber;
            os << "] ";

            os.width(this->m_widthField);
            os.fill(' ');
            os << left << this->m_lstItem[i]->m_itemName;
            os << " - ";

            os << (this->m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
            os << endl;
        }
	}

}