#include<iostream>
#include<string.h>
#include "Header.h"
using namespace std;
int main()
{
	Priority_Queue <int> pq;

	pq.push(100,1);
	pq.push(200,2);
	pq.push(300,3);
	pq.push(350, 3);
	pq.push(400,4);

	cout << "removing:" << endl;

          pq.pop();
	
}