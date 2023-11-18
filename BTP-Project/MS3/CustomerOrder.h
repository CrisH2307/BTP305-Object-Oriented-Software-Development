//                 CustomerOrder.h
//
// Name: Cris Huynh
// Seneca Student ID: 105444228
// Seneca email: xhuynh@myseneca.ca
// Date of completion: 10/23/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"
#include "Utilities.h"
#include "CustomerOrder.h"
#include <iostream>
#include<vector>
#include <string>
namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};
        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
    private:
        //! Instance Variable
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{};

        //! Class Variable
        static size_t m_widthField;

    public:
        CustomerOrder() = default;
        CustomerOrder(const std::string& thatOne);

        //! Rules of 5
        CustomerOrder(const CustomerOrder& that);
        CustomerOrder& operator=(const CustomerOrder& that) = delete;
        CustomerOrder(CustomerOrder&& that) noexcept;
        CustomerOrder& operator=(CustomerOrder&& that) noexcept;
        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };

}
#endif