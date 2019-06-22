#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *left;
	Node *right;
	Node(int val) { value = val;   left = right = nullptr; }
};
Node *addNode(Node *node, int val) {
	if (node == nullptr) // check node is null
		return new Node(val);
	if (val > node->value)   //check value
		node->right = addNode(node->right, val);
	else
		node->left = addNode(node->left, val);

	return node;
}
// it print all nodes in using In-Order traversing, its used for sort the elements
void print_Inorder(Node *node) {
	if (node) {
		print_Inorder(node->left);
		cout << node->value << endl;
		print_Inorder(node->right);
	}
}
// it print all nodes in using Pre-Order traversing, its used for saving and crerating tree again
void print_Preorder(Node *node) {
	if (node) {
		cout << node->value << endl;
		print_Preorder(node->left);
		print_Preorder(node->right);
	}
}
//Post Order Used for deleting the all  nodes
void RemoveAll_Post_Order(Node *node) {
	if (node) {
		RemoveAll_Post_Order(node->left);
		RemoveAll_Post_Order(node->right);
		cout <<"Deleting = " << node->value << endl;
		delete node;

	}
}
int main() {
	int val;
	Node *root = nullptr;
	while (cout << "Enter the value: ", cin >> val, val)
	{
		root = addNode(root, val);
	}
	print_Inorder(root);
	print_Preorder(root);
	RemoveAll_Post_Order(root);
}