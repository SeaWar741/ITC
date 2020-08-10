//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <vector> 

using namespace std;

#ifndef Lista_h
#define Lista_h
 
//se llama a template
template <class T>
class Lista{
private:
    static const int MAX = 100; //constante MAX
    vector <T> data;//vector de dato T (variable en tipo)
    int size;//tamaño del array/vector
public:
    Lista(); //constructor
    void insert(T dataI); //insert con dato T
    T erase(); //borrar regresando dato T
    T getData(int index); //obtener con dato T
    int getSize(); //regresar tamaño
    void print(); //imprimir lista
};

//se llama a template
template <class T>
Lista<T>::Lista(){ //constructor
    size = 0;
}

//se llama a template
template <class T>
void Lista<T>::insert(T dataI){
    if(size != MAX){ //si el tamaño no es el maximo se mete dato
        this->data.push_back(dataI);
        size++;//incrementa el size
    }
    else{//en caso de que falle (out of bounds) sale error
        throw runtime_error("LISTA LLENA");
    }
}

//se llama a template
template <class T>
T Lista<T>::erase(){
    if(size!=0){ //si el tamaño no es 0 se elimina y despliega dato final
        T lastItem = data[size-1];
        data.pop_back(); //se elimina el ultimo elemento
        size--; //se reduce el tamaño
        return lastItem;
    }
    else{
        throw runtime_error("NO HAY ELEMENTOS");
    }
}

//se llama a template
template <class T>
T Lista<T>::getData(int index){
    if(index >= 0 && index < size && size!=0){
        return data[index]; //si el indice esta entre el rango y el tamaño es mayor a 0
    }
    else{
        if(size ==0){//si el tamaño es 0 entonces regresa error
            throw runtime_error("NO HAY ELEMENTOS");
        }
        else{//si la posicion es out of bounds regresa error
            throw runtime_error("POSICION INVALIDA");
        }
    }
}

//se llama a template
template <class T>
int Lista<T>::getSize(){
    return size; //regresa el size
}

//se llama a template
template <class T>
void Lista<T>::print(){
    if(size !=0){//si no esta vacio
        for(int i= 0; i<size;i++){//imprime desde 0 hasta el size
            cout<<"["<<i<<"]"<<" - "<<data[i]<<endl;
        }
    }
    else{
        cout<<"NO HAY ELEMENTOS"<<endl;
    }
}

#endif