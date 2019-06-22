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
public: List() { head = tail = NULL; }
		bool add(int val) {
			Node *newNode = new Node(val);
			if (NULL == head)
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
			for (Node *current = head;current; current = current->next)
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
		bool remove(int val) {
			for (Node *current = head; current;current=current->next)
			{
				if (current->value == val) {
					if (tail == head) {
						tail = head = NULL;
						delete current;
						return true;
					}
					if (current == head) {
						head = head->next;
						delete current;
						head->prev = NULL;
						return true;
			      }
					if (current == tail) {
						tail= tail->prev;
						delete current;
						tail->next= NULL;
						return true;
					}
					current->prev->next = current->next;
					current->next->prev = current->prev;
					return true;
				}
			}
		}
};
int main() {
	int val, val1;
	List shopping;
	while (cout << "Enter value", cin >> val, val)
	{
		shopping.add(val);
	}
	//shopping.printBackward();
	shopping.printForward();
	cout << "Enter value for delete element";
	cin >> val1;
	shopping.remove(val1);
	cout << "After removing element"<<endl;
	shopping.printForward();
}