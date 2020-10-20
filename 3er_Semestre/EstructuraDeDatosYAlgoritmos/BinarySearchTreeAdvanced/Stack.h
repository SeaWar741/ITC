#ifndef Stack_h
#define Stack_h

#include "Node2.h"

template<class T>
class Stack{
private:
    Node2<T>* top;
    int size;
public:
    Stack();
    void push(T Data);
    T pop();
    T getTop();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
Stack<T>::Stack() {
    top = NULL;
    size = 0;
}

template<class T>
void Stack<T>::push(T data) {
    top = new Node2<T>(data,top);
    size++;
}

template<class T>
T Stack<T>::pop() {
    T data;
    if (!isEmpty()) {
        Node2<T>* aux = top;
        data = aux->data;
        top = aux->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("The Stack is empty");
}

template<class T>
T Stack<T>::getTop() {
    if (!isEmpty()) {
        return top->data;
    }
    throw runtime_error("The Stack is empty");
}

template<class T>
int Stack<T>::getSize() {
    return size;
}

template<class T>
void Stack<T>::clear() {
    while (top != NULL) {
        Node2<T>* aux = top;
        top = aux->next;
        delete aux;
    }
    size = 0;
}

template<class T>
void Stack<T>::print() {
    Node2<T>* aux = top;
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
}
#endif