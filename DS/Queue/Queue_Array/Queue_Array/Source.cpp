#include<iostream>
#include "Header.h"
int main()
{
	int val;
	queue q;
	while (cout<<"Enter the value: ", cin>>val, val)
	{
		q.push(val);
	}

	cout << "remove the elements: " << endl;
	try{
		for (int i = 0; i < 10; i++)
		{
			int res = q.pop();
			cout << res << endl;
		}
	}
	catch (const char* messege)
	{
		cerr << messege << endl;
	}
}