//Juan Carlos Garfias Tovar, A01652138

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        DoublyLinkedList();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };
        void setSize(int sizeIn){this->size = sizeIn;};

        Node* getData(int index);
        void addLast(string ip, int attempts);

        void clear();
        void print();
        void printReverse();

        Node* operator[](int index);
        void operator=(vector<int> list);
};

// constructor
DoublyLinkedList::DoublyLinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

//getData
//obtiene el dato del indice
//O(n)
Node* DoublyLinkedList::getData(int index){
    if(!isEmpty() && index > 0 && index <= size){
        int counter = 1;
        Node *aux = head;
        while(counter <= size){
            if(counter == index){
                return aux;
            }
            counter++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE");
}

//addLast
//inserta como ultimo elemento en la lista el input
//siendo un nodo con ip y attempts
//O(1)
void DoublyLinkedList::addLast(string ip, int attempts){
    if(!isEmpty()){
        tail->next = new Node(ip, attempts);
        tail->next->prev = tail;
        tail = tail->next;
    } else{
        head = new Node(ip, attempts);
        tail = head;
    }
    size++;
}

//clear
//borra la lista
//o(n)
void DoublyLinkedList::clear() {
    if(!isEmpty()){
        Node *aux = head;
        while (head->next != NULL) {
            Node *aux = head;
            head = aux->next;
            delete aux;
        }
        size = 0;
        tail = NULL;
        head = NULL;
    }
}

//print
//imprime la lista
//o(n)
void DoublyLinkedList::print(){
    if(!isEmpty()){
        Node *aux = head;
        while(aux != NULL){
            aux->print();
            aux = aux->next;
        }
    } else{
        cout << "LIST IS EMPTY";
    }
    cout << endl;
}

//printReverse
//imprime la lista de manera invertida
//o(n)
void DoublyLinkedList::printReverse(){
    if(!isEmpty()){
        Node *aux = tail;
        while(aux != NULL){
            aux->print();
            aux = aux->prev;
        }
    } else{
        cout << "LIST IS EMPTY";
    }
    cout << endl;
}

//sobrecarga de operador[]
//sobrecarga
//o(n)
Node* DoublyLinkedList::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node *aux = head;
        int counter = 1;
        while(counter <= size){
            if(counter == index){
                return aux;
            }
            counter++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE");
}
