#include "Queue.h"
namespace AT_ADT
{
	//-----------------------------------------------------------------------------------------------------------------
	// constructor
	//-----------------------------------------------------------------------------------------------------------------
	queue::queue(size_t n_elements, datatype datum)
		:list()
	{
		if(n_elements <= 0)
			throw out_of_range("Empty list");
		for(size_t i = 0; i < n_elements; ++i)
			push(datum);
	}
	
	//-----------------------------------------------------------------------------------------------------------------
	// copy constructor
	//-----------------------------------------------------------------------------------------------------------------
	queue::queue(const queue& x)
		:list()
	{
		list::iterator r_it = x.begin();
		push(*r_it++);
		while (r_it != x.begin())
			push(*r_it++);
	}

	//-----------------------------------------------------------------------------------------------------------------
	// constructor using iterators, copies from b to one before e
	//-----------------------------------------------------------------------------------------------------------------
	queue::queue(iterator b, iterator e)
		:list()
	{
		if (b != nullptr)
		{
			push(*b++);
			while (b != e->next)
				push(*b++);
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	// prints out a list
	//-----------------------------------------------------------------------------------------------------------------
	ostream& operator<<(ostream& sout, const queue& x) 
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

