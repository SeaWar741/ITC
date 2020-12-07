//Juan Carlos Garfias Tovar, A01652138

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "LinkedList.h"

using namespace std;


template<class T>
class Hash{
    private:
        vector< LinkedList<T> > tList;
        int SIZE;
        void split(vector<string> &vect, string str, string pattern);
        int changeToNumber(string key);
        int hashing(int k, int j);
        int findKey(string key);
    public:
        Hash(int size);
        
        int getSize(){return SIZE;};
        
        void insert(string key);
        void insertEdge(string key, string edge);
        
        void print();
        void printEdges(string key);
};


//Constuctor
template <class T>
Hash<T>::Hash(int size){
    this->SIZE = size;
    LinkedList<T> temp;
    vector< LinkedList<T> > temptList(SIZE, temp);
    tList = temptList;
}

//split
//parte el string a partir de un delimitador
//o(n)
template<class T>
void Hash<T>::split(vector<string> &vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    while(end >= 0){
        end = int(str.find(pattern, beg));
        vect.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }
}


//changeToNumber
//toma el string dado(key) y lo pasa a valores int
//itera sobre el string a partir de chars
//o(n)
template<class T>
int Hash<T>::changeToNumber(string key){
    string numbers = "";
    for(int i = 0; i < key.size(); i++){
        if(isdigit(key[i])){//checa si es numero o no
            numbers += key[i];
        }
    }
    return stoi(numbers);
}


//hashing
//funcion para realizar hashing
//o(1)
template<class T>
int Hash<T>::hashing(int k, int j){
    return fmod(k + pow(j, 5), SIZE);
}

//findKey
//funcion para obtener el valor a partir de key
//o(n)
template<class T>
int Hash<T>::findKey(string key){
    int j = 0;
    int newKey = changeToNumber(key);
    int hash = hashing(newKey, j);
    while(tList[hash].getData(1) != key && j < SIZE){
        hash = hashing(newKey, j++);
    }
    return j == SIZE ? -1 : hash;
}


//insert
//funcion para insertar key
//o(n)
template<class T>
void Hash<T>::insert(string key){
    int j = 0;
    int newKey = changeToNumber(key);
    int hash = hashing(newKey, j);
    while(!tList[hash].isEmpty()){
        hash = hashing(newKey, j++);
    }
    tList[hash].addFirst(key);
}


//insertEdge
//funcion para insertar edge
//o(1)
template<class T>
void Hash<T>::insertEdge(string key, string edge){
    int hash = findKey(key);
    tList[hash].addLast(edge);
}

//printEdges
//funcion para imprimir ejes
//o(n)
template<class T>
void Hash<T>::printEdges(string key){
    int hash = findKey(key);
    if(hash == -1){
        cout << "IP NOT PRESENT IN REGISTRY"<<endl;
    } else{
        tList[hash].print();
    }
}


//print
//itera sobre la tabla e imprime el valor string
//o(n)
template<class T>
void Hash<T>::print(){
    cout << "Adress  " << "  Value\n";
    for(int i = 0; i < SIZE; i++){
        cout << "["<<i << "] --> "<< tList[i] << endl;
    }
    cout << endl;
}