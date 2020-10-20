#pragma once 
template<class T>
struct Node2 {
    T data;
    Node2<T> *next;
    Node2(T data);
    Node2(T data, Node2<T> *next);
};

template<class T>
Node2<T>::Node2(T data) {
    this->data = data;
    this->next = NULL;
}

template<class T>
Node2<T>::Node2(T data, Node2<T>* next) {
    this->data = data;
    this->next = next;
}