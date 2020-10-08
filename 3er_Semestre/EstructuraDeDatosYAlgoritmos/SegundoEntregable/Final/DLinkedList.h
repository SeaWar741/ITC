
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class DLinkedList{
    private:
        struct Node* head; // global variable - pointer to head node.
    public:
        DLinkedList();

        //Funciones para insertar
        void insertAtHead(T x);
        void insertAtTail(T x);

        //Funciones para sort

        //Funciones extra
        void print();
        void reversePrint();

};

template <class T>
DLinkedList<T>::DLinkedList(){
    this-> head = NULL;
}


template <class T>
void DLinkedList<T>::insertAtHead(T x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

template <class T>
void DLinkedList<T>::insertAtTail(T x) {
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


template <class T>
void DLinkedList<T>::print() {
	struct Node* temp = head;
	while(temp != NULL) {
        printEntry(temp->data);
		temp = temp->next;
	}
	printf("\n");
}

template <class T>
void DLinkedList<T>::reversePrint() {
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