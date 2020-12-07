//Juan Carlos Garfias Tovar, A01652138
#include "Node.h"
#include <vector>
#include <iostream>


using namespace std;

//Clase Queue
template<class T>
class Queue{
    private:
        Node<T> *head;
        Node<T> *tail;
        int index;
        int size;
    public:
        Queue();

        T dequeue();
        void enqueue(T data);
  
        T front();
        T back();
        
        int getSize() { return size; };
        void clear();

        bool isEmpty(){return size == 0;};
        int getIndex(){return index;};

        void print();
};

// constructor default
//inserta como head y tail valores null y establece size como 0
template<class T>
Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

//dequeue
//quita el primer del queue
//O(1)
template<class T>
T Queue<T>::dequeue(){
   if(!isEmpty()){// si no esta vacio agarra un nodo temporal igual a head
        Node<T> *temp = head;
        T data = temp->data;
        head = head->next;// lo mueve y borra temp
        delete temp;//reduce el size
        size--;
        return data;//regresa el data 
    }
    throw runtime_error("EMPTY\n");
}

//enqueue
//Inserta dato al queue
//O(1)
template<class T>
void Queue<T>::enqueue(T data){
    if(!isEmpty()){//si no esta vacio
        tail->next = new Node<T>(data);//pone tail como un nuevo nodo con el dato
        tail = tail->next;//le pone tail igual al next
        size++;//incrementa el size
    } else{
        head = new Node<T>(data);//si esta vacio simplemente hace add con el data
        tail = head;//cambia el tail al head
        size++;//incrementa el size
    }
}

//front
//Obtiene el valor del primer nodo agregado al Queue
//O(1)
template<class T>
T Queue<T>::front(){
    if(!isEmpty()){
        return head->data;
    }
    throw runtime_error("EMPTY\n");
}

//back
//Obtiene el valor del último nodo agregado al Queue
//O(n)
template<class T>
T Queue<T>::back(){
    if(!isEmpty()){
        return tail->data;
    }
    throw runtime_error("EMPTY\n");
}

//clear
//metodo para borrar todos los elementos, itera y elimina cada uno
//o(n)
template<class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        while(size > 0){
            if(size > 1){
                Node<T> *temp = head;
                head = head->next;
                delete temp;
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

//print
//metodo para imprimir, manera iterativa
//o(n)
template<class T>
void Queue<T>::print(){
    if(!isEmpty()){
        Node<T> *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    } else{
        cout << "EMPTY"<<endl;
    }
}
