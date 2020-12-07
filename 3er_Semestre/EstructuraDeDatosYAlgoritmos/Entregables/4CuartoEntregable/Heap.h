//Juan Carlos Garfias Tovar, A01652138
#include <vector>
#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

class Heap{
    private:
        DoublyLinkedList doblyList;
        int size;
    public:
        Heap();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };

        void insert(string ip, int failedAttempts);
        void remove();
        
        void swap(int ip1, int ip2);
        void upHeap(int index);
        void downHeap(int index);

        void print();

        Node *operator[](int index);
        void operator=(DoublyLinkedList list);
        Node *getNodeAt(int index);
        Node *getNode(string ip, int &index);
};

//constructor default
Heap::Heap(){
    size = 0;
}

//insert
//hace un insert de un nodo con ip y failedattemps
//O(1)
void Heap::insert(string ip, int failedAttempts){
    if(isEmpty()){
        doblyList.addLast(ip, failedAttempts);
        size++;
    } else{
        int index = 1;
        Node *aux = getNode(ip, index);
        if(aux !=  NULL){
            aux->failedAttempts++;
            upHeap(index);
        } else{
            doblyList.addLast(ip, failedAttempts);
            size++;
            upHeap(size);
        }
       
    }
    doblyList.setSize(size);
}

//remove
//elimina del heap
//o(1)
void Heap::remove(){
    if(isEmpty()){
        throw runtime_error("EMPTY LIST");
    }
    if(size == 1){
        doblyList.clear();
        size--;
    } else{
        doblyList[1]->ip = doblyList[size]->ip;
        doblyList[1]->failedAttempts = doblyList[size]->failedAttempts;
        size--;
        doblyList[size]->next = NULL;
        downHeap(1);
    }
    doblyList.setSize(size);
}

//swap
//intercambio de ips
//o(1)
void Heap::swap(int ip1, int ip2){
    Node *aux = doblyList[ip1];
    Node *aux2 = doblyList[ip2];
    string ipTemp = aux->ip;
    int failedAttemptsTemp = aux->failedAttempts;
    aux->ip = aux2->ip;
    aux->failedAttempts = aux2->failedAttempts;
    aux2->ip = ipTemp;
    aux2->failedAttempts = failedAttemptsTemp;
}

//upHeap
//realiza un swap para mover elementos hacia
//arriba
//O(1)
void Heap::upHeap(int ip1){
    if(ip1 == 1){
        return;
    }
    int ip2 = ip1 / 2;
    Node *aux = doblyList[ip1];
    Node *aux2 = doblyList[ip2];
    if(aux->failedAttempts > aux2->failedAttempts){
        swap(ip1, ip2);
    }
    upHeap(ip2);
}


//downHeap
//realiza un swap para mover elementos hacia
//abajo
//O(1)
void Heap::downHeap(int ip1){
    if(ip1 * 2 > size){
        return;
    }
    int ip2 = ip1 * 2;
    Node *aux = doblyList[ip1];
    Node *aux2 = doblyList[ip2];
    if((ip1 * 2 + 1) > size){
        if(aux2->failedAttempts > aux->failedAttempts){
            swap(ip1, ip2);
        }
        return;
    }
    int i3 = ip2 + 1;
    Node *aux3 = doblyList[i3];
    if(aux2->failedAttempts > aux3->failedAttempts){
        if(aux2->failedAttempts > aux->failedAttempts){
            swap(ip1, ip2);
        }
        downHeap(ip2);
    } else{
        if(aux3->failedAttempts > aux->failedAttempts){
            swap(ip1, i3);
        }
        downHeap(i3);
    }
}


//getNode
//obtiene el node
//O(n)
Node *Heap::getNode(string ip, int &index){
    if(!isEmpty()){
        Node *aux = doblyList[1];
        while(aux != NULL){
            if(aux->ip == ip){
                return aux;
            }
            index++;
            aux = aux->next;
        }
    }
    return NULL;
}

//print
//imprime heap
//O(n)
void Heap::print(){
    if(isEmpty()){
        throw runtime_error("EMPTY LIST");
    }
    Node *aux = doblyList[1];
    while(aux != NULL){
        aux->print();
        aux = aux->next;
    }
    cout << "\n";
}

//[]
//sobrecarga de operador []
//O(n)
Node* Heap::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node *aux = doblyList[1];
        int count = 1;
        while(count <= size){
            if(count == index){
                return aux;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE");
}