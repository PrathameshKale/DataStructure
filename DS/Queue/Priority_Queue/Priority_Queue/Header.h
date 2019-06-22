#include<iostream>
#include<string.h>
using namespace std;

template <class T>
struct Node
{
	T value;
	int priority;
	Node<T> *next;

	Node (T val, int prio)
	{
		value = val;
		priority = prio;
		next = nullptr;
	}
};

template <class T>
class Priority_Queue
{
	Node<T> *head;
	Node<T>*tail;

public: 
	Priority_Queue()
	{
		head = tail = nullptr;

	}

   bool push(T val, int prio)
	{
		Node<T> *newNode = new Node<T>(val, prio);
		if (head == nullptr)
		{ 
			head = tail = newNode;
			return true;
		}
		Node<T> *temp = head;
		for (Node<T> *current = head; current ; current=current->next)
		{
			if (prio < current->priority)
			{
				if (current == head)
				{
					newNode->next = head;
					head = newNode;
					return true;
				}
				else
				{
					temp->next = newNode;
					newNode->next = current;
					return true;
				}
				temp = current;
			}
			tail->next = newNode;
			tail = newNode;
			return true;
		}
    }

	void pop()
	{
		for (Node<T> *current = head; current ; current=current->next)
		{
			cout << current->value << endl;;
		}
	}
};