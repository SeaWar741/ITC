#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

//O(n2)
//Metodo de intercambio
template <class T>
vector<T> exchange(vector<T> list){
    T last;
    int comparaciones = 0,intercambios = 0;
    for (int i = 0; i <= list.size()-1; i++){
        for (int j = 0; j < list.size(); j++){
            comparaciones++;
            if(list[i]<list[j]){
                intercambios++;
                last = list[i];
                list[i] = list[j];
                list[j] = last;
            }
        }
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;
}

//o(n ^ 2)
//Buuble sort
template <class T>
vector<T> bubble(vector<T> list){
    T temp;
    int comparaciones = 0,intercambios = 0;
    for (int i = list.size(); i>0 ; i--){
        for (int j = 0; j < i-1; j++){
            comparaciones++;

            if(list[j]>list[j+1]){
                intercambios++;

                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;
}

//O(n^2)
//Bubble sort mejorado
template <class T>
vector<T> bubble2(vector<T> list){
    T temp;
    bool continues;
    int minIndex,comparaciones = 0,intercambios = 0;
    for (int i = 0; i < list.size()-1&&continues; i++){
        continues = false;
        for (int j = 0; j < list.size()-1-i; j++){
            if(list[j+i]<list[j]){
                intercambios++;

                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
        
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;
}

//O(n^2)
//Selection sort
template <class T>
vector<T> selection(vector<T> list){
    T temp;
    int minIndex,comparaciones = 0,intercambios = 0;
    for (int i = 0; i < list.size()-1; i++){
        minIndex = i;
        for (int j = i+1; j < list.size(); j++){
            comparaciones++;
            if (list[j] < list[minIndex]){
                minIndex = j;
            }
        }
        intercambios++;
        temp = list[i];
        list[i] = list[minIndex];
        list[minIndex]=temp;
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;
}

//O(n^2)
//insercion
template <class T>
vector<T> insertion(vector<T> list)  {  
    T key;
    int i, j;
    int comparaciones = 0,intercambios = 0;  
    for (i = 1; i < list.size(); i++) {  
        key = list[i];  
        j = i - 1;  

        comparaciones++;//aqui va?   

        while (j >= 0 && list[j] > key){//esto cambiarlo
             
            list[j + 1] = list[j];  
            j--;  
        }
        intercambios++;//aqui va?   
        list[j + 1] = key;  
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;  
}  


//--------------------Busquedas----------------------------
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
    //vector<int> list = {1,3,4,6,8,0,2,-4,6,15,10,25,20,21,30,32,-1,-6,2,45,-10,9,5,-45,-2,56,20,-21,-23,-19,20,21,-32,-5,2,30,-40,-23,-19};
    vector<int> list ={29,3,8,17,30,15,42};

    cout<<"*Original:"<<endl;
    print(list);

    cout<<endl<<"*Ordenada con Intercambio:"<<endl;
    auto start = high_resolution_clock::now(); 
    print(exchange(list));
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Tiempo de ejecucion: "<< duration.count()*0.000001 << " segundos" << endl; 

    cout<<endl<<"*Ordenada con Bubble:"<<endl;
    auto start1 = high_resolution_clock::now(); 
    print(bubble(list));
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<microseconds>(stop1 - start1); 
    cout << "Tiempo de ejecucion: "<< duration1.count()*0.000001 << " segundos" << endl; 

    cout<<endl<<"*Ordenada con Bubble optimizado:"<<endl;
    auto start2 = high_resolution_clock::now(); 
    print(bubble(list));
    auto stop2 = high_resolution_clock::now(); 
    auto duration2 = duration_cast<microseconds>(stop2 - start2); 
    cout << "Tiempo de ejecucion: "<< duration2.count()*0.000001 << " segundos" << endl;

    cout<<endl<<"*Ordenada con Selection:"<<endl;
    auto start3 = high_resolution_clock::now(); 
    print(selection(list));
    auto stop3 = high_resolution_clock::now(); 
    auto duration3 = duration_cast<microseconds>(stop3 - start3); 
    cout << "Tiempo de ejecucion: "<< duration3.count()*0.000001 << " segundos" << endl;

    cout<<endl<<"*Ordenada con Insertion:"<<endl;
    auto start4 = high_resolution_clock::now(); 
    print(insertion(list));
    auto stop4 = high_resolution_clock::now(); 
    auto duration4 = duration_cast<microseconds>(stop4 - start4); 
    cout << "Tiempo de ejecucion: "<< duration4.count()*0.000001 << " segundos" << endl;


    //-------------------Busquedas-----------------------------------------------------

    cout<<endl<<"*Busqueda iterativa:"<<endl;
    auto start5 = high_resolution_clock::now();  
    cout<<sequential(list,30)<<endl;
    auto stop5 = high_resolution_clock::now(); 
    auto duration5 = duration_cast<microseconds>(stop5 - start5); 
    cout << "Tiempo de ejecucion: "<< duration4.count()*0.000001 << " segundos" << endl;

    return 0;
}
