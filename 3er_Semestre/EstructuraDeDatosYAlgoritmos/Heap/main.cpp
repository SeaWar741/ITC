//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "PriorityQueue.h"
#include "DoublyLinkedList.h"
using namespace std;

//HeapSort
//se ordena a partir de remover el top de la lista y ahace add
template<class T>
void HeapSort(DoublyLinkedList<T>& list, string order ){
    PriorityQueue<T> heapAux(list);
    list.clear();
    while (!heapAux.isEmpty()){
        if(order == "ascending"){
            list.addFirst(heapAux.remove());//se insertan al inicios
        }
        if(order == "descending"){
            list.addLast(heapAux.remove());//se insertan al final
        }
    }
    
}

//menu
//imprime el menu
void menu(){
    cout<<"-----------------------------"<<endl;
    cout<<"1)Ingresar valores"<<endl;
    cout<<"2)Orden ascendente"<<endl;
    cout<<"3)Orden descendente"<<endl;
    cout<<"4)Salir"<<endl;
    cout<<"-----------------------------"<<endl;
}


int main(){
    DoublyLinkedList<int> lista;
    int selection,value, amount;
    bool continues = true;

    cout<<endl<<"Bienvenido a PriorityQueue/Heap tester!"<<endl<<endl;
    cout<<"Ingresar cantidad de datos a ingresar >";cin>>amount;
    cout<<endl;
    for (int i = 0; i < amount; i++){//se insertan x elementos
        cout<<">";cin>>value;
        lista.addLast(value);
    }
    cout<<endl;
    
    while (continues){//mientras que sea verdadero
        menu();
        cout<<endl;
        cout<<"Ingresar seleccion >";cin>>selection; //seleccion user menu
        cout<<"-----------------------------"<<endl;
        switch (selection){
            case 1:
                cout<<"Ingresar cantidad de datos a ingresar >";cin>>amount;
                cout<<endl;
                for (int i = 0; i < amount; i++){//ingresar mas valores a la lista
                    cout<<">";cin>>value;
                    lista.addLast(value);
                }
                break;
            case 2:
                HeapSort(lista,"ascending"); //orden ascending
                lista.print();
                break;
            case 3:
                HeapSort(lista,"descending"); //orden descending
                lista.print();
                break;
            case 4:
                continues = false; //se rompe el loop
                break;
            default:
                cout<<"Invalido!"<<endl;
                break;
        }
        cout<<endl;
    }
    cout<<"Gracias por usar PriorityQueue/Heap tester!"<<endl;

    
/*
    lista = {8,5,17,19,21,28};

    lista.print();

    
    heap.print();
    for (int i = 0; i < 7; i++){
        try{
            cout<<heap.remove()<<endl;
        }catch(runtime_error& e){
            cout<<e.what()<<endl;
        }
    
    }
    cout<<endl;

    //Heap Sort
    HeapSort(lista,"ascending");
    lista.print();
    HeapSort(lista,"descending");
    lista.print();
*/

    return 0;
}
