#include "Node2.h"
#include <vector>
#include <iostream>
template <class T>

//Clase Queue
class Queue{
    private:
        Node2<T> *head;
        Node2<T> *tail;
        int index;
        int size;
    public:
        Queue();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };
        int getIndex(){return index;};

        void enqueue(T data);
        T dequeue();
        
        void getData(){return tail;};

        T front();
        T back();

        void clear();
        void print();
};

// constructor
template<class T>
Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

//Inserta al final del queue
template<class T>
void Queue<T>::enqueue(T data){
    if(!isEmpty()){
        tail->next = new Node2<T>(data);
        tail = tail->next;
        size++;
    } else{
        head = new Node2<T>(data);
        tail = head;
        size++;
    }
}

//quita el ultimo del queue
template<class T>
T Queue<T>::dequeue(){
   if(!isEmpty()){
        Node2<T> *aux = head;
        T data = aux->data;
        head = head->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("EMPTY\n");
}

//hacia el frente
template<class T>
T Queue<T>::front(){
    if(!isEmpty()){
        return head->data;
    }
    throw runtime_error("EMPTY\n");
}

//hacia atras
template<class T>
T Queue<T>::back(){
    if(!isEmpty()){
        return tail->data;
    }
    throw runtime_error("EMPTY\n");
}

//itera y borra los elementos
template<class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        while(size > 0){
            if(size > 1){
                Node2<T> *aux = head;
                head = head->next;
                delete aux;
                size--;
            } else{
                head = tail = NULL ;
                size--;
            }
        }
        
    } else{
        cout << "EMPTY\n";
    }
}

//imprime de manera iterativa
template<class T>
void Queue<T>::print(){
    if(!isEmpty()){
        Node2<T> *aux = head;
        while(aux != NULL){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "EMPTY";
    }
    cout << "\n";
}