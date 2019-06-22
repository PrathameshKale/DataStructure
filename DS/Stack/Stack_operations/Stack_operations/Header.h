#include<iostream>
using namespace std;

template<class T>
class stack 
{
	T *array;
	int size;
	int top;

public:	
	stack(int s)
	{
	   size = s;
	   if ((array = new T[size]) == nullptr)
		   throw "out of memory: ";
	   top = -1;
	}
   stack(){delete [] array }

   void push(int val)
   {
	   if (top == size - 1)
		   throw "stack overflow";
	   array[++top] = val;
   }

   T pop()
   {
	   if (top == -1)
		   throw "stack underflow";
	   return array[top--];
   }

   T peek()
   {
	   if (top == -1)
		   throw "stack underflow";
	   return array[top];
   }

};
