#include "Node.h"

template <class T>
class BinarySearchTree{
    private:
        Node<T> *root;
        int childs;
        int height;
        
    public:
        BinarySearchTree();

        void insert(T data);
        void delete(T data);

        print();
        bool find(T data);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

template <class T>
void BinarySearchTree<T>::insert(T data){
    if(root == NULL) { // if empty
		root = newNode(data);
	}
	else if(data <= root->data) {//if data is lesser than root insert to the left
		root->left = insert(data);
	}
	else {//if data is greater than root insert to the right
		root->right = insert(data);
	}
}

template <class T>
bool BinarySearchTree<T>::Search(int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(data);
	}
	else {
		return Search(data);
	}
}


