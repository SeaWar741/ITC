#include <iostream>
#include "RegistryEntry.h"

struct Node  {
	RegistryEntry data;
	struct Node* next;
	struct Node* prev;
};

struct Node* GetNewNode(RegistryEntry x) {
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}