#include<iostream>
using namespace std;

class queue
{
	int front, rear;
	int size;
	int *array;

public:
	queue(int s=10)
	{
		array = new int[size = s];
		front = 0;
		rear = 0;
	}

	~queue() { delete[] array; }

	void push(int val)
	{
		if ((rear == size - 1 && front == 0) && (front == rear + 1))
			throw "queue is full";
		else
			array[rear++] = val;
	}


	int pop()
	{
		if (rear == front)
			throw "queue is empty: ";
		return array[front++];
	}
};