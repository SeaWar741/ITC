
#include <iostream>
#include "Node.h"

using namespace std;


class DLinkedList{
    private:
        struct Node* head; // global variable - pointer to head node.
    public:
        DLinkedList();

        //Funciones para insertar
        void insertAtHead(RegistryEntry x);
        void insertAtTail(RegistryEntry x);

        //Funciones para sort

        //Funciones extra
        void print();
        void reversePrint();
};


DLinkedList::DLinkedList(){
    this-> head = NULL;
}

void DLinkedList::insertAtHead(RegistryEntry x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

void DLinkedList::insertAtTail(RegistryEntry x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

void DLinkedList::print() {
	struct Node* temp = head;
	while(temp != NULL) {
        printEntry(temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void DLinkedList::reversePrint() {
	struct Node* temp = head;

	if(temp == NULL) return;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	while(temp != NULL) {
		printEntry(temp->data);
		temp = temp->prev;
	}
	printf("\n");
}