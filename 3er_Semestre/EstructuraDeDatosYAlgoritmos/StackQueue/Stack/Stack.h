#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

//clase Stack
//estructura de datos lineal
template <class T>
class Stack{
    private:
        Node<T> *top;//apuntador
        int size;
    public:
        Stack();

        bool isEmpty();
        int getSize(){return size;};

        T pop();
        void push(T data);
        T getTop();
        
        void deleteTop();
        void clear();
        void print();
};

//constructor default
//inicializa el top en nullo y size en cero
template<class T>
Stack<T>::Stack(){
    top = NULL;
    size = 0;
}

//isEmpty
//verifica si el stack esta vacio
//O(1)
template<class T>
bool Stack<T>::isEmpty(){
    if(size==0){
        return true;//si esta de size 0 regresa true
    }
    else{
        return false;
    }
}

//pop
//metodo para obtener el elemento del final
//regresa el elemento o un error de stack vacio
//O(1)
template<class T>
T Stack<T>::pop(){
    if(!isEmpty()){
        Node<T> *temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
    throw runtime_error("EMPTY STACK\n");
}

//push
//metodo para hacer add al stack de elementos
//busca el nodo final y lo mueve para insertar uno al final 
//O(1)
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

//getTop
//metodo para regresar el elemento final del stack
//si no lo encuentra lanza error
//O(1)
template<class T>
T Stack<T>::getTop(){
    if(!isEmpty()){
        return top->data;
    }
    throw runtime_error("EMPTY STACK\n");
}

//deleteTop
//metodo para eliminar el elemento final
//busca el elemento final y cambia el apuntador al previo
//O(1)
template<class T>
void Stack<T>::deleteTop(){
    if(size > 1){
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        size--;
    } else if(size == 1){
        top = NULL;
        size--;
    }
}

//clear
//se encarga de eliminar todos los elementos del stack
//regresa empty stack si ya no hay elementos
//O(n)
template<class T>
void Stack<T>::clear(){
    if(!isEmpty()){
        for (int i = size; i > 0; i--){
            deleteTop();
        }
        
        cout << "DELETED STACK\n";
    } else{
        cout << "EMPTY STACK\n";
    }
}

//print
//se encarga de imprimir el stack a partir de los apuntadores
//itera sobre el stack o regresa empty
//o(n)
template<class T>
void Stack<T>::print(){
    if(!isEmpty()){
        Node<T> *temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    } else{
        cout << "EMPTY";
    }
    cout << endl;
}