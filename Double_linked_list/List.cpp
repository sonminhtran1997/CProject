#include "List.h"
namespace AT_ADT
{
	//-----------------------------------------------------------------------------------------------------------------
	// constructor
	//-----------------------------------------------------------------------------------------------------------------
	list::list(size_t n_elements, datatype datum) 
		:m_size(0), head(nullptr), tail(nullptr)
	{
		if(n_elements <= 0)
			throw out_of_range("Empty list");
		for(size_t i = 0; i < n_elements; ++i)
			push_front(datum);
	}

	//-----------------------------------------------------------------------------------------------------------------
	// copy constructor
	//-----------------------------------------------------------------------------------------------------------------
	list::list(const list& x)
		: m_size(0), head(nullptr), tail(nullptr)
	{
		list::iterator r_it = x.begin();
		push_back(*r_it++);
		while (r_it != x.begin())
			push_back(*r_it++);
	}

	//-----------------------------------------------------------------------------------------------------------------
	// constructor using iterators, copies from b to one before e
	//-----------------------------------------------------------------------------------------------------------------
	list::list(iterator b, iterator e)
		:m_size(0), head(nullptr), tail(nullptr)
	{
		if (b != nullptr)
		{
			push_back(*b++);
			while (b != e->next)
				push_back(*b++);
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	// insert element at front of list
	//-----------------------------------------------------------------------------------------------------------------
	void list::push_front(datatype datum) 
	{
		listelem* temp = new listelem(datum, tail, head);
		m_size++;
		if (!empty())
		{
			head = temp;
			tail->next = head;
			temp->next->prev = temp;
		}
		else
		{
			head = tail = temp;
			head->next = tail;
			head->prev = head;
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	// removes front element and returns the data from that element
	//-----------------------------------------------------------------------------------------------------------------
	datatype list::pop_front() 
	{
		if(head == nullptr)
			throw runtime_error("Empty list");
		m_size--;
		datatype data = head->data;
		iterator temp = begin();
		tail->next = nullptr;
		temp++;
		delete head;
		head = temp;
		if (!empty())
		{
			head->prev = tail;
			tail->next = head;
		}
		else
			tail = head = nullptr;
		return data;
	} 

	//-----------------------------------------------------------------------------------------------------------------
	// insert element at end of list
	//-----------------------------------------------------------------------------------------------------------------
	void list::push_back(datatype datum)
	{
		listelem* temp = new listelem(datum, tail, head);
		m_size++;
		if (!empty())
		{
			tail->next = temp;
			tail = temp;
			head->prev = temp;
		}
		else
		{
			head = tail = temp;
			head->next = tail;
			head->prev = head;
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	// removes end element and returns the data from that element
	//-----------------------------------------------------------------------------------------------------------------
	datatype list::pop_back()
	{
		if(head == nullptr)
			throw runtime_error("Empty list");
		m_size--;
		datatype data = tail->data;
		iterator temp = end();
		head->prev = nullptr;
		--temp;
		delete tail;
		tail = temp;
		if (!empty())
		{
			head->prev = tail;
			tail->next = head;
		}
		else
			tail = head = nullptr;
		return data;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// empties the list
	//-----------------------------------------------------------------------------------------------------------------
	void list::release() 
	{
		while (head != nullptr)
			pop_front();
	}

	//-----------------------------------------------------------------------------------------------------------------
	// returns a copy of rlist
	//-----------------------------------------------------------------------------------------------------------------
	list list::operator=(const list & rlist) 
	{
		if(&rlist != this)
		{
			list::iterator r_it = rlist.begin();
			release();
			if (r_it != nullptr)
			{
				push_back(*r_it++);
				while (r_it != rlist.begin())
					push_back(*r_it++);
			}
		}
		return *this;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// [] operator -- l-value
	//-----------------------------------------------------------------------------------------------------------------
	datatype& list::operator[](int index)
	{
		iterator it;
		if(index >= 0)
		{
			if(index >= static_cast<int>(getSize()))
				throw out_of_range("index out-of-range");
			it = begin();
			for(int i = 0; i < index; i++)
				it++;
		}
		else
		{
			if(index < -(static_cast<int>(getSize())))
				throw out_of_range("index out-of-range");
			it = end();
			for(int i = -1; i > index; i--)
				it--;
		}
		return *it;
	}
	//-----------------------------------------------------------------------------------------------------------------
	// [] operator -- r-value
	//-----------------------------------------------------------------------------------------------------------------
	const datatype& list::operator[](int index)const
	{
		iterator it;
		if(index >= 0)
		{
			if(index >= static_cast<int>(getSize()))
				throw out_of_range("index out-of-range");
			it = begin();
			for(int i = 0; i < index; i++)
				it++;
		}
		else
		{
			if(index < -(static_cast<int>(getSize())))
				throw out_of_range("index out-of-range");
			it = end();
			for(int i = -1; i > index; i--)
				it--;
		}
		return *it;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// pre-increment
	//-----------------------------------------------------------------------------------------------------------------
	list::iterator list::iterator::operator++() 
	{
		if(ptr == nullptr)
			throw runtime_error("nullptr pointer");
		ptr = ptr->next;
		return *this;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// post-increment
	//-----------------------------------------------------------------------------------------------------------------
	list::iterator list::iterator::operator++(int)
	{
		if(ptr == nullptr)
			throw runtime_error("nullptr pointer");
		iterator temp = *this;
		ptr = ptr->next;
		return temp;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// pre-decrement
	//-----------------------------------------------------------------------------------------------------------------
	list::iterator list::iterator::operator--() 
	{ 
		if(ptr == nullptr)
			throw runtime_error("nullptr pointer");
		ptr = ptr->prev;
		return *this;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// post-decrement
	//-----------------------------------------------------------------------------------------------------------------
	list::iterator list::iterator::operator--(int)
	{ 
		if(ptr == nullptr)
			throw runtime_error("nullptr pointer");
		iterator temp = *this;
		ptr = ptr->prev;
		return temp;
	}

	//-----------------------------------------------------------------------------------------------------------------
	// prints out a list
	//-----------------------------------------------------------------------------------------------------------------
	ostream& operator<<(ostream& sout, const list& x) 
	{
		list::iterator p = x.begin(); // gets x.h
		if (p != nullptr)
		{
			sout << "(";
			sout << *p;
			++p;
			while (p != x.begin())
			{
				sout << ",";
				sout << *p;
				++p; // advances iterator using next
			}
			sout << ")\n";
		}
		return sout;
	}
} 

