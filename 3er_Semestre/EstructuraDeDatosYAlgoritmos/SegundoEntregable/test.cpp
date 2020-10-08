/* Doubly Linked List implementation */
#include<iostream>

using namespace std;

template <class T>
struct Node{
	T data;
	Node* next;//siguiente
	Node* prev;//anterior
};

//clase DLinkedList
template <class T>
class DLinkedList{
private:
	Node<T>* head;//hasta adelante
	Node<T>* tail;//hasta atras
	Node<T>* n;
public:
	DLinkedList();
	print(Node<T>* head);
};

template <class T>
DLinkedList::DLinkedList(){
	
}


template <class T>
void print(Node<T>* head){
	Node<T>* temp = head; //temporal node
	while (temp != NULL){
		cout<<"("<<temp->prev<<")"<<temp->data<<"("<<temp->next<<") ";
		temp = temp ->next; //apunta al siguiente nodo
	}
	cout<<endl;
}

int main() {

	

	//primer nodo
	n = new Node<int>;
	n->data = 1;
	n->prev = NULL;
	head = n;
	tail = n;
	tail->next = NULL;	

	print(head);

	//segundo nodo
	n = new Node<int>;
	n->data = 2;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;

	print(head);

	//tercer nodo
	n = new Node<int>;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;

	print(head);

	//cuarto nodo
	n = new Node<int>;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;

	//ultimo nodo poner null
	tail->next = NULL;
	
	print(head);

	return 0;
}