#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *right;
	Node *left;

	Node(int val) { value = val; right = left = nullptr; }
};

class Tree {
private:  Node *root;

		  Node * addNode(Node *node, int val) {
			  if (!node)
				  return new Node(val);
			  if (val > node->value)
				  node->right = addNode(node->right, val);
			  else
				  node->left = addNode(node->left, val);
			       return node;
		      }

		  void removeAll(Node *node) {
			  if (node) {
				  removeAll(node->left);
				  removeAll(node->right);
				  cout << "deleting= " << node->value << endl;
			  }
		  }

		  Node *removeNode(Node *node, int val) {
			  if (!node)
				  return nullptr;
			  if (val > node->value)
				  node->right = removeNode(node->right, val);
			  else if (val < node->value)
				  node->left = removeNode(node->left, val);
			  else
			  {
				  if (!node->left && !node->right)
				  {
					  delete  node;
					  return nullptr;
				  }

				  if (node->right && !node->left)

				  {
					  Node *temp = node->right;
					  delete node;
					  return temp;
				  }

				  if (!node->right && node->left)

				  {
					  Node *temp = node->left;
					  delete node;
					  return temp;
				  }

				  Node *successor = node->right;
				  while (successor->left)
				  {
					  successor = successor->left;
				  }
				  node->value = successor->value;
				  node->right = removeNode(node->right, successor->value);
			  }
			  return node;
		  }
          
		  void printTree(Node *node) {
			  static int level = 0;
			  int i;
			  if (node) {
				  level++;
				  printTree(node->right);
				  for (i = 0; i < level; i++)
					  cout << " ";
				  cout << node->value << endl;
				  printTree(node->left);
				  level--;
			  }
		 }

public:    Tree() { root = nullptr; }
	    
	   void add(int val) {
	                 root = addNode(root, val);
                } 

		   void removeTotal() {
			   removeAll(root);
		        }

		   void removeone(int val) {
			   root = removeNode(root, val);
		        }
		   void print() {
			   printTree(root);
		   }
};
int main() {
	int val;
	Tree t;
	while (cout<<"Enter the value : ", cin>>val, val)
	{
		t.add(val);
	}
	t.print();
	while (cout << "Enter the value for delete : ", cin >> val, val)
	{
		t.removeone(val);
		t.print();
	}
}