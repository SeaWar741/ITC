#include <iostream>
#include "Node.h"

using namespace std;

class DLinkedList{
private:
	struct Node* head; //pointer to head node.
public:
	DLinkedList(/* args */);

	
	//Inserts a Node at head of doubly linked list
	void InsertAtHead(int x);

	//Inserts a Node at tail of Doubly linked list
	void InsertAtTail(int x);

	//Prints all the elements in linked list in forward traversal order
	void Print();

	//Prints all elements in linked list in reverse traversal order. 
	void ReversePrint();
};

DLinkedList::DLinkedList(){

}

void DLinkedList::InsertAtHead(int x) {
	struct Node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

void DLinkedList::InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

void DLinkedList::Print() {
	struct Node* temp = head;
	//printf("Forward: ");
	while(temp != NULL) {
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	printf("\n");
}

void DLinkedList::ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}


