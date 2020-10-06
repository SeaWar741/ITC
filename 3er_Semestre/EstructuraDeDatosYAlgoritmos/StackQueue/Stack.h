#include <iostream>
#include <vector>
#include "Node.h"

template <class T>
class Stack{
    private:
        Node<T> *top;
        int size;
    public:
        Stack();

        bool isEmpty()
        int getSize(){return size;};

        void push(T data);
        T pop();
        T getTop();

        void clear();
        void print();
        void deleteTop();

};

template<class T>
Stack<T>::Stack(){
    top = NULL;
    size = 0;
}

template<class T>
void Stack<T>::push(T data){
    if(!isEmpty()){
        top = new Node<T>(data, top);
        size++;
    } else{
        top = new Node<T>(data);
        size++;
    }
}

template<class T>
T Stack<T>::pop(){
    if(!isEmpty()){
        Node<T> *aux = top;
        T data = aux->data;
        top = top->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("EMPTY STACK\n");
}

template<class T>
T Stack<T>::getTop(){
    if(!isEmpty()){
        return top->data;
    }
    throw runtime_error("Error: the stack is empty..\n");
}

template<class T>
void Stack<T>::deleteTop(){
    if(size > 1){
        Node<T> *aux = top;
        top = top->next;
        delete aux;
        size--;
    } else if(size == 1){
        top = NULL;
        size--;
    }
}

template<class T>
void Stack<T>::clear(){
    if(!isEmpty()){
        Node<T> *aux = top;
        while(aux != NULL){
            deleteTop();
            aux = aux->next;
        }
        deleteTop();
        cout << "Succes: elements deleted..\n";
    } else{
        cout << "There are no elements to delete..\n";
    }
}


template<class T>
void Stack<T>::print(){
    if(!isEmpty()){
        Node<T> *aux = top;
        while(aux != NULL){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The stack is empty..";
    }
    cout << "\n";
}