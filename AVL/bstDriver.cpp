#include <iostream>
#include <cstdlib>
#include "bst.h"
using namespace std;

//-------------------------------------------------------------------------------------------
//	Function:		main()
//	File:			Main.cpp
//	Title:			Testing Tree
//	Description:	This file contains function main() which tests Tree
//	Programmer:		An Dien Tang
//	Date:			6/3/2015
//	Version:		1.0
//	Environment:	Hardware: Laptop Toshiba
//					Software:  Windows 8 for execution;
//					Complied under Visual Studio 2012
//	Input:			Information of Tree
//	Output:			Screen display of Tree
//	Calls:			node class and its inherited classes
//	Called By:		n/a
//	Parameters:		n/a
//	Returns:		EXIT_SUCCESS  = successful 
//					EXIT_FAILURE = failure
//	History Log:
//					6/3/2015  AT  completed version 1.0
// ------------------------------------------------------------------------------------------
int main(void)
{
	using PB_BST::bst;
	using PB_BST::node;
	try
	{
		bst<char> tree;
		node<char>* marker = NULL;
		char c;
		cout << "enter some characters, followed by <Enter>.\n" ;
		do
		{ 
			cin.get(c);
			if(c == '\n')
				break;
			tree.insert(c); 
		}
		while(1);
		bst<char> tree2 = tree; // test overloaded =
		tree2 += tree; // test overloaded +
		cout << "tree 1:" << endl;		
		cout << tree << " : " << tree.getNumberOfNodes()
			<< "nodes" << endl;  // test overloaded << and print()
		tree.printXlevel(cout);
		cout  << endl << "tree 2:" << tree2 
			<< tree2.getNumberOfNodes() << "nodes" << endl;
		tree2.printXlevel(cout);
		cout << endl << endl << "Enter character to match: ";
		cin >> c;
		tree.findfirst(c, tree.getroot(), marker);
 
		// set marker to first match of c
		if(marker != NULL)
			cout << marker->value();
		else
			cout << "not found";
		cout << "\n Enter character to delete: ";
		cin >> c;
		cin.ignore(256, '\n');
		c = tree.popfirst(c, tree.getroot());
		cout << tree << endl;
		tree.printXlevel(cout);

		// test popfirst(), popnode(), poplow()	
		tree.deltree();  //delete first tree
		tree2 += 'Z';     // add in another element , test +=
		tree2 = tree2 + 'Y';  // test +		
		cout << tree2 << endl;
		cout << "tree 1:" << endl;		
		cout << tree << " : " << tree.getNumberOfNodes()
			<< "nodes" << endl;  // test overloaded << and print()
		tree.printXlevel(cout);
		cout  << endl << "tree 2:" << tree2 
			<< tree2.getNumberOfNodes() << "nodes" << endl;
		tree2.printXlevel(cout);
		cout << endl;
		tree2.deltree();  //delete second tree  */
	}
	catch(exception e)
	{
		cout << "Exception: " << e.what() << endl;
		cout << "press \"Enter\" to continue" << endl;
		cin.get(); // keep window open
		return EXIT_FAILURE;
	}
	catch(...)
	{
		cout << "Unknown Exception: " << endl;
		cout << "press \"Enter\" to continue" << endl;
		cin.get(); // keep window open
		return EXIT_FAILURE;
	}
	cout << "press \"Enter\" to continue" << endl;
	cin.get(); // keep window open
	return EXIT_SUCCESS;
} 


