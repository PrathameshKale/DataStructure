#include<iostream>
#include "Header.h"
using namespace std;
int main() 
{
	int val;
	int size;
	cout << "Enter size " << endl;
	cin >> size;
	stack <int> s(size);
	while (cout<<"Enter value for add: ", cin>> val, val)
	{
		s.push(val);
	}
	
	cout << "removing: " << endl;
	try {

		for (int i = 0; i < size; i++)
		{

			//cout << s.peek() << endl;
			cout << s.pop() << endl;
		}
	}   catch (const char* messege) {
		cerr << messege;
	}
}