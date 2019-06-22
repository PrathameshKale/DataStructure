#include<iostream>
#include<string.h>
#include "Header.h";
using namespace std;
int main() 
{
	HashTable<int, string> players;
	players.put(250,"sachin");
	players.put(953, "yuvi");
	players.put(482, "virat");
	players.put(252, "dhoni");
    
	players.print();
	cout << "Get the perticular value: " << endl;
	string name;
	players.Get(482,name);
	cout << "Value is: " << name;

	cout << "Enter key for remove: ";
	int k;
	cin >> k;
	if (!players.remove(k))
		cout << "Not remove " << k << "Entry: "<<endl;
	players.print();
}