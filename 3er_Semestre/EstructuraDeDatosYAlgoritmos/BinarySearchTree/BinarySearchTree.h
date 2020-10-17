#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class BinarySearchTree{
    private:
        Node<T> *root;
        int childs = 0;//por definir
        int height;//por definir
        
    public:
        BinarySearchTree();

        Node<T>* FindMin();
		struct Node<T>* Delete(T data);
		void Inorder();

		Node<T>* Insert(char data);

};

//Test
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}

//Function to find minimum in a tree. 
template <class T>
Node<T>* BinarySearchTree<T>::FindMin(){
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
template <class T>
struct Node<T>* BinarySearchTree<T>::Delete(T data) {
	if(root == NULL){
		return root;
	} 
	else if(data < root->data){
		root->left = Delete(data);
	}
	else if (data > root->data){
		root->right = Delete(data);
	}
	// element is found
	else{
		// Case 1:  has no child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: has one child
		else if(root->left == NULL) {
			struct Node<T> *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node<T> *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: has two or more children
		else { 
			struct Node<T> *temp = FindMin();
			root->data = temp->data;
			root->right = Delete(temp->data);
		}
	}
	return root;
}
 
//Function to visit nodes in Inorder
template <class T>
void BinarySearchTree<T>::Inorder() {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 

// Function to Insert Node in a Binary Search Tree
template <class T>
Node<T>* BinarySearchTree<T>::Insert(char data){
	if(root == NULL) {
		root = new Node<T>();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(data);
	else 
		root->right = Insert(data);
	return root;
}