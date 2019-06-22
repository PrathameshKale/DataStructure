#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T value;
	Node *right;
   Node *left;

	Node(T val) { value = val; right = left = nullptr; }
};

template<class T>
class Tree {
private:   
	Node<T> *root;

		  Node<T> *addNode(Node<T> *node, T val) {
			  if (!node)
				  return new Node<T>(val);
			  if (val > node->value)
				  node->right = addNode(node->right, val);
			  else
				  node->left = addNode(node->left, val);
			  return node;
		  }

		  int removeAll(Node<T> *node) {
			  if (node) {
				  removeAll(node->left);
				  removeAll(node->right);
				  cout << "deleting= " << node->value << endl;
				  delete node;
			  }
			  return 1;
		  }

		   Node<T> *removeNode(Node<T> *node, T val, bool &isDelete) {
			  if (!node)
			  {
				  isDelete = false;
				  return nullptr;
			  }
			  if (val > node->value)
				  node->right = removeNode(node->right, val, isDelete);
			  else if (val < node->value)
				  node->left = removeNode(node->left, val, isDelete);
			  else
			  {
				  if (!node->left && !node->right)
				  {
					  delete  node; isDelete = true;
					  return nullptr;
				  }

				  if (node->right && !node->left)

				  {
					  Node<T> *temp = node->right;
					  delete node;  isDelete = true;
					  return temp;
				  }

				  if (!node->right && node->left)

				  {
					  Node<T> *temp = node->left;
					  delete node;
					  isDelete = true;
					  return temp;
					  
				  }

				  Node<T> *successor = node->right;
				  while (successor->left)
				  {
					  successor = successor->left;
				  }
				  node->value = successor->value;
				  node->right = removeNode(node->right, successor->value, isDelete);
				  isDelete = true;
			  }
			  return node;
		  }

		  void printTree(Node<T> *node) {
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

		  void printInorder(Node<T> *node) {
			  if (node) {
				  printInorder(node->left);
				  cout << node->value<< endl;
				  printInorder(node->right);
			  }
		 }

public:    Tree() { root = nullptr; }

		   void add(T val) {
			   root = addNode(root, val);
		   }

		   int removeTotal() {
			   int res=removeAll(root);
			   return res;
		   }

		   bool removeone(T val) {
			   bool  isDelete;
			   root = removeNode(root, val, isDelete);
			   return isDelete;
		   }
		   void print() {
			   printTree(root);
		   }
		   void printAsending() {
			   printInorder(root);
		   }
};
