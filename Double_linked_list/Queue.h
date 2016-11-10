#include "List.h"
//---------------------------------------------------------------------------------------------------------------------------
//	Title:	queue Class
//	Description:This file contains the class definition for queue, with a test driver
//	Programmer:	An Dien Tang
//	Object Oriented Programming Using C++, Edition 2 By Ira Pohl
//		modified by An Dien Tang
//	Date: original: 5/15/2015
//	Version: 1.5
//	Environment: 	Intel Xeon PC
//	Software:	MS Windows 8 for execution;
//			Compiles under Microsoft Visual C++.Net 2012
//	class list: protectedly inherited from class list
//		Methods:
//			inline: 
//				queue() -- construct the empty queue
//				unsigned getSize()const  -- accessor, returns m_size
//				iterator begin()const -- returns address of first element
//				iterator end()const -- returns address of last element
//				datatype& pop()const  -- returns first element data
//				void push()const -- returns last element data
//				bool empty()const -- true if no elements
//				void release() -- removes all items from list
//			non-inline:
//				queue(size_t n_elements, datatype datum) --
//					create a queue of a specific size, all elements the same
//				queue(const queue& x); -- copy constructor
//				queue(iterator b, iterator e) -- constructor using iterators
//	History Log:
//			May 18, 2015, AT completed version 1.15
//---------------------------------------------------------------------------------------------------------------------------
namespace AT_ADT
{
	class queue: protected list
	{
	public:
		queue(): list(){}
		queue(size_t n_elements, datatype datum);
		queue(const queue& x);
		queue(iterator b, iterator e);
		unsigned getSize() const {return list::getSize();}
		iterator begin() const { return list::begin();}
		iterator end() const {return list::end();}
		datatype pop() {return list::pop_front();}
		void push(datatype element) {list::push_back(element);}
		bool empty()const {return list::empty();}
		void release() {list::release();}
		~queue() { release(); }
	};
	ostream& operator<<(ostream& sout, const queue& x);
}

