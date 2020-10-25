#pragma once 
template<class T>
struct NodeD {
    T data;
    NodeD<T> *next;
    NodeD<T> *prev;
    NodeD(T data);
    NodeD(T data, NodeD<T> *next, NodeD<T>* prev);
};

template<class T>
NodeD<T>::NodeD(T data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
NodeD<T>::NodeD(T data, NodeD<T>* next, NodeD<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}




