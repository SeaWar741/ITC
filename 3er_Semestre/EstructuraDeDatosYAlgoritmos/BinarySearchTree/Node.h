
template <class T>
struct Node{
    T data;
    Node *left;
    Node *right;
};

template <class T>
Node<T> *newNode(T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

