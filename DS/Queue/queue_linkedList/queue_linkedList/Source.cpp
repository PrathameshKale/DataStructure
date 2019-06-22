#include<iostream>
#include "Header.h"
using namespace std;
int main()
{
	queue q;
	int val;
	while (cout<<"Enter the value: ", cin>>val, val)
	{
		q.push(val);
	}
	cout << "queue elemets is : " << endl;
	q.print();

	//cout << "enter the remove elemenst: " << endl;
	//int s;
	//cin >> s;
	
	cout << "after remove queue elemets is : " << endl;
	q.pop();
	cout << "after remove:" << endl;
	q.print();
}