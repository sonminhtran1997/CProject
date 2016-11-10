#include "Queue.h"
//---------------------------------------------------------------------------------------------------------------------------
//	Function:	main()
//	File:		Main.cpp
//	Title:		Testing list and queue
//	Description:	This file contains function main() which tests list and queue
//	Programmer:	An Dien Tang
//	Date:		5/20/2015
//	Version:	1.0
//	Environment:	Hardware: Laptop Toshiba
//			Software:  Windows 8 for execution;
//			Complied under Visual Studio 2012
//	Input:		none
//	Output:	Screen display of list and queue
//	Calls:		list class and its inherited classes
//	Called By:	n/a
//	Parameters:	n/a
//	Returns:	EXIT_SUCCESS  = successful 
//				EXIT_FAILURE = failure
//	History Log:
//			5/20/2015  AT  completed version 1.0
// --------------------------------------------------------------------------------------------------------------------------
int main()
{
	using AT_ADT::list; // not the same as std::list<class T>
	using AT_ADT::queue;
	try
	{
		list mylist(5, 'X');
		list mylist2;
		list mylist3(mylist);
		list mylist4(mylist.begin(), mylist.end());
		cout << "mylist's size: " << mylist.getSize() << endl;
		cout << "mylist's front: " << mylist.front() << endl;
		cout << "mylist's back: " << mylist.back() << endl;
		cout << "mylist: " << mylist << endl;
		cout << "mylist2: " << mylist2 << endl;
		cout << "mylist3: " << mylist3 << endl;
		cout << "mylist4: " << mylist4 << endl;
		mylist.push_front('Y');
		mylist.push_front('Z');
		cout << mylist.pop_front() << endl;
		mylist2 = mylist; // a copy
		cout << "mylist: " << mylist << endl;
		mylist.push_back('A');
		mylist.push_back('B');
		cout << mylist.pop_back() << endl;
		cout << "mylist: " << mylist << endl;
		list::iterator listit(mylist.begin());
		cout << (listit++)->data << " ";
		cout << (++listit)->data << " ";
		cout << (listit--)->data << " ";
		cout << (--listit)->data << " ";
		cout << listit->data << endl;
		cout << "mylist: ";
		for(int i = 0; i < static_cast<int>(mylist.getSize()); i++)
			cout << mylist[i] << " ";
		cout << endl;
		cout << "mylist backward: ";
		for(int i = -1; i >= -static_cast<int>(mylist.getSize()); i--)
			cout << mylist[i] << " ";
		cout << endl;
		mylist.release();
		cout << "mylist: " << mylist << endl;
		cout << "mylist2: " << mylist2 << endl << endl;

		queue myqueue(5, 'X');
		queue myqueue2;
		queue myqueue3(myqueue);
		queue myqueue4(myqueue.begin(), myqueue.end());
		cout << "myqueue: " << myqueue << endl;
		cout << "myqueue2: " << myqueue2 << endl;
		cout << "myqueue3: " << myqueue3 << endl;
		cout << "myqueue4: " << myqueue4 << endl;
		myqueue.push('Y');
		myqueue.push('Z');
		cout << "myqueue's size: " << myqueue.getSize() << endl;
		cout << myqueue.pop() << endl;
		cout << "myqueue: " << myqueue << endl;
		myqueue.release();
		cout << "myqueue: " << myqueue << endl;
	}
	catch(exception e)
	{
		cerr << "program terminated: " << e.what() << endl;
		cin.get();
		return EXIT_FAILURE;
	}
	cin.get();  // keep window open
	return EXIT_SUCCESS;
}


