struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

//Creates a new Node and returns pointer to it. 
struct Node* getNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}