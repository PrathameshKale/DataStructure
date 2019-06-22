#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *next;
	Node *prev;
	Node() {}
	Node(int val) { this->value = val; this->next = NULL; this->prev = NULL; }
};

class List {
	Node *head, *tail;
public: List() { head=tail = NULL; }
		bool add(int val) {
			Node *newNode = new Node(val);
			if (NULL==head)
			{
				head = newNode;
			}
			else {

				tail->next = newNode;
				newNode->prev = tail;
			}
			tail = newNode;
			return true;
		}
		void printForward() {
			for (Node *current =head;current; current=current->next)
			{
				cout << current->value;
			}
		}
		void printBackward() {
			for (Node *current = tail;current; current = current->prev)
			{
				cout << current->value;
			}
			
		}
};
int main() {
	int val;
	List shopping;
	while (cout<<"Enter value", cin>>val,val)
	{
		shopping.add(val);
	}
	shopping.printBackward();
	shopping.printForward();
}