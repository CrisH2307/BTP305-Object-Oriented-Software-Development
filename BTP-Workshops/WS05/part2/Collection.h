/*
*****************************************************************************
						Collection.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP305 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <stdexcept>

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

namespace sdds
{
	template <typename T>
	class Collection
	{
	private:
		std::string m_nameCollection{};
		T* m_item{};
		size_t m_size{};
		void (*m_observer)(const Collection<T>&, const T&);		
	public:
		Collection(const std::string& name) : m_nameCollection(name), m_item(nullptr), m_size(0), m_observer(nullptr) {}

		// ! Rule of 5 (BUT DELETED)
		Collection(const Collection& that) = delete;

		Collection& operator=(const Collection& that) = delete;

		Collection(Collection&& that) = delete;

		Collection& operator=(Collection&& cthat) = delete;

		~Collection()
		{
			delete[]m_item;
		}

		const std::string& name() const
		{
			return m_nameCollection;
		}

		size_t size() const
		{
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			/*
			void setObserver(void (*observer)(const Collection<T>&, const T&)): stores the address 
			of the callback function (observer) into an attribute. This parameter is a pointer to 
			a function that returns void and accepts two parameters: a collection and an item that 
			has just been added to the collection. This function is called when an item is added to the collection.
			*/

			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			/*
			Collection<T>& operator+=(const T& item): adds a copy of item to the collection, only 
			if the collection doesn't contain an item with the same title. If item is already in 
			the collection, this function does nothing. If the item is not yet in the collection, this function:

			resizes the array of items to accommodate the new item
			if an observer has been registered, this operator calls the observer function passing 
			the current object (*this) and the new item as arguments.
			ASSUMPTION: type T has a member function called title() that returns the title of the item (std::string).

			*/

			bool ok = false;
			// Check if the item that we are trying to add is not a duplicate
			// Not using range based loop as DMA is involved

			for (size_t i = 0; i < size(); ++i)
			{
				if (m_item[i].title() == item.title())
				{
					ok = true;
				}

			}
			if (not(ok))
			{
				T* that = new T [m_size + 1];
				for (size_t i = 0; i < size(); ++i)
				{
					that[i] = m_item[i];
				}

				that[m_size] = item;

				// Clean
				delete[] m_item;
				m_item = that;
				m_size++;

				// Calling the observer function if registered
				if (m_observer)
				{
					m_observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const
		{
			/*
			T& operator[](size_t idx) const: returns the item at index idx.

			if the index is out of range, this operator throws an exception of type std::out_of_range with the message 
			Bad index [IDX]. Collection has [SIZE] items.. Use operator + to concatenate strings.
			*/

			// Throwing an exception if the index is out of range
			if (idx >= m_size) 
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}

			return m_item[idx];
		}

		T* operator[](const std::string& title) const
		{
			/*
			T* operator[](const std::string& title) const: returns the address of the item with the title
			 title (type T has a member function called title() that returns the title of the item). 
			 If no such item exists, this function returns nullptr.
			*/

			T* that = nullptr;

			for (size_t i = 0; i < m_size; ++i) 
			{
				if (m_item[i].title() == title) 
				{
					that = &m_item[i];
				}
			}
			return that;
		}

	};


		template<typename T>
		std::ostream& operator<<(std::ostream& o, Collection<T>& that)
		{
			/*
			overload the insertion operator to insert the content of a Collection object into an
			 ostream object. Iterate over all elements in the collection and insert each one into 
			 the ostream object (do not add newlines).
			*/
		
			for (size_t i = 0; i < that.size(); ++i) 
			{
				o << that[i];
			}
			return o;
		}
}

#endif

