#include<iostream>
#include "Header.h"
using namespace std;
int main()
{
	List<int> list;
	int val;
	while (cout << "Enter the value: ", cin >> val, val)
	{
		list.addLast(val);
	}
	list.print();
	int vlaueToSearch, valueToAdd, occurance;

	/*cout << "Enter where to add After what: " << endl;
	cin >> vlaueToSearch;
	cout << "Enter value for insert: " << endl;
	cin >> valueToAdd;
	list.addAfter(vlaueToSearch, valueToAdd);
	list.print();
	*/

	/* cout << "Enter where to add before what: " << endl;
	cin >> vlaueToSearch;
	cout << "Enter value for insert: " << endl;
	cin >> valueToAdd;
	list.addBefore(vlaueToSearch, valueToAdd);
	list.print();
	*/

	/*	cout << "Enter where to add : " << endl;
		cin >> vlaueToSearch;
		cout << "Enter value for replace: " << endl;
		cin >> valueToAdd;
		cout << "Enter which occuarnce value for replace: " << endl;
		cin >> occurance;
		list.replace(vlaueToSearch, valueToAdd, occurance);
		list.print();
		*/
	/*int valToRemove;
	cout << "Emter value for remove:" << endl;
	cin >> valToRemove;
	list.remove(valToRemove);

	list.print();
	*/
	cout << "removing all: " << endl;
	list.removeAll();
	list.print();
}