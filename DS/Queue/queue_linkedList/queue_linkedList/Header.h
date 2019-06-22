#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *next;

	Node(int val)
	{
		value = val;
		next = nullptr;
	}
};

class queue 
{
	Node *head;
	Node *tail;

public: queue()
	{
		head = tail = nullptr;
	}

	void push(int val)
	{
		Node *node = new Node(val);
		if (head == nullptr)
			head = tail=node;
		else
			tail->next = node;
		tail = node;

	}

	void pop()
	{
		for (Node *current = head; current; current = head)
		{
			head = current->next;
			cout << "delete is: " << current->value << endl;
			delete current;

	    }
	}
	

	void print()
	{
		if (head == nullptr)
			cout << "queue is empty:" << endl;
		for (Node *current = head; current; current = current->next)
		{
				cout << current->value << endl;
		}
	}
};