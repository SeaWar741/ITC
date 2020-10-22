//Juan Carlos Garfias Tovar, A01652138
//priority max to low, balanceado completamente
//representa un nodo del arbol cuyos hijos estan en 2k y 2k+1
#include<iostream>
#include "DoublyLinkedList.h"

template <class T>
class PriorityQueue{
private:
    DoublyLinkedList<T> heap;
    int size;
public:
    PriorityQueue(/* args */);
    PriorityQueue(DoublyLinkedList<T> lista);
};

//Constructor default
template <class T>
PriorityQueue<T>::PriorityQueue(){

}

//Constructor con linked list
template <class T>
PriorityQueue<T>::PriorityQueue(DoublyLinkedList<T> lista){

}

