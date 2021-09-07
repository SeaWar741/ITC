//Actividad 2.2 Implementación de "Sufix Array"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <string.h>
#include <utility>
#include <algorithm>

using namespace std;

//suffix
struct Suffix{
    string x; //string
    short int d; //pos
    int longestCommonPrefix; //pos longestCommonPrefix
};

//compare suffixes
//input: sufijo a,sufijo b
//compara los strings de los sufijos para ver si a es menor a b
//o(1)
bool compareSuffixes(const Suffix a,const Suffix b){
    return a.x<b.x;
}

//findLongestCommonPrefixArray
//input: string a, string b
//compara los strings y verifica la longitud e igualdad
//O(n^2)
int findLongestCommonPrefixArray(string a,string b){
    int i=0,j=0,k=0;
    while(i<a.length() && j<b.length()){
        if(a[i]==b[j]){
            k++;
            i++;
            j++;
        }
        else{
            break;
        }
    }
    return k;
}


//------------------------------------------------------------------------------

//Suffix Array
class SuffixArray{    
    public:
        string txt;
        Suffix suffixArray[10000];
        int len;
        SuffixArray(string a);
        void printArray();
        void printLongestCommonPrefixes();
        void printLenght();
};

SuffixArray::SuffixArray(string a){
    txt = a+'$';
    this->len = txt.length();

    for(int i=0;i<len;i++){
        suffixArray[i].x = txt.substr(i);
        suffixArray[i].d = i+1;
    }

    //O(n2 log n)
    sort(suffixArray,suffixArray+len,compareSuffixes);

    suffixArray[0].longestCommonPrefix=0;
    suffixArray[1].longestCommonPrefix=0;

    for(int i=2;i<len;i++){
        suffixArray[i].longestCommonPrefix = findLongestCommonPrefixArray(suffixArray[i].x,suffixArray[i-1].x);
    }
}

void SuffixArray::printArray(){
    cout<<"\nArreglo de sufijos ordenados:"<<endl;
    for(int i=0;i< this->len;i++){
        cout<< this->suffixArray[i].x<<" "<< this->suffixArray[i].d<<endl;
    }
    cout<<endl;
}

void SuffixArray::printLongestCommonPrefixes(){
    for(int i=0;i<len;i++){
        cout<<suffixArray[i].d<<" "<<suffixArray[i].longestCommonPrefix<<endl;    
    }  
}

//------------------------------------------------------------------------------

int main(){ 

    string txt;

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Programacion Sufix Array\n";
    cout<<"----------------------------------------------------------------------------------------\n";
    cout << "\nIngresa el texto>";cin >> txt; cout << "\n";  
    

    SuffixArray arreglo(txt); //se crea objeto de suffixArray
    arreglo.printArray();
    
}