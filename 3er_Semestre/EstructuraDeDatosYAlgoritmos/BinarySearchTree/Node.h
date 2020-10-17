template <class T>
struct Node {
	T data; 
	Node<T>* left;
	Node<T>* right;
};

// Function to create a new Node in heap
template <class T>
Node<T>* GetNewNode(T data) {
	Node<T> *newNode = new Node<T>();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}