#include <iostream>
#include "RegistryEntry.h"

struct Node  {
	RegistryEntry data;
	Node* next;
	Node* prev;
};

struct Node* GetNewNode(RegistryEntry x) {
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}


/*
template<class T>
struct Node{
    T data;//contiene un data y un apuntador como indice al siguiente nodo, conectandolos entre si
    Node<T> *next;
	Node<T> *prev;
    Node(T data);
    Node(T data,Node<T> *next);
};

//constructor for only data
template <class T>
Node<T>::Node(T data){
    this->data = data;
	newNode->prev = NULL;
    next = NULL;
}

//constructor data and next 
template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}
*/