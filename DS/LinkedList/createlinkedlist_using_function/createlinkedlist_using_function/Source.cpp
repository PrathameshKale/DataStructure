#include<iostream>
using namespace std;
struct  Node
{
	Node() {}
	int value;
	Node *next;
	Node(int val) { this->value = val; this->next = NULL; }
};
class List {
	Node *head, *tail;
public:List() { this->head = NULL; this->tail = NULL; }
	   void add(int val) {
		   Node *newNode = new Node(val);
		   if (NULL == head)
			   head = newNode;
		   else
		   {
			   tail->next = newNode;
		   }
		   tail = newNode;
	   }
	   void forwordprint() {
		   for (Node *current = head;current; current = current->next) {
			   cout << current->value;
		   }
		}
	  
};
int main() {
	int val;
	List shoppingList;
	while (printf("Enter value"), scanf("%d",&val), val)
	{
		shoppingList.add(val);
	}
	shoppingList.forwordprint();
	
}