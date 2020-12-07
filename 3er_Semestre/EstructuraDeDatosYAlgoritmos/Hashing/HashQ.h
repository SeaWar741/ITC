//Juan Carlos Garfias Tovar, A01652138
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int BUCKETSQ = 50; //numero de elementos

template<class T>
class HashQ{
    private:
        T tList[BUCKETSQ];//tabla
        int hashing(int k, int j);//funcion de hasheo

        int changeToNumber(string key);//cambiar a numero
        bool verifyInt(const char & s);//checar si es un numero el char
    public: 
        HashQ();
        void insert(string key);//insertar valor
        void print();//imprimir tabla
};

//constructor default
//no es necesario inicializar nada
template<class T>
HashQ<T>::HashQ(){

}

//hashing
//realiza la funcion hasheo a partir de dos inputs y el size
//o(1)
template<class T>
int HashQ<T>::hashing(int k, int j) {
    return fmod(k + pow(j, 2), BUCKETSQ);
}

//verifyInt
//checa a partir de in char si este es un int
//o(n)
template<class T>
bool HashQ<T>::verifyInt(const char & ss){
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
int HashQ<T>::changeToNumber(string key){
    string numbers = "";
    for(int i = 0; i < key.size(); i++){
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
void HashQ<T>::insert(string key){
    int newElement = 0;
    int newKey = changeToNumber(key);
    int hash = hashing(newKey, newElement);
    while(tList[hash] != "" && newElement < BUCKETSQ){
        hash = hashing(newKey, newElement++);//aumenta en uno y realiza hasheo
    }
    tList[hash] = key;
}

//print
//itera sobre la tabla e imprime el valor string
//o(n)
template<class T>
void HashQ<T>::print(){
    cout << "Adress  " << "  Value\n";
    for(int i = 0; i < BUCKETSQ; i++){
        cout << "["<<i << "] --> ";
        cout << tList[i] << "\n";
    }
    cout << endl;
}