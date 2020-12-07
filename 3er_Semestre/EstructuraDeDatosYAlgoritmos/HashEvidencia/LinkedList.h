//Juan Carlos Garfias Tovar, A01652138

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
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

        void insertAt(int indexin, T datain);
        void clear();
        void sortMerge(vector<T>& vectIn ,int left,int middle,int right);
        void sortMerging(vector<T> & vectin, int left, int right);
        void sort();
        void duplicate();
        void removeDuplicates();
        void reverse();


        //Sobrecarga
        Node<T> *operator[](int indexin);
        void operator=(initializer_list<T> list);

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
    if(isEmpty()){//si esta vacio crea un head node a partir del data in
        head = new Node<T>(datain);
    } else{//si no itera hasta encontrar el ultimo elemento e insertarlo mientras que next no sea null
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
    if(!isEmpty()){//mientras que no este vacio
        Node<T> *aux = head;
        if(aux->data == data){//va buscando hasta encontrar el mismo data
            head = aux->next;//cambia el next y reduce de size
            size--;
            cout << "DELETED"<<endl;
            return true;
        }
        Node<T> *auxF = head;
        int count = 0;
        while(count < size){ //itera hasta encontrarlo y hace que el aux sea el next para mover los elementos hasta encontrar el data
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
        if(index == count){//se encarga de buscar en el rango hasta encontrar el indice adecuado y hacer delete
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
    if(!isEmpty() && index > 0 && index <= size){//itera hasta encontrar el nodo adecuado
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
    if(!isEmpty() && index > 0 && index <= size){//busca en el nodo y reemplaza el data por data in
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
bool LinkedList<T>::updateData(T data, T datain){//se mueve hasta encontrar el nodo con el data igual al input y reemplaza
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
int LinkedList<T>::findData(T data){//busca de manera iterativa el data comparando data de nodos
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
        for(int i = 0; i < size; i++){//imprime de manera iterativa
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "LIST IS EMPTY";
    }
    cout << "\n";
}

//--------------Actividad 2-----------------

//insert at
//inserts data by given index
//O(n)
template<class T>
void LinkedList<T>::insertAt(int index, T data){
    if(!isEmpty() && index >= 1 && index <= size){
        if(index == 1){
            addFirst(data);
        } else {
            int counter = 1;
            Node<T> *aux = head;
            Node<T> *previous = head;
            while(aux != NULL){
                if(counter == index){
                    previous->next = new Node<T>(data,aux);
                    size++;
                }
                previous = aux;
                aux = aux->next;                
                counter++;
            }
        }
    } else{
        throw runtime_error("OUT OF RANGE\n");
    }
}


//clear
//deltes data structure
//O(n)
template<class T>
void LinkedList<T>::clear(){
    while(size>0){
        deleteAt(size);
        size--;
    }
    cout<<"CLEARED"<<endl;
}


//sortMerge
//uses sorting algorithm to merge two vectors
//O(n^2)
template<class T>
void LinkedList<T>::sortMerge(vector<T> &vectIn ,int left,int middle,int right){
    vector<T> v1,v2;//vectores izquierda y derecha
    int i=0,j=0,counter =left;
    for(int count = left; count <= middle; count++){
        v1.push_back(vectIn[count]);
    }
    for(int count2 = middle+1; count2 <= right; count2++){
        v2.push_back(vectIn[count2]);
    }
    while(i < (middle-left+1) && j < (right-middle)){
        if(v1[i] > v2[j]){
            vectIn[counter] = v2[j];
            j++;
        } else{
            vectIn[counter] = v1[i];
            i++;
        }
        counter++;
    }
    while(i < (middle - left + 1)){
        vectIn[counter] = v1[i];
        counter++;
        i++;
    }

    while(j < (right-middle)){
        vectIn[counter] = v2[j];
        counter++;
        j++;
    }
}


//sortMerging
//uses sorting algorithm to sort linked list, divides by two and joins them 
//O(n^2)
template<class T>
void LinkedList<T>::sortMerging(vector<T> & vectin, int left, int right){
    if(!isEmpty()){
        if(left < right){
            int middle = left + (right-left) / 2;
            sortMerging(vectin, left, middle);
            sortMerging(vectin, middle + 1, right);
            sortMerge(vectin, left, middle, right);
        }
    } else{
        throw runtime_error("LIST IS EMPTY\n");
    }
}


//sort
//list to vector and orders it 
//O(n^2)
template<class T>
void LinkedList<T>::sort(){
    if(!isEmpty()){
        vector<T> temp;
        Node<T> *aux = head;
        while(aux != NULL){
            temp.push_back(aux->data);
            aux = aux->next;
        }
        sortMerging(temp, 0, size-1);//sorts the list and iterates over it to update values
        for(int i = 1; i <= temp.size(); i++){
            updateAt(i, temp[i-1]);
        }
    }
}


//duplicate
//duplicates consecutively items in list 
//O(n)
template<class T>
void LinkedList<T>::duplicate(){
    //int ogSize = size;
    if(!isEmpty()){
        Node<T> *aux = head;
        int counter = 2;
        while(aux!= NULL ){
            //cout<<counter<<endl;
            
            if(counter>size){
                addLast(aux->data);
            }
            else{
                //cout<<"hola"<<endl;
                insertAt(counter, aux->data);
            }
            aux = aux->next->next;
            counter += 2;
        }
    } else{
        throw runtime_error("EMPTY LIST\n");
    }
}


//removeDuplicates
//removes duplicates in the list
//O(n^2)
template<class T>
void LinkedList<T>::removeDuplicates(){
    if(!isEmpty()){
        Node<T> *aux = head;
        vector<T> temp;
        while (aux!=NULL){
            bool continues = true;
            for(T i : temp){//iterates over data in list
                if(aux->data == i){
                    continues = false;
                }
            }
            if(continues){
                temp.push_back(aux->data);
            } else{
                deleteData(aux->data);
            }
            aux = aux->next;
        }
        cout<<"DUPLICATES DELETED"<<endl;
        
    }
    else{
      throw runtime_error("EMPTY LIST\n");
    }
}


//reverse
//reverse the list
//O(n^2)
template<class T>
void LinkedList<T>::reverse(){
    if(!isEmpty()){
        vector<T> temp;
        Node<T> *aux = head;
        while(aux != NULL){
            temp.push_back(aux->data);
            aux = aux->next;
        }
        clear();//vacia la lista y la vuelve a llenar con los valores del vector
        for(T i : temp){//copies from vector
            addFirst(i);
        }
    } else{
        throw runtime_error("EMPTY LIST\n");
    }
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
void LinkedList<T>::operator=(initializer_list<T> list){
    if(isEmpty()){
        for(T i : list){
            addLast(i);
        }
    }
    else{
        throw runtime_error("ERROR: NOT EMPTY");
    }
}

//=
//asigns values
//O(n)
/*
template<class T>
void LinkedList<T>::operator=(initializer_list<T> list){
    if(isEmpty()){
        for(T i: list){
            addLast(i);
        }else{
            throw runtime_error("ERROR: NOT EMPTY");
        }
    }
}
*/