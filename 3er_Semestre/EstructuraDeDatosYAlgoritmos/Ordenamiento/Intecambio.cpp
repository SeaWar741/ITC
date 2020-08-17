#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

//O(n2)
//Metodo de intercambio
template <class T>
vector<T> exchange(vector<T> list){
    int last;
    for (int i = 0; i <= list.size()-1; i++){
        for (int j = 0; j < list.size(); j++){
            if(list[i]<list[j]){
                last = list[i];
                list[i] = list[j];
                list[j] = last;
            }
        }
    }
    return list;
}

//o(n cuadrado)
//Buuble sort
template <class T>
vector<T> bubble(vector<T> list){
    int temp;
    
    for (int i = 0; i < list.size()-1; i++){
        for (int j = 0; j < list.size()-1; j++){
            if(list[j]>list[j+1]){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
        
    }
    return list;
}

//O(n)
//Imprimir vector
template <class T>
void print(vector<T> list){
    for (int i = 0; i < list.size(); i++){
        cout<<"["<<i<<"] "<<list[i]<<endl;
    }
    
}

int main(){
    vector<int> list = {1,3,4,6,8,0,2,4,6,15,10};
    
    cout<<"Original:"<<endl;
    print(list);

    cout<<endl<<"Ordenada con Intercambio:"<<endl;
    auto start = high_resolution_clock::now(); 
    print(exchange(list));
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Tiempo de ejecucion: "<< duration.count() << " microsegundos" << endl; 

    cout<<endl<<"Ordenada con Bubble:"<<endl;
    auto start1 = high_resolution_clock::now(); 
    print(bubble(list));
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<microseconds>(stop1 - start1); 
    cout << "Tiempo de ejecucion: "<< duration1.count() << " microsegundos" << endl; 

    return 0;
}
