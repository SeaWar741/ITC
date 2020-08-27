#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

//O(n^2)
//insertion
template <class T>
vector<T> insertion(vector<T> list)  {  
    T key;
    int i, j;
    int comparaciones = 0,intercambios = 0;  
    for (i = 1; i < list.size(); i++) {  
        key = list[i];  
        j = i - 1;  

        comparaciones++;

        while (j >= 0 && list[j] > key){
            list[j + 1] = list[j];  
            j--;  
        }
        intercambios++;
        list[j + 1] = key;  
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;  
}

//--------------------Busquedas----------------------------

//O(n)
template <class T>
int sequential(vector<T> list,T element){
    int i=0;
    while(i<list.size()){
        if(list[i]==element){
            return i;
        }
        i++;
    }
    return -1;
    
}

//O(log n)
template<class T>
int binarySearch(vector<T> list,T value){
    int low,high,mid;
    low = 0;
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        if(list[mid]==value){
            return mid;
        }
        else if(list[mid]<value){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}



//--------------------Imprimir----------------------------
//O(n)
//Imprimir vector
template <class T>
void print(vector<T> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<'\t';
    }
    cout<<endl<<endl;
}

int main(){
    vector<int> list = {8,11,11,30,45,82,191,212,220,283,325,326,345,363,394,425};


    cout<<endl<<"Busqueda iterativa:"<<endl;
    auto start1 = high_resolution_clock::now();  
    cout<<sequential(list,30)<<endl;
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1); 
    cout << "Tiempo de ejecucion: "<< duration1.count()*0.0000000001 << " segundos" << endl;

    cout<<endl<<"Busqueda binaria:"<<endl;
    auto start2 = high_resolution_clock::now();  
    cout<<binarySearch(list,30)<<endl;
    auto stop2 = high_resolution_clock::now(); 
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2); 
    cout << "Tiempo de ejecucion: "<< duration2.count()*0.0000000001 << " segundos" << endl;

    return 0;
}
