#ifndef BST_H
#define BST_H
//----------------------------------------------------------------------------
// A rudimentary Binary Search Tree program
// Compiled under MS Visual C++.Net 2010
// by Paul Bladek
// December, 2000
// revised April, 2005
// revised May, 2008
// revised May, 2010
// revised May, 2015
//----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <exception>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


namespace PB_BST
{
	int RIGHTHEAVY = 1;
	int LEFTHEAVY = -1;
	// CLASS DEFINITIONS 
	template<class T>
	//------------------------------------------------------------------------
	// BST NODE
	// REQUIRES Type T be able convert from int & have < & == defined
	//------------------------------------------------------------------------
	class node
	{
	public: 
		node(T d = 1) :m_data(d), m_height(1), left(nullptr), right(nullptr){}
		node(const node<T>& n); // Copy Constructor
		node<T>& operator=(const node<T>& n);
		T value()const {return m_data;}    // Accessor
		operator T()const {return m_data;}  // cast to data type
		void setdata(T d) {m_data = d;}
		int getHeight()const {return m_height;}
		int setHeight();
	private: 
		T m_data;
		int m_height;
	public:  // to freely use these
		node<T>* left;
		node<T>* right;
	}; 

	//---------------------------------------------------------------------------------
	// Function:	node(const node<T>& n)
	// Title:		Copy constructor 
	// Description:	a constructor for copying a tree
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		None
	// Called By:	None
	// Parameters:	const node<T>& n: a tree to copy
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>::node(const node<T>& n)
		:m_data(n.m_data), m_height(n.getHeight()), left(nullptr), right(nullptr)	
	{
		if(n.left != nullptr)
			left = new node<T>(*(n.left));
		if(n.right != nullptr)
			right = new node<T>(*(n.right));
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>& operator=(const node<T>& n)
	// Title:		operator for the equal
	// Description:	operator function for equal
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		getHeight()
	// Called By:	None
	// Parameters:	const node<T>& n: a tree to copy
	// Returns:		node<T>&: a new tree
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>& node<T>::operator=(const node<T>& n)  // overloaded =
	{
		if(this != &n)
		{
			m_data = n.m_data;
			m_height = n.getHeight();
			if(n.left != nullptr)
				left = new node<T>(*(n.left));
			else
				left = nullptr;
			if(n.right != nullptr)
				right = new node<T>(*(n.right));
			else
				right = nullptr;
		}
		return *this;
	} 

	//---------------------------------------------------------------------------------
	// Function:	setHeight()
	// Title:		Set Height
	// Description:	Set the height for the tree
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		setHeight()
	// Called By:	setHeight()
	//				deltree()
	//				insert()
	// Parameters:	None
	// Returns:		int: a number of the current height
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	int node<T>::setHeight()
	{
		int lHeight = 0;
		int rHeight = 0;
		m_height = 1;

		if(left != nullptr)	
			lHeight = left->setHeight();
		if(right != nullptr)
			rHeight = right->setHeight();
		return (m_height += (lHeight > rHeight) ? lHeight : rHeight);
	}

	//------------------------------------------------------------------------
	// Binary Search Tree -- Basic Implementation
	//------------------------------------------------------------------------
	template <class T>
	class bst
	{    
	public:
		bst() :root(nullptr), parentptr(&root){}
		bst(const bst<T>& t) :root(nullptr), parentptr(&root)
		{if(t.root != nullptr) root = new node<T>(*(t.root));}

		node<T>* &getroot(){return root;}

		bool isempty()const{return (root == nullptr);}

		bst<T>& operator=(const bst<T>& t);
		bst<T>& operator+=(const bst<T>& t);
		bst<T>& operator+=(const T d){insert(d, root); return *this;}
		bst<T> operator+(const T d)
		{bst<T> temp = *this; temp.insert(d, temp.root); return temp;}

		void findfirst(const T& d, node<T>* &np, node<T>* &match);
		void insert(T d);
		void deltree() {deltree(root);}
		void print(ostream& out)const {print(root, out);}
		void print(node<T>* cur, ostream& out)const;
		void printXlevel(ostream& out)const {printXlevel(root, out);}
		void printXlevel(node<T>* cur, ostream& out) const;
		T popnode(node<T>* &cur);
		T poplow(node<T>* &cur);
		T pophigh(node<T>* &cur);
		T popfirst(const T& d, node<T>* np);
		int getHeight()const
		{if(isempty()) return 0; return root->getHeight();}
		void setHeight() {if(root != nullptr) root->setHeight();}
		int getNumberOfNodes()const;
		int getNumberOfNodes(node<T>* np)const;
		~bst(){deltree(root);}
	protected:		
		void setLevel(node<T>* cur, vector<T>& levelVector, int level2print,
			int position = 0) const;
		void insert(T d, node<T>* &cur);
		node<T>* root; // root of this tree
		node<T>** parentptr; // holding pointer needed by some functions

		void addtree(const node<T>* np); // used by +
	private:
		node<T>* rotateRight(node<T> *nodeN);
		node<T>* rotateLeft(node<T> *nodeN);
		node<T>* rotateRightLeft(node<T> *nodeN);
		node<T>* rotateLeftRight(node<T> *nodeN);
		node<T>* rebalance(node<T> *&nodeN);
		int getHeightDifference(const node<T> *const nodeN)const;
		void deltree(node<T>* &cur);
	}; 

	//---------------------------------------------------------------------------------
	// Function:	bst<T>& operator=(const node<T>& n)
	// Title:		operator for the equal
	// Description:	operator function for equal
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		deltree()
	// Called By:	None
	// Parameters:	const bst<T>& t: a tree to copy
	// Returns:		bst<T>&: a new tree
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	bst<T>& bst<T>::operator=(const bst<T>& t)   
	{
		if(this != &t)
		{
			if(!isempty())
				deltree(root);
			if(!t.isempty())
			{
				root = new node<T>(*(t.root));
			}
		}
		return *this;
	}

	//---------------------------------------------------------------------------------
	// Function:	bst<T>& operator+=(const node<T>& n)
	// Title:		operator for the equal plus
	// Description:	operator function for equal plus
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		addtree()
	// Called By:	None
	// Parameters:	const bst<T>& t: a tree to add
	// Returns:		bst<T>&: a new tree
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	bst<T>& bst<T>::operator+=(const bst<T>& t)   
	{
		addtree(t.root);
		return *this;
	}

	//---------------------------------------------------------------------------------
	// Function:	void addtree(const node<T>* np)
	// Title:		Add tree
	// Description:	Add a tree into a tree
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		addtree()
	//				insert()
	// Called By:	operator+=()
	//				addtree()
	// Parameters:	const node<T>* np: a tree to add
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::addtree(const node<T>* np) 	
	{
		if(np != nullptr)
		{
			addtree(np->left);
			addtree(np->right);
			insert(np->value(), root);
		}
	}

	//---------------------------------------------------------------------------------
	// Function:	void findfirst(const T& d, node<T>* &np, node<T>* &match)
	// Title:		Find first
	// Description:	Find and return the first node that matchs with the input node
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		findfirst()
	// Called By:	findfirst()
	// Parameters:	const T& d: a value to find
	//				node<T>* &np: a tree to find
	//				node<T>* &match: a tree to set if can find the value
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::findfirst(const T& d, node<T>* &np, node<T>* &match)
	{
		if(match != nullptr)
			return;
		if(np != nullptr)
		{
			findfirst(d, np->left, match);
			if(d == np->value())
			{	
				match = np;
				parentptr = &np;
				return;
			}
			findfirst(d, np->right, match);
		}
	}

	//---------------------------------------------------------------------------------
	// Function:	void insert(T d)
	// Title:		Insert
	// Description:	Insert a new value
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		insert()
	// Called By:	None
	// Parameters:	T d: a value to add
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::insert(T d)
	{
		insert(d, root);
	}

	//---------------------------------------------------------------------------------
	// Function:	void insert(T d, node<T>* &cur)
	// Title:		Insert
	// Description:	Insert a new node
	// Programmer:	Paul Bladek
	//				An Dien Tang
	// Date:		6/2/15
	// Version:		1.5
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		setHeight()
	//				rebalance()
	//				insert()
	// Called By:	insert()
	//				insert()
	// Parameters:	T d: a value to add
	//				node<T>* &cur: a tree to add
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0
	//				6/2/15 AT completed v 1.5	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::insert(T d, node<T>* &cur)
	{
		if(cur == nullptr)
		{                       
			cur = new node<T>(d);
			if(isempty())
				root = cur;
			root->setHeight();
			root = rebalance(root);
		}
		else
		{
			if(d < cur->value())
				insert(d, cur->left);
			else
				insert(d, cur->right);
		}
	} 

	//---------------------------------------------------------------------------------
	// Function:	void print(node<T>* cur, ostream& out)const
	// Title:		Print
	// Description:	Print out the node with its height
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		All of the nodes with their heights
	// Calls:		print()
	//				getHeight()
	// Called By:	print()
	// Parameters:	ostream& out: output stream
	//				node<T>* &cur: a tree to print
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::print(node<T>* cur, ostream& out)const 
	{
		if(cur != nullptr)
		{
			print(cur->left, out);
			out << cur->value() << "(" << cur->getHeight() << ") ";
			print(cur->right, out);
		}
	} 

	//---------------------------------------------------------------------------------
	// Function:	void bst<T>::setLevel(node<T>* cur, vector<T>& levelVector,
	//				int level2print, int position) const
	// Title:		Set level
	// Description:	Set the level of each node
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		setLevel()
	// Called By:	setLevel()
	//				printXlevel()
	// Parameters:	node<T>* cur: a current tree to set level
	//				vector<T>& levelVector: level
	//				int level2print: current level
	//				int position: current position
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::setLevel(node<T>* cur, vector<T>& levelVector,
		int level2print, int position) const 
	{	
		static int currentLevel = -1;
		if(level2print < 0)
			return;
		if(cur != nullptr)
		{
			currentLevel++;
			if(currentLevel < level2print)
				setLevel(cur->left, levelVector, level2print, position * 2);
			if(currentLevel == level2print)
				levelVector[position] = cur->value();
			if(currentLevel < level2print)
				setLevel(cur->right, levelVector, level2print,
				position * 2 + 1);
			currentLevel--;
		}
	} 

	//---------------------------------------------------------------------------------
	// Function:	void printXlevel(node<T>* cur, ostream& out) const
	// Title:		Print x level
	// Description:	Print out the tree
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		getHeight()
	//				setLevel()
	// Called By:	setLevel()
	// Parameters:	node<T>* cur: a current tree to print
	//				ostream& out: output stream
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	    
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::printXlevel(node<T>* cur, ostream& out) const 
	{	
		if(cur == nullptr)
			return;
		const size_t SPACER = 64;
		const T NO_NODE = static_cast<T>(-1);
		const int PRINT_MAX = 6;
		vector<vector<T>> treeVector(cur->getHeight());

		for(int i = 0; i < cur->getHeight(); i++)
		{
			out << "level " << i + 1 << ": ";
			if(i < PRINT_MAX)
			{
				int size = static_cast<int>(pow(2.0, i));
				treeVector[i] = vector<T>(size, NO_NODE);
				setLevel(cur, treeVector[i], i);
				out << string(SPACER / (2 * size), ' '); 
				for(int j = 0; j < static_cast<int>(treeVector[i].size());
					j++)
				{
					if(treeVector[i][j] != NO_NODE)
						out  << treeVector[i][j];
					else
						out  << ' ';
					out << string(SPACER / size - 1, ' ');
				}
			}
			else 
				out << "  . . .";

			out << endl;
		}
	} 

	//---------------------------------------------------------------------------------
	// Function:	void deltree(node<T>* &cur)
	// Title:		Delete tree
	// Description:	Delete the tree
	// Programmer:	Paul Bladek
	// Date:		6/2/15
	// Version:		1.5
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		deltree()
	//				setHeight()
	// Called By:	None
	// Parameters:	node<T>* cur: a current tree to delete
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0
	//				6/2/15 AT completed v 1.5
	//---------------------------------------------------------------------------------
	template <class T>
	void bst<T>::deltree(node<T>* &cur)   
	{
		if(cur != nullptr)
		{
			deltree(cur->left);
			deltree(cur->right);
			delete cur;
			cur = nullptr;
			if(root != nullptr)
				root->setHeight();
		}
	} 

	//---------------------------------------------------------------------------------
	// Function:	T popnode(node<T>* &cur)
	// Title:		Pop node
	// Description:	Pop a node in a tree
	// Programmer:	Paul Bladek
	//				An Dien Tang
	// Date:		6/3/15
	// Version:		1.5
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		setdata()
	//				pophigh()
	//				value()
	//				rebalance()
	// Called By:	deltree()
	// Parameters:	node<T>* cur: a current tree to find
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	  
	//				3/6/15 AT completed v 1.5
	//---------------------------------------------------------------------------------
	template <class T>
	T bst<T>::popnode(node<T>* &cur)  
	{ 
		bool curOnTheLeft = true;
		bool curIsRoot = true;
		if(cur == nullptr)
			throw(invalid_argument("Pointer does not point to a node"));
		T contents = cur->value();
		node<T>* temptr = root;
		if(root != cur)
		{
			curIsRoot = false;
			while(temptr->left != cur && temptr->right != cur)
				if(temptr->value() > cur->value())
					temptr = temptr->left;
				else
					temptr = temptr->right;
			if(temptr->left != cur)
				curOnTheLeft = false;
		}
		if(cur->left == nullptr && cur->right == nullptr)
		{ // no children
			delete cur;
			cur = nullptr;
		}
		else if(cur->left == nullptr)
		{ // only right child
			node<T>* temp = cur->right;
			delete cur;
			cur = temp;
		}
		else if(cur->right == nullptr)
		{ // only left child
			node<T>* temp = cur->left;
			delete cur;
			cur = temp;
		}
		else
		{ // two children
			node<T>* temp = cur->left;
			while(temp->right != nullptr)
				temp = temp->right;
			cur->setdata(temp->value());
			pophigh(cur->left);
			curIsRoot = true; // no need to assgin the address again
			// pops rightmost node of left child and
			// places that value into the current node
		}
		if(curIsRoot == false)
		{
			if(curOnTheLeft == true)
				temptr->left = cur;
			else
				temptr->right = cur;
		}
		if(root != nullptr)
		{
			root->setHeight();
			root = rebalance(root);
		}
		return contents;
	}

	//---------------------------------------------------------------------------------
	// Function:	T poplow(node<T>* &cur)
	// Title:		Pop low
	// Description:	Pop the left most child in a tree
	// Programmer:	Paul Bladek
	//				An Dien Tang
	// Date:		6/3/15
	// Version:		1.5
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		setHeight()
	//				poplow()
	//				value()
	//				rebalance()
	// Called By:	poplow()
	// Parameters:	node<T>* cur: a current tree to find
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	  
	//				3/6/15 AT completed v 1.5
	//---------------------------------------------------------------------------------
	template <class T>
	T bst<T>::poplow(node<T>* &cur)  
	{
		if(cur == nullptr)
			throw(invalid_argument("Pointer does not point to a node"));
		if(cur->left == nullptr)
		{
			T temp = cur->value();
			node<T>* temptr = cur->right;
			delete cur;
			cur = temptr;
			if(root != nullptr)
				root->setHeight();
			root = rebalance(root);
			return temp;
		}
		return poplow(cur->left);
	}


	//---------------------------------------------------------------------------------
	// Function:	T pophigh(node<T>* &cur)
	// Title:		Pop high
	// Description:	Pop the right most child in a tree
	// Programmer:	Paul Bladek
	//				An Dien Tang
	// Date:		6/3/15
	// Version:		1.5
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		setHeight()
	//				pophigh()
	//				value()
	//				rebalance()
	// Called By:	pophigh()
	// Parameters:	node<T>* cur: a current tree to find
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	  
	//				3/6/15 AT completed v 1.5
	//---------------------------------------------------------------------------------
	template <class T>
	T bst<T>::pophigh(node<T>* &cur)  
	{
		if(cur == nullptr)
			throw(invalid_argument("Pointer does not point to a node"));
		if(cur->right == nullptr)
		{
			T temp = cur->value();
			node<T>* temptr = cur->left;
			delete cur;
			cur = temptr;
			if(root != nullptr)
				root->setHeight();
			root = rebalance(root);
			return temp;
		}
		return pophigh(cur->right);
	}

	//---------------------------------------------------------------------------------
	// Function:	T popfirst(const T& d, node<T>* np)
	// Title:		Pop first
	// Description:	Pop the first node in a tree that matchs the data
	// Programmer:	Paul Bladek
	//				An Dien Tang
	// Date:		6/3/15
	// Version:		1.5
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		findfirst()
	//				popnode()
	// Called By:	findfirst()
	// Parameters:	node<T>* np: a current tree to find
	//				const T& d: a data to find
	// Returns:		void
	// History Log:
	//				2005 PB completed v 1.0	  
	//				3/6/15 AT completed v 1.5
	//---------------------------------------------------------------------------------
	template <class T>
	T bst<T>::popfirst(const T& d, node<T>* np)
	{
		node<T>* matchptr = nullptr;
		findfirst(d, root, matchptr);
		if(*parentptr != nullptr)
		{
			if((*parentptr)->value() == d)
				return popnode((*parentptr));
		}
		if(root != nullptr)
			root->setHeight();
		return 0;
	}

	//---------------------------------------------------------------------------------
	// Function:	int getNumberOfNodes()const
	// Title:		Get number of nodes
	// Description:	Calculate and return the total number of nodes in the tree
	// Programmer:	Paul Bladek
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		getNumberOfNodes()
	// Called By:	findfirst()
	// Parameters:	None
	// Returns:		int: the numbers of nodes
	// History Log:
	//				2005 PB completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	int bst<T>::getNumberOfNodes()const
	{
		return getNumberOfNodes(root);
	}

	//---------------------------------------------------------------------------------
	// Function:	int getNumberOfNodes(node<T>* np)const
	// Title:		Get number of nodes
	// Description:	Calculate and return the total number of nodes in the tree
	// Programmer:	Paul Bladek
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Hardware:	IBM Pentium  
	//				Software:	Win98, ME, NT, Win2000, XP for execution;
	// Input:		None
	// Output:		None
	// Calls:		getNumberOfNodes()
	// Called By:	getNumberOfNodes()
	//				getNumberOfNodes
	// Parameters:	node<T>* np: current tree
	// Returns:		int: the numbers of nodes
	// History Log:
	//				2005 PB completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	int bst<T>::getNumberOfNodes(node<T>* np)const
	{
		int count  = 1;
		if(np != nullptr)
		{ 
			count += getNumberOfNodes(np->left);			
			count += getNumberOfNodes(np->right);
			return count;
		}
		return 0;
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>* rotateRight(node<T> *nodeN)
	// Title:		Rotate right
	// Description:	Rotate the current node to balance
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		None
	// Called By:	rebalance()
	//				rotateRightLeft()
	//				rotateLeftRight()
	// Parameters:	node<T>* nodeN: a current node to rotate
	// Returns:		node<T>*: a new node that is balance
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>* bst<T>::rotateRight(node<T> *nodeN)
	{
		node<T>* temp = nodeN->left;
		nodeN->left= temp->right;
		temp->right = nodeN;
		return temp;
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>* rotateLeft(node<T> *nodeN)
	// Title:		Rotate left
	// Description:	Rotate the current node to balance
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		None
	// Called By:	rebalance()
	//				rotateRightLeft()
	//				rotateLeftRight()
	// Parameters:	node<T>* nodeN: a current node to rotate
	// Returns:		node<T>*: a new node that is balance
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>* bst<T>::rotateLeft(node<T> *nodeN)
	{
		node<T>* temp = nodeN->right;
		nodeN->right= temp->left;
		temp->left = nodeN;
		return temp;
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>* rotateRightLeft(node<T> *nodeN)
	// Title:		Rotate right left
	// Description:	Rotate the current node to balance
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		rotateRight()
	//				rotateLeft()
	// Called By:	rebalance()
	// Parameters:	node<T>* nodeN: a current node to rotate
	// Returns:		node<T>*: a new node that is balance
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>* bst<T>::rotateRightLeft(node<T> *nodeN)
	{
		nodeN->right= rotateRight(nodeN->right);
		node<T>* temp = rotateLeft(nodeN);
		return temp;
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>* rotateLeftRight(node<T> *nodeN)
	// Title:		Rotate left right
	// Description:	Rotate the current node to balance
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		rotateRight()
	//				rotateLeft()
	// Called By:	rebalance()
	// Parameters:	node<T>* nodeN: a current node to rotate
	// Returns:		node<T>*: a new node that is balance
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>* bst<T>::rotateLeftRight(node<T> *nodeN)
	{
		nodeN->left= rotateLeft(nodeN->left);
		node<T>* temp = rotateRight(nodeN);
		return temp;
	}

	//---------------------------------------------------------------------------------
	// Function:	int getHeightDifference(const node<T> *const nodeN)const
	// Title:		Get height difference
	// Description:	Get the difference in height between 2 children of a node
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		getHeight()
	// Called By:	rebalance()
	// Parameters:	const node<T> *const nodeN: a current node to find height
	// Returns:		int: the difference in height
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	int bst<T>::getHeightDifference(const node<T> *const nodeN)const
	{
		if (nodeN->left != nullptr)
			if (nodeN->right != nullptr)
				return ((nodeN->right->getHeight()) - (nodeN->left->getHeight()));
			else
				return -nodeN->left->getHeight();
		else if (nodeN->right != nullptr)
			return nodeN->right->getHeight();
		else
			return 0;
	}

	//---------------------------------------------------------------------------------
	// Function:	node<T>* rebalance(node<T> *nodeN)
	// Title:		Rebalance
	// Description:	Rebalance the whole tree
	// Programmer:	An Dien Tang
	// Date:		6/3/15
	// Version:		1.0
	// Environment:	Laptop Toshiba 
	//				Software: MS Windows 8
	//				Compiles under Microsoft Visual C++.Net 2012
	// Input:		None
	// Output:		None
	// Calls:		rotateRight()
	//				rotateLeft()
	//				rebalance()
	//				getHeightDifference()
	//				rotateRightLeft()
	//				rotateLeftRight()
	//				setHeight
	// Called By:	rebalance()
	// Parameters:	node<T>* nodeN: a current node to rotate
	// Returns:		node<T>*: a new node that is balance
	// History Log: 
	//				3/6/15 AT completed v 1.0
	//---------------------------------------------------------------------------------
	template <class T>
	node<T>* bst<T>::rebalance(node<T> *&nodeN)
	{
		node<T> * temp = nodeN;
		if (nodeN != nullptr)
		{
			nodeN->left = rebalance(nodeN->left);
			nodeN->right = rebalance(nodeN->right);
			if (getHeightDifference(nodeN) > RIGHTHEAVY)
			{
				if (getHeightDifference(nodeN->right) == LEFTHEAVY)
					temp = rotateRightLeft(nodeN);
				else
					temp = rotateLeft(nodeN);
			}
			else if (getHeightDifference(nodeN) < LEFTHEAVY)
			{
				if (getHeightDifference(nodeN->left) == RIGHTHEAVY)
					temp = rotateLeftRight(nodeN);
				else
					temp = rotateRight(nodeN);
			}
			nodeN = temp;
		}
		root->setHeight();
		return temp;
	}

	// ----------------------------------------------------------------------------
	//	method:			ostream& operator<<(ostream& sout, bst<T> tree)
	//	description:	prints out the tree object to the stream
	//	Input:			None
	//	Output:			Screen display of tree information
	//	Calls:			bst<T>::print()
	//	Called By:		None
	//	Parameters:		ostream & sout  -- the stream used for output
	//					bst<T> -- the object to print
	//	Returns:		a reference to sout 
	//	History Log:
	//					6/3/15  AT  completed version 1.0
	// ----------------------------------------------------------------------------
	template <class T>
	ostream& operator<<(ostream& out, bst<T> tree)
	{
		tree.print(tree.getroot(), out);
		return out;
	}

} // end namespace PB_BST

#endif
