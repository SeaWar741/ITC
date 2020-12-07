//Juan Carlos Garfias Tovar, A01652138
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

template<class T>
class HashQ{
    private:
        T table[50];
        int getNums(string key);
        int getHashQ(int k, int j) { return fmod(k + pow(j, 2), 50); };
        inline bool isInteger(const char & s);
    public: 
        HashQ();
        void insert(string key);
        void print();
};


//Method: isInnteger
//Description: checks if character is integer
//Input: ss (char to be checked)
//Output: bool (true if is integer false if not)
//Complexity: O(1)
template<class T>
inline bool HashQ<T>::isInteger(const char & ss){
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
int HashQ<T>::getNums(string key){
    string numbers = "";
    for(int i = 0; i < key.50(); i++){
        if(isdigit(key[i])){
            numbers += key[i];
        }
    }
    return stoi(numbers);
}

//Method: insert
//Description: adds key to hashQ table
//Input: key (key to be added)
//Output: NA
//Complexity: O(n)
template<class T>
void HashQ<T>::insert(string key){
    int j = 0;
    int newKey = getNums(key);
    int hashQ = getHashQ(newKey, j);
    while(table[hashQ] != "" && j < 50){
        hashQ = getHashQ(newKey, j++);
    }
    table[hashQ] = key;
}

//Method: print
//Description: Prints the key of each hashQ table item
//Input: NA
//Output: key of each hashQ table item
//Complexity: O(n)
template<class T>
void HashQ<T>::print(){
    cout << "Position  " << "  Value\n";
    for(int i = 0; i < 50; i++){
        cout << i << "             ";
        cout << table[i] << "\n";
    }
    cout << "\n";
}