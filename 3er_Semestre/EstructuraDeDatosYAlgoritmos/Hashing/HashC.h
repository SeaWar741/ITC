//Juan Carlos Garfias Tovar, A01652138
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "LinkedList.h"

using namespace std;

const int BUCKETS = 50;//numero de elementos

template<class T>
class HashC{
    private:
        vector< LinkedList<T> > tTable;//tabla de elementos
        int hashing(int k, int j);//funcion hasheo

        int changeToNumber(string key);//pasar a numero
        inline bool verifyInt(const char & s);//verificar numero
    public:
        HashC();
        void insert(string key);//insertar elemento
        void print();
};


//Constuctor
//inicializa un vector a partir de el numero de buckets
template<class T>
HashC<T>::HashC(){
    LinkedList<T> temp;
    vector< LinkedList<T> > temptTable(BUCKETS, temp);
    tTable = temptTable;
}

//hashing
//realiza la funcion hasheo a partir de dos inputs y el size
//o(1)
template<class T>
int HashC<T>::hashing(int k, int j){
    return fmod(k + pow(j, 2), BUCKETS);
};


//verifyInt
//checa a partir de in char si este es un int
//o(n)
template<class T>
inline bool HashC<T>::verifyInt(const char & ss){
   string s = to_string(ss);
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}


//changeToNumber
//toma el string dado(key) y lo pasa a valores int
//itera sobre el string a partir de chars
//o(n)
template<class T>
int HashC<T>::changeToNumber(string key){
    string numbers = "";
    for(int i = 0; i < 4; i++){
        if(isdigit(key[i])){//checa si es numero o no
            numbers += key[i];
        }
    }
    return stoi(numbers);
}

//insert
//toma el string y lo inserta en el hash
//realiza la funcion de cambiar a numero y lo hashea
//o(n)
template<class T>
void HashC<T>::insert(string key){
    int j = 0;
    int newKey = changeToNumber(key);
    int hash = hashing(newKey, j);
    if(tTable[hash].isEmpty()){
        tTable[hash].addFirst(key);
    } else{
        tTable[hash].addLast(key);
    }
    //tTable[hash].print();
}


//print
//itera sobre la tabla e imprime el valor string
//o(n)
template<class T>
void HashC<T>::print(){
    cout << "Adress  " << "  Value\n";
    for(int i = 0; i < BUCKETS; i++){
        cout << "["<<i << "] --> ";
        tTable[i].print();
    }
    cout << endl;
}