# include <iostream>
# include <string>
# include <iomanip>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

int main()

{
	string name1, name2;
	int num1, num2;
	double price1 ,price2, totalcostofitems;
	const double TAX = 8.675/100;
	double tax ;
	name1= "mechanical pencil";
	name2= "binder";
	num1=2;
	num2=3;
	price1=2.50;
	price2=7.25;
	totalcostofitems = num1*price1 +num2*price2;
	tax = totalcostofitems*TAX;
	totalcostofitems+= tax;

	cout<<" Enter name of item 1:";

	getline(cin,name1);

	cout<<" Enter number of mechanical pencils and the price of each:";

	cin>>   num1>>      price1;

	cout<<"Enter name of item 2";

	getline(cin, name2);

	cout<< "Enter number of binders and the price of each:";

	cin>>   num2>>      price2;

	cout<<fixed<<showpoint<<setprecision(2);

	cout<<setw(6)<< "Item"<<setw(6)<<"Count"<<setw(6)<<"Price"<<endl;

	cout<<setw(6)<<name1<<setw(6)<<num1<<setw(6)<<num1*price1<<endl;

	cout<<setw(6)<<name2<<setw(6)<<num2<<setw(6)<<num2*price2<<endl;

	cout<<setw(6)<<"Tax"<<setw(12)<<tax<<endl;

	cout<<setw(6)<<"Total"<<setw(12)<<totalcostofitems <<endl;

	return 0;

}