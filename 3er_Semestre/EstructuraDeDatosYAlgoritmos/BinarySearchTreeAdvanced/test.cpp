//Juan Carlos Garfias Tovar, A01652138
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};



int main() {
	Node* root = NULL;
	root = Insert(root,5); 
	root = Insert(root,10);
	root = Insert(root,3);
	root = Insert(root,4); 
	root = Insert(root,1);
	root = Insert(root,11);

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}