#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node *right;
	Node *left;
	Node(int val) { value = val;   right = left = NULL; }
};
Node *addNode(Node *node, int val) {
	if (node == nullptr)
		return new Node(val);
	if (val > node->value)
		node->right = addNode(node->right, val);
	else
		node->left = addNode(node->left, val);
	return node;
 }
/*void printNode(Node *node) {
	if (node) {
		printNode(node->left);
		cout << node->value << endl;
		printNode(node->right);
	}
}*/

void printAsTree(Node *node) {
	static int level = 0;
	int i;
	if (node) {
		level++;
		printAsTree(node->right);
		for (i = 0; i < level; i++)
			cout << " ";
		cout << node->value << endl;
		printAsTree(node->left);
		level--;
	}
}

Node *removeNode(Node *node, int val) {
	if (node == nullptr)
		return nullptr;
	else if (val > node->value)
		node->right = removeNode(node->right, val);
	else if (val < node->value)
		node->left = removeNode(node->left, val);
	else{
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			return nullptr;
		}
	if (node->left == nullptr && node->right != nullptr) {
		Node *temp = node->right;
		delete node;
		return temp;
	}
	if (node->left != nullptr && node->right == nullptr) {
		Node *temp = node->left;
		delete node;
		return temp;
	}
	Node *sucessor = node->right;
	while (sucessor->left!=nullptr)
	{
		sucessor = sucessor->left;
	}
	node->value = sucessor->value;
	node->right= removeNode(node->right, sucessor->value);
	
}
	return node;
}
int main() {
	int val;
	Node *root=nullptr;
	while (cout << "Enter the value: ", cin >> val, val) {
		root = addNode(root, val);
	}
	printAsTree(root);
	while (
		cout << "Enter value for deleting: ",
		cin >> val,
		val)
	{
		root = removeNode(root, val);
		cout << "After deleting: "<<endl;
		printAsTree(root);
	}
}