#include<iostream>
using namespace std;

template<class T>
struct Node
{
	int value;
	Node *next;
	Node *prev;

	Node(int val)
	{
		value = val;
		next = prev = nullptr;
	}
};

template<class T>
class List
{
	Node<T> *head;
	Node<T> *tail;

public:	List() 
	{
		head = new Node<T>(0);
		tail = new Node<T>(0);

		head->next = tail;
		tail->prev = head;
	}

private:
	  bool insert(Node<T> *node, int val)
	{
		 
		       Node<T> * newNode = new Node<T>(val);
			   newNode->prev = node;
			   newNode->next = node->next;
			   newNode->prev->next = newNode;
			   newNode->next->prev = newNode;
			   return true;
	}

	  void printForward()
	  {
		  int cnt=0;
		  for (Node<T> *current = head->next; current!=tail; current = current->next)
		  {
			  cout << current->value << endl;
			  cnt++;
		  }
		  cout << "Total node add is: " << cnt;
     }

	  void replaceNode(int valueToReplace, int newValue , int occurance)
	  {
		  int occur = 0;
		  for (Node<T> *current = head->next; current != tail; current = current->next)
		  {
			  if (current->value == valueToReplace) {
				  occur++;
				  if(occur== occurance)
				  current->value = newValue;
			  }
		  }
	  }

	  bool removeNode(int valueToRemove)
	  {
		  for (Node<T> *current = head->next; current != tail; current = current->next)
		  {
			  if (current->value == valueToRemove)
			  {
				
				  current->prev->next = current->next;
				  current->next->prev = current->prev;
				  delete current;
				  return true;
			  }
		  } return false;
	  }

	  int removeAllNode()
	  {
		  int cnt = 0;
		  while (head->next!=tail)
		
		  {
			  head->next = head->next->next;
			  delete head->next->prev;
			  cnt++;
		  }
		  tail->prev = head;
		  return cnt;
	  }

public:
		  void addFront(int val)
		  {
			  insert(head, val);
		  }
		  void addLast(int val)
		  {
			  insert(tail->prev, val);
		  }
		  void addAfter(int valueToSearch, int valueToAdd)
		  {
			  for (Node<T> *current = head->next; current != tail; current = current->next) {
				  if (current->value == valueToSearch) {
					  insert(current, valueToAdd);
				  }
			  }
		  }
		  void addBefore(int valueToSearch, int valueToAdd)
		  {
			  for (Node<T> *current = head->next; current != tail; current = current->next) {
				  if (current->value == valueToSearch) {
					  insert(current->prev, valueToAdd);
				  }
			  }

		  }

		  void replace(int replaceToValue, int newValue, int occurance)
		  {
			  replaceNode(replaceToValue, newValue, occurance);
		  }
		  void remove(int valueToRemove)
		  {
			 bool status= removeNode(valueToRemove);
			 cout << "Is delete : " << status << endl;
		  }
		  void print()
		  {
			  printForward();
		  }

		  void removeAll() {
			 int cnt= removeAllNode();
			 cout << "total node : " << cnt << "deleted: " << endl;
		 }

		 
	  
};
