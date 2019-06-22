#include<iostream>
#include "BST.h"
using namespace std;
int main() {
	int val;
	Tree<int> t;
	while (cout << "Enter the value : ", cin >> val, val)
	{
		t.add(val);
	}
	t.print();
	/* while (cout << "Enter the value for delete : ", cin >> val, val)
	{
		if (!t.removeone(val))
			cout << "Not delete the" << val << " Node "<<endl;
		t.print();
	}    */
	//cout << t.removeTotal()<<endl;
	cout << "Print asending order:" << endl;
	t.printAsending();
}