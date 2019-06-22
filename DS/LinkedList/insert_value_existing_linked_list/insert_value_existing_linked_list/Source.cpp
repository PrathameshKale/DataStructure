#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *next;
	Node *prev;
	Node(int val) { value = val; next = NULL; prev = NULL; }
};
class List {
	Node *head;
	Node *tail;
public: List() { head = tail = NULL; }
		bool insertAtStart(int val) {
			Node *newNode = new Node(val);
			if (head == NULL) {
				head = newNode;
			}
			else {
				tail->prev=newNode;
				head = newNode;
			}
			tail = newNode;
	  }
};
int main() {

}