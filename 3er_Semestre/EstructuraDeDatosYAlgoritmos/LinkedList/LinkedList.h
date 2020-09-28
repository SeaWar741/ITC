//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        
        void addFirst(T datain);
        void addLast(T datain);
        
        bool deleteData(T datain);
        bool deleteAt(int indexin);
        
        T getData(int indexin); 
        
        bool updateAt(int indexin, T datain);
        bool updateData(T data, T datain);

        void print();
        bool isEmpty(){return size == 0;};
        
        int getSize(){return size;};
        int findData(T datain);

        //Sobrecarga
        Node<T> *operator[](int indexin);
        LinkedList<T> operator=(T list[]);

};

template<class T>
LinkedList<T>::LinkedList(){
    this-> head = NULL;
    this-> size = 0;
}

//AddFirst
//adds node and makes it the head, receives data
//O(1)
template<class T>
void LinkedList<T>::addFirst(T datain){
    head = new Node<T>(datain, head);
    size++;
}

//AddLast
//adds as last element of list
//O(n)
template<class T>
void LinkedList<T>::addLast(T datain){
    if(isEmpty()){
        head = new Node<T>(datain);
    } else{
        Node<T> *aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new Node<T>(datain);
    }
    size++;
}

//deleteData
//deletes the data of the node with the input data
//O(n)
template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        if(aux->data == data){
            head = aux->next;
            size--;
            cout << "DELETED"<<endl;
            return true;
        }
        Node<T> *auxF = head;
        int count = 0;
        while(count < size){
            if(aux->data == data){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout << "DELETED"<<endl;
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "NODE NOT FOUND"<<endl;
    return false;
}

//deleteAt
//deletes from input index
//O(n)
template<class T>
bool LinkedList<T>::deleteAt(int index){
    if(!isEmpty() && index <= size && index > 0){
        int count = 1;
        Node<T> *aux = head;
        if(index == count){
            head = aux->next;
            size--;
            cout <<endl<<"DELETED"<<endl;
            return true;
        }
        Node<T> *auxF = head;
        while(count <= size){
            cout << count << " ";
            if(count == index){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout <<endl<< "DELETED"<<endl;
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "NODE NOT FOUND"<<endl;
    return false;
}


//getData
//gets the data from input index
//O(n)
template<class T>
T LinkedList<T>::getData(int index){
    if(!isEmpty() && index > 0 && index <= size){
        int counter = 1;
        Node<T> *aux = head;
        while(counter <= size){
            if(counter == index){
                return aux->data;
            }
            counter++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE\n");
}


//updateAt
//updates data from input node
//O(n)
template<class T>
bool LinkedList<T>::updateAt(int index, T datain){
    if(!isEmpty() && index > 0 && index <= size){
        int count = 1;
        Node<T> *aux = head;
        while(count <= size){
            if(count == index){
                aux->data = datain;
                cout << "UPDATED"<<endl;
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE");
}



//updateData
//updates data from given data
//O(n)
template<class T>
bool LinkedList<T>::updateData(T data, T datain){
    if(!isEmpty()){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(aux->data == data){
                aux->data = datain;
                cout << "UPDATED"<<endl;
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("NOT FOUND\n");
}


//findData
//Find index by input data
//O(n)
template<class T>
int LinkedList<T>::findData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(aux->data == data){
                return count;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE");
}



//print
//displays list
//O(n)
template<class T>
void LinkedList<T>::print(){
    Node<T> *aux = head;
    if(size > 0){
        for(int i = 0; i < size; i++){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "LIST IS EMPTY";
    }
    cout << "\n";
}


//----------Overcharge---------------


//[]
//used as array index
//O(n)
template<class T>
Node<T>* LinkedList<T>::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){//verifica que no este vacio y que el indice este en el rango del size
        Node<T> *aux = head;//se crea un nodo auxiliar para almacenar head
        int counter = 1;
        while(counter <= size){
            if(counter == index){//si es igual al indice se regresa el nodo auxiliar
                return aux;
            }
            counter++;//si no se aumenta el contador y se pone el siguiente en los nodos
            aux = aux->next;
        }
    }
    throw runtime_error("OUT OF RANGE\n");
}


//=
//asigns values
//O(n)
template<class T>
LinkedList<T> LinkedList<T>::operator=(T list[]){
    if(sizeof(list) > 0){//siempre que sea mayor de 0 la lista/array
        for (int i = 0; i <= sizeof(list)/sizeof(list[0]); i++){
            this->addLast(list[i]);//se hace un add iterativo a partir del indice del array
        }
        return *this;//regresa el linkedlist copiado de la lista/array
    }
    throw runtime_error("INVALID: EMPTY LIST\n");
}

