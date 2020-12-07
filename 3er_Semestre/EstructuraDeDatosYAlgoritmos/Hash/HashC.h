// Act 5.1 - Chained hash class
// Abraham Cepeda Oseguera
// A00827666
// 30 de noviembre 2020
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "LinkedList.h"

using namespace std;

const int SIZE2 = 50;

template<class T>
class HashC{
    private:
        vector< LinkedList<T> > table;
        
        int getNums(string key);
        int getHash(int k, int j){return fmod(k + pow(j, 2), SIZE2);};
        inline bool isInteger(const char & s);
    public:
        HashC();
        void insert(string key);
        void print();
};


//Constuctor
template<class T>
HashC<T>::HashC(){
    LinkedList<T> temp;
    vector< LinkedList<T> > tempTable(SIZE2, temp);
    table = tempTable;
}

//Method: isInnteger
//Description: checks if character is integer
//Input: ss (char to be checked)
//Output: bool (true if is integer false if not)
//Complexity: O(1)
template<class T>
inline bool HashC<T>::isInteger(const char & ss){
   string s = to_string(ss);
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

//Method: getNums
//Description: returns the numbers of the alphanumeric string
//Input: key (alphanuumeric string)
//Output: the numbers of the key
//Complexity: O(1)
template<class T>
int HashC<T>::getNums(string key){
    string numbers = "";
    for(int i = 0; i < 4; i++){
        if(isdigit(key[i])){
            numbers += key[i];
        }
    }
    return stoi(numbers);
}

//Method: insert
//Description: adds key to hash table
//Input: key (key to be added)
//Output: NA
//Complexity: O(n)
template<class T>
void HashC<T>::insert(string key){
    int j = 0;
    int newKey = getNums(key);
    int hash = getHash(newKey, j);
    if(table[hash].isEmpty()){
        table[hash].addFirst(key);
    } else{
        table[hash].addLast(key);
    }
    table[hash].print();
}

//Method: print
//Description: Prints the key of each hash table item
//Input: NA
//Output: key of each hash table item
//Complexity: O(n)
template<class T>
void HashC<T>::print(){
    cout << "Position  " << "  Value\n";
    for(int i = 0; i < SIZE2; i++){
        cout << i << "             ";
        table[i].print();
    }
    cout << "\n";
}