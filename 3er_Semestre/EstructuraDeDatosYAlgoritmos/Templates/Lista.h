//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <vector> 

using namespace std;

#ifndef Lista_h
#define Lista_h

template <class T>
class Lista{
private:
    static const int MAX = 100;
    vector <T> data;
    int size;
public:
    Lista();
    void insert(T dataI);
    T erase();
    T getData(int index);
    int getSize();
    void print();
};

template <class T>
Lista<T>::Lista(){
    size = 0;
}

template <class T>
void Lista<T>::insert(T dataI){
    if(size != MAX){
        this->data.push_back(dataI);
    }
    else{
        throw runtime_error("LISTA LLENA");
    }
    size++;
}

template <class T>
T Lista<T>::erase(){
    if(size!=0){
        T lastItem = data[size-1];
        data.pop_back();
        return lastItem;
    }
    else{
        throw runtime_error("NO HAY ELEMENTOS");
    }
    size--;
}

template <class T>
T Lista<T>::getData(int index){
    if(index >= 0 && index < size && size!=0){
        return data[index];
    }
    else{
        if(size ==0){
            throw runtime_error("NO HAY ELEMENTOS");
        }
        else{
            throw runtime_error("POSICION INVALIDA");
        }
    }
}

template <class T>
int Lista<T>::getSize(){
    return size;
}

template <class T>
void Lista<T>::print(){
    for(int i= 0; i<size;i++){
        cout<<"["<<i<<"]"<<" - "<<data[i]<<endl;
    }
}

#endif