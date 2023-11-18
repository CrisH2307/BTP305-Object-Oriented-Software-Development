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
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
using namespace std;
namespace sdds
{
    //todo: static size_t m_widthField – the maximum width of a field, used for display purposes
    size_t CustomerOrder::m_widthField = 0;

    //CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}

    CustomerOrder::CustomerOrder(const std::string& thatOne)
    {
        //todo: A custom 1-argument constructor that takes a reference to an unmodifiable string. 
        /*
        This constructor uses a local Utilities object to extract the tokens from the string and
        populate the current instance. The fields in the string are (separated by a delimiter):
            + Customer Name
            + Order Name
            + the list of items making up the order (at least one item)
        After finishing extraction, this constructor updates CustomerOrder::m_widthField if the current value is
        smaller than the value stored in Utilities::m_widthField.
        */

        Utilities U;
        size_t pos = 0;
        bool more = false;
        std::vector<Item*> theItem;

        this->m_name = U.extractToken(thatOne, pos, more);
        this->m_product = U.extractToken(thatOne, pos, more);
        this->m_widthField = max(U.getFieldWidth(), m_widthField);

        while (more)
        {
            theItem.push_back(new Item(U.extractToken(thatOne, pos, more)));
        }

        m_cntItem = theItem.size();
        m_lstItem = new Item *[m_cntItem];

        for (size_t i = 0; i < m_cntItem; i++) 
        {
            m_lstItem[i] = std::move(theItem[i]);
        }

    }

    //! ---------------------------------- RULES OF FIVE ---------------------------------------------//

    CustomerOrder::CustomerOrder(const CustomerOrder& that) { throw "Error"; }

    CustomerOrder::CustomerOrder(CustomerOrder&& that) noexcept { *this = move(that); }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& that) noexcept
    {
        if (this != &that)
        {
            for (size_t i = 0; i < m_cntItem; ++i)
            {
                delete m_lstItem[i];
            }
            delete[]m_lstItem;

            if (!that.m_name.empty())
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
    //! ---------------------------------- END OF RULES OF FIVE ---------------------------------------------//

    bool CustomerOrder::isOrderFilled() const
    {
        //todo: returns true if all the items in the order have been filled; false otherwise
        bool ok = false;
        size_t SIZE = 0;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (this->m_lstItem[i]->m_isFilled)
            {
                ++SIZE;
            }
        }

        if (SIZE == m_cntItem)
        {
            ok = true;
        }

        return ok;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const
    {
        //todo: returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.

        bool ok = false;
        int cntItems = 0;
        int cntFilled = 0;

        // loop through item list 
        for (size_t i = 0; i < this->m_cntItem; ++i)
        {
            if (m_lstItem[i]->m_itemName == itemName)
            {
                ++cntItems;
                if (m_lstItem[i]->m_isFilled)
                {
                    ++cntFilled;
                }
            }
        }

        // if nothing was found
        if (cntItems == 0 or cntFilled == cntItems)
        {
            ok = true;
        }

        return ok;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        //todo: this modifier fills one item in the current order that the Station specified in the first parameter handles.
        /*
        if the order doesn't contain the item handled, this function does nothing
        if the order contains items handled, and the Station's inventory contains at least one item,
        this function fills the order with one single item. It subtracts 1 from the inventory and updates
        Item::m_serialNumber and Item::m_isFilled. It also prints the message
                    Filled NAME, PRODUCT [ITEM_NAME].
        if the order contains items handled but unfilled, and the inventory is empty, this function prints the message
                    Unable to fill NAME, PRODUCT [ITEM_NAME].
        all messages printed are terminated by an endline
        */


        // This is gonna prevent the duplicate readfile
        bool avoidDuplicate = false;

        for (size_t i = 0; i < m_cntItem and !avoidDuplicate; ++i)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName() and not(m_lstItem[i]->m_isFilled))
            {
                if (station.getQuantity() > 0)
                {
                    station.updateQuantity();
                    this->m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    this->m_lstItem[i]->m_isFilled = true;

                    os << "    Filled " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << "]";
                    os << endl;

                    avoidDuplicate = true;
                }
                else
                {
                    os << "    Unable to fill " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << "]";
                    os << endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const
    {
        //todo: this query displays the state of the current object in the format (see the sample output for details)
        /*
        CUSTOMER_NAME - PRODUCT
        [SERIAL] ITEM_NAME - STATUS
        [SERIAL] ITEM_NAME - STATUS
        ...
        SERIAL - a field of width 6
        ITEM_NAME - a field of size m_widthField
        STATUS is either FILLED or TO BE FILLED
        you must use IO manipulators to format this output.
        */

        os << this->m_name << " - " << this->m_product << endl;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            os << "[";
            os << setfill('0');
            os.width(6);
            os << this->m_lstItem[i]->m_serialNumber;
            os << "] ";

            os << setfill(' ');
            os << left;
            os.width(m_widthField);
            os << this->m_lstItem[i]->m_itemName;
            os << " - ";

            if (this->m_lstItem[i]->m_isFilled) 
                os << "FILLED";
            else
                os << "TO BE FILLED";
            os << endl;
            os << right;
        }
    }

}