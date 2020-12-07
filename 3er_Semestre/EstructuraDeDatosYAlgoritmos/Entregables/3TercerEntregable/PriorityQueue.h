//Juan Carlos Garfias Tovar, A01652138
//priority max to low, balanceado completamente
//representa un nodo del arbol cuyos hijos estan en 2k y 2k+1
#include<iostream>
#include "DoublyLinkedList.h"
using namespace std;

template <class T>
class PriorityQueue{
private:
    DoublyLinkedList<T> heap;
    int size;
    void downSort(int index);
    void swap(int auxa,int auxb );
public:
    PriorityQueue();
    PriorityQueue(DoublyLinkedList<T> lista);
    bool isEmpty();
    void print();

    T remove();
};

//Constructor default
template <class T>
PriorityQueue<T>::PriorityQueue(){
    size = 0;
}

//Constructor con linked list
template <class T>
PriorityQueue<T>::PriorityQueue(DoublyLinkedList<T> lista){
    if (!lista.isEmpty()){
        heap = lista;
        size = lista.getSize();
        int index = size/2;
        downSort(index); //se hace un downsort por default

    }
    
}   

//isEmpty
//verifica si el size es igual a cero o no
template <class T>
bool PriorityQueue<T>::isEmpty(){
    return size==0; // true o false
}

//swap
//funcion para realizar intercambios en los elementos
//a partir de los indices de la lista
template <class T>
void PriorityQueue<T>::swap(int a, int b){
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

//down sort
//funcion para realizar el sort del heap
//ordena el heap
//o(n^2)
template <class T>
void PriorityQueue<T>::downSort(int index){
    while (index >= 1){ //si el indice es mayor a uno
        int pos = index; //se pone el indice como posicion
        while (pos*2 <= size){//se mientras que la posicion por dos sea menor al size
            int s1 = pos*2;
            int s2 = pos*2+1;
            int max;
            if(s2> size){ //se comparan pos
                max = s1;
            }else{ //se comparan los datos de los indices
                heap[s1].major(heap[s2]) ? max = s1: max = s2; 
            }
            if(heap[max].major(heap[pos]) ){ //se hace swap si es mayor
                swap(pos,max);
                pos = max;
            }else{
                pos=size;

            }
        }
        index--; //se reduce el indice
    }
}


//print
//funcion para realizar print
//imprime la lista
template<class T>
void PriorityQueue<T>::print(){
    heap.print();
}


//remove
//elimina el elemento incial de la lista
template<class T>
T PriorityQueue<T>::remove(){
   if(!isEmpty()){
       T aux = heap[1];
       swap(1,size);
       heap.deleteAt(size);//elimina el indice incial
       size--;//reduce el size
       downSort(1);//aplica downsort
       return aux;
   }else{
       throw runtime_error("HEAP IS EMPTY");
   }
}
