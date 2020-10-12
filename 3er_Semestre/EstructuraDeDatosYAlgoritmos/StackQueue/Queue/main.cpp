//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "Queue.h"
using namespace std;

//menu
//funcion para mostrar las opciones de metodos de queue
void menu(){
    cout<<"=----------------------------="<<endl;
    cout<<"1) dequeue"<<endl;
    cout<<"2) enqueue"<<endl;
    cout<<"3) front"<<endl;
    cout<<"4) back"<<endl;
    cout<<"5) getSize"<<endl;
    cout<<"6) clear"<<endl;
    cout<<"7) print"<<endl;
    cout<<"8) exit"<<endl;
    cout<<"=----------------------------="<<endl;
}

//list
//funcion para imprimir la lista con delimitadores
template <class T>
void print(Queue<T> list){
    cout<<"=----------------------------="<<endl;
    list.print();
    cout<<"=----------------------------="<<endl;
}


int main(){
    Queue<int> lista;
    int values,selection,insertion;
    bool continues = true;
    
    cout<<"Bienenido a Enqueue tester!"<<endl;
    cout<<endl<<"Ingresar cantidad de elementos iniciales: >";cin>>values;

    for (int i = 0; i < values; i++){
        lista.enqueue(i);
    }

    print(lista);

    while (continues){//mientras que continues sea verdadero

        menu();
        cout<<endl<<"Ingresar seleccion: >";cin>>selection;

        switch (selection){
            case 1:
                cout<<"Dequeue: "<<lista.dequeue()<<endl;
                break;
            case 2:
                cout<<"Ingresar valor a insertar: >";cin>>insertion;
                lista.enqueue(insertion);
                break;
            case 3:
                cout<<"Valor al frente: "<<lista.front()<<endl;
                break;
            case 4:
                cout<<"Valor al final: "<<lista.back()<<endl;
                break;
            case 5:
                cout<<"Size del queue: "<<lista.getSize()<<endl;
                break;
            case 6:
                lista.clear();
                break;
            case 7:
                print(lista);
                break;
            case 8:
                continues = false;
                break;
            default:
                cout<<"Valor invalido"<<endl;
                break;
        }
        cout<<endl;
        print(lista);
        cout<<endl;    
    }

    cout<<endl<<"Gracias por usar Queue tester!"<<endl<<endl;
    
    return 0;
}
