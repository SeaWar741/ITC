//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;
using namespace std::chrono; 

//letras y strings a usar para poblar vectoress
char lettersChar[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r', 's', 't', 'u', 'v', 'w', 'x','y', 'z'};
string lettersString[26] = {"Hola", "Como", "Estas", "Te", "Caes", "Super", "Amigo", "Divertido", "Rie", "Canta", "Fruta", "Limon", "Manzana", "Naranja", "Uva", "Perro", "Si", "No", "Quiza", "Tu", "El", "Ella", "Nosotros", "Somos", "Son", "Quiero"};


//--------------------Utility functions--------------------

//O(n)
//Imprimir vector
template <class T>
void print(vector<T> list){
    for (int i = 0; i < list.size(); i++){ //se itera e imprime cada elemento separado por espacio
        cout<<list[i]<<"  ";
    }
    cout<<endl<<endl;
}

//--------------------Sorting Algorithms--------------------

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
//Bubble Sort
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
//Bubble Sort mejorado
template <class T>
vector<T> bubble2(vector<T> list){
    T temp;
    bool continues;
    int minIndex,comparaciones = 0,intercambios = 0;
    for (int i = 0; i < list.size()&&continues; i++){
        continues = false;
        for (int j = 0; j < list.size()-1-i; j++){
            comparaciones++;
            if(list[j]>list[j+1]){
                intercambios++;

                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                continues =true;
            }
        }
        
    }
    cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;
}

//O(n^2)
//Selection Sort
template <class T>
vector<T> selectionSort(vector<T> list){
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
//Insertion Sort
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


//Merge Sort helper
template <class T>
void merge(vector<T> &list,int left,int middle,int right, int &comp){
    int i = 0, j =0;
    int counter =left;
    vector<T> vectorLeft, vectorRight;

    //Copy to new vectors
    for(int iter1 = left; iter1 <= middle; iter1++){
        vectorLeft.push_back(list[iter1]);
    }
    for(int iter2 = middle+1; iter2 <= right; iter2++){
        vectorRight.push_back(list[iter2]);
    }

    //
    while(i < (middle-left+1) && j < (right-middle)){
        comp++;
        if(vectorLeft[i] > vectorRight[j]){
            list[counter] = vectorRight[j];
            j++;
        } else{
            list[counter] = vectorLeft[i];
            i++;
        }
        counter++;
    }

    //
    while(i < (middle - left + 1)){
        list[counter] = vectorLeft[i];
        counter++;
        i++;
    }
    while(j < (right-middle)){
        list[counter] = vectorRight[j];
        counter++;
        j++;
    }
}

//O(nlogn)
//Merge Sort
template<class T>
void mergeSort(vector<T> &list,int left,int right,int &comp){
    if(left<right){
        int middle = left + (right-left)/2;
        mergeSort(list,left,middle,comp);
        mergeSort(list,middle+1,right,comp);

        merge(list,left,middle,right,comp);
    }
}


//Quick Sort swap helper
template<class T>
void swap(vector<T> &list, int num1, int num2){
    T num = list[num1];
    list[num1] = list[num2];
    list[num2] = num;
}

//Quick Sort vector spliter
template<class T>
int divide(vector<T> &list, int begin, int end,int &comp){
    int pos = begin+1, r = end;
    while(pos < r){
        comp++;
        while(list[pos] < list[begin] && pos != end){
            pos++;
            comp++;
        }
        while(list[r] >= list[begin] && r != begin){
            r--;
            comp++;
        }
        if(r > pos){
            swap(list, pos, r);
        } 
        else{
            swap(list, begin, r);
        }
    }
    if(list[begin] > list[r]){
        swap(list, begin, r);
    }
    return r;
} 

//O(nlogn)
//Quick Sort
template<class T>
void quickSort(vector<T> &vect, int l, int r,int &comp){
    int pos;
    if(l < r){
        pos = divide(vect, l, r,comp);
        quickSort(vect, l, pos-1,comp);
        quickSort(vect, pos+1, r,comp);
    }
}



//--------------------Busquedas----------------------------

//O(n)
//Busqueda secuencial
template <class T>
int sequential(vector<T> list,T element){
    int i=0;
    while(i<list.size()){
        if(list[i]==element){ //itera por todos los elementos hasta encontrarlo
            return i;
        }
        i++;
    }
    return -1;
    
}

//O(log n)
//Busqueda Binaria
template<class T>
int binarySearch(vector<T> list,T value){
    int low = 0;
    int high = list.size() - 1;
    while(low <= high){ //parte el vector a partir de comparaciones con el target
        int medium = (high + low) / 2;
        if(list[medium] == value){
            return medium;
        } else if(list[medium] > value){
            high = medium - 1;
        } else{
            low = medium + 1;
        }
    }
    return -1;
}


//-----------------Vector Creation Functions---------------

//O(n)
template<class T>
void newIntVector(vector<T> &vect, int n){
    random_device rd; //Crea un random y hace push del dato
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, n);
    for(int i = 0; i < n; i++){
        vect.push_back(dist(mt));
    }
}

//O(n)
template<class T>
void newDoubleVector(vector<T> &vect, double n){
    random_device rd;//Crea un random y hace push del dato. Lo redondea para ser visible
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, n);
    for(int i = 0; i < n; i++){
        vect.push_back(round(10. * dist(mt)) / 10.);
    }
}

//O(n)
template<class T>
void newCharVector(vector<T> &vect, int n){
    random_device rd;//Crea un random y hace push del dato a partir del indice de letras char
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 25); 
    for(int i = 0; i < n; i++){
        vect.push_back(lettersChar[dist(mt)]);
    }
}

//O(n)
template<class T>
void newStringVector(vector<T> &vect, int n){
    random_device rd;//Crea un random y hace push del dato a partir del indice de palabras
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 25);
    for(int i = 0; i < n; i++){
        vect.push_back(lettersString[dist(mt)]);
    }
}


//--------------------Menu functions--------------------

//Menu para los algoritmos de ordenamiento
//toma la lista, la clona y el tipo de dato como parametro
template <class T>
void sortingMenu(vector<T> listC,int type){
    int selection;  
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"Selecciona el algoritmo"<<endl;
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"1) Exchange"<<endl;
    cout<<"2) Selection"<<endl;
    cout<<"3) Bubble"<<endl;
    cout<<"4) Insertion"<<endl;
    cout<<"5) Merge"<<endl;
    cout<<"6) Quick"<<endl<<endl;
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"Ingresar seleccion >";cin>>selection;
    vector<T> list =listC;
    cout<<"Vector:"<<endl;
    print(list);
    if(selection>=1 && selection<=6){//verifica rango y evalua el metodo deseado
        if(selection == 1){
            cout<<endl<<"*Ordenada con Intercambio:"<<endl;
            auto start = high_resolution_clock::now(); 
            print(exchange(list));
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start); 
            cout << "Tiempo de ejecucion: "<< duration.count()*0.000001 << " segundos" << endl; 
        }
        if(selection == 2){
            cout<<endl<<"*Ordenada con Selection:"<<endl;
            auto start3 = high_resolution_clock::now(); 
            print(selectionSort(list));
            auto stop3 = high_resolution_clock::now(); 
            auto duration3 = duration_cast<microseconds>(stop3 - start3); 
            cout << "Tiempo de ejecucion: "<< duration3.count()*0.000001 << " segundos" << endl;
        }
        if(selection == 3){
            cout<<endl<<"*Ordenada con Bubble:"<<endl;
            auto start1 = high_resolution_clock::now(); 
            print(bubble(list));
            auto stop1 = high_resolution_clock::now(); 
            auto duration1 = duration_cast<microseconds>(stop1 - start1); 
            cout << "Tiempo de ejecucion: "<< duration1.count()*0.000001 << " segundos" << endl; 
            
            cout<<endl<<"*Ordenada con Bubble optimizado:"<<endl;
            auto start2 = high_resolution_clock::now(); 
            print(bubble2(list));
            auto stop2 = high_resolution_clock::now(); 
            auto duration2 = duration_cast<microseconds>(stop2 - start2); 
            cout << "Tiempo de ejecucion: "<< duration2.count()*0.000001 << " segundos" << endl;
        }
        if(selection == 4){
            cout<<endl<<"*Ordenada con Insertion:"<<endl;
            auto start4 = high_resolution_clock::now(); 
            print(insertion(list));
            auto stop4 = high_resolution_clock::now(); 
            auto duration4 = duration_cast<microseconds>(stop4 - start4); 
            cout << "Tiempo de ejecucion: "<< duration4.count()*0.000001 << " segundos" << endl;
        }
        if(selection == 5){
            cout<<endl<<"*Ordenada con Merge:"<<endl;
            auto start8 = high_resolution_clock::now(); 
            int initial =0;
            int sizelist = list.size() - 1;
            int comparisonsMerge = 0;
            mergeSort(list,0,sizelist,comparisonsMerge);
            cout<<"-Comparaciones: "<<comparisonsMerge<<endl<<endl;
            print(list);
            auto stop8 = high_resolution_clock::now(); 
            
            auto duration8 = duration_cast<microseconds>(stop8 - start8); 
            cout << "Tiempo de ejecucion: "<< duration8.count()*0.000001 << " segundos" << endl;
        }
        
        if(selection == 6){
            cout<<endl<<"*Ordenada con QuickSort:"<<endl;
            auto start9 = high_resolution_clock::now();
            int comparisonsQuick = 0;
            quickSort(list,0, (list.size()-1),comparisonsQuick);
            cout<<"-Comparaciones: "<<comparisonsQuick<<endl<<endl;
            print(list);
            auto stop9 = high_resolution_clock::now(); 
            auto duration9 = duration_cast<microseconds>(stop9 - start9); 
            cout << "Tiempo de ejecucion: "<< duration9.count()*0.000001 << " segundos" << endl;
        }
        /**/
    }
    else{
        cout<<endl<<"ERROR ENTRADA NO VALIDA"<<endl; //fuera de rango
    }
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
}   

//Menu para algoritmos de busqueda
//toma la lista, la clona, el tipo de dato como parametro y el elemento a buscar
template <class T>
void searchMenu(vector<T> listC,int type,T search){
    vector<T> list; 

    int selection;  
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"Selecciona el algoritmo"<<endl;
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"1) Sequential"<<endl;
    cout<<"2) Binary"<<endl;
    cout<<endl<<"------------------------------------------------"<<endl;
    cout<<"Ingresar seleccion >";cin>>selection;
    list =listC;
    
    cout<<endl;
    int comparisonsQuick = 0;
    quickSort(list,0, (list.size()-1),comparisonsQuick);
    cout<<"Se ordena el vector:"<<endl;
    print(list);

    if(selection>=1 && selection<=3){//verifica rango y realiza busqueda
        if(selection ==1){
            cout<<endl<<"*Busqueda iterativa:"<<endl;
            auto start5 = high_resolution_clock::now();  
            cout<<sequential(list,search)<<endl;
            auto stop5 = high_resolution_clock::now(); 
            auto duration5 = duration_cast<microseconds>(stop5 - start5); 
            cout << "Tiempo de ejecucion: "<< duration5.count()*0.000001 << " segundos" << endl;
        }
        if(selection == 2){
            
            cout<<"*Busqueda binaria:"<<endl;
            auto start6 = high_resolution_clock::now();  
            cout<<binarySearch(list,search)<<endl;
            auto stop6 = high_resolution_clock::now(); 
            auto duration6 = duration_cast<nanoseconds>(stop6 - start6); 
            cout << "Tiempo de ejecucion: "<< duration6.count()*0.0000000001 << " segundos" << endl;
        }

    }
    else{
        cout<<endl<<"ERROR ENTRADA NO VALIDA"<<endl;
    }
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
}


void menu(){
    int selectionTop;
    int type,inputLength;
    bool continuesTop = true;

    vector <char> charVector;
    vector <string> stringVector;
    vector <int> intVector;
    vector <double> doubleVector;

    char searchc;
    string searchs;
    int searchi;
    double searchd;
    
    cout<<endl<<"------------------------------------------------"<<endl;
    cout<<endl<<"Algoritmos esenciales de ordenamiento y busqueda"<<endl<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;

    cout<<"Selecciona tipo de dato"<<endl;
    cout<<"1) char"<<endl;
    cout<<"2) string"<<endl;
    cout<<"3) int"<<endl;
    cout<<"4) double"<<endl<<endl;
    cout<<"Ingresar seleccion >";cin>>type;
    cout<<"Ingresar size >";cin>>inputLength;
    cout<<endl<<"Vector:"<<endl;
    switch (type){ //Switch para opciones de tipo de dato (populates data)
        case 1:
            newCharVector(charVector,inputLength);
            print(charVector);
            break;
        case 2:
            newStringVector(stringVector,inputLength);
            print(stringVector);
            break;
        case 3:
            newIntVector(intVector,inputLength);
            print(intVector);
            break;
        case 4:
            newDoubleVector(doubleVector,inputLength);
            print(doubleVector);
            break;
        default:
            break;
    }
    cout<<endl<<"------------------------------------------------"<<endl<<endl;

    if( (type >= 1 && type <=4) && (inputLength >0) ){ //verifica rangos
        while (continuesTop){ //mientras no se de la opcion de salir loop 
            cout<<"1) Algoritmos de ordenamiento"<<endl;
            cout<<"2) Algoritmos de busqueda"<<endl;
            cout<<"3) Salir"<<endl<<endl;
            cout<<"Ingresar seleccion >";cin>>selectionTop;
            switch (selectionTop){ //switch para la seleccion a partir de tipo de dato
                case 1:
                    if(type ==1){
                        sortingMenu(charVector,type);
                    }
                    if(type ==2){
                        sortingMenu(stringVector,type);
                    }
                    if(type ==3){
                        sortingMenu(intVector,type);
                    }
                    if(type ==4){
                        sortingMenu(doubleVector,type);
                    }
                    break;
                case 2:
                    if(type ==1){
                        cout<<endl<<"Ingresar elemento a buscar >";cin>>searchc;
                        searchMenu(charVector,type,searchc);
                    }
                    if(type ==2){
                        cout<<endl<<"Ingresar elemento a buscar >";cin>>searchs;
                        searchMenu(stringVector,type,searchs);
                    }
                    if(type ==3){
                        cout<<endl<<"Ingresar elemento a buscar >";cin>>searchi;
                        searchMenu(intVector,type,searchi);
                    }
                    if(type ==4){
                        cout<<endl<<"Ingresar elemento a buscar >";cin>>searchd;
                        searchMenu(doubleVector,type,searchd);
                    }
                    break;
                case 3:
                    continuesTop = false; //rompe loop
                    break;
                default:
                    cout<<endl<<endl<<"Input no valido"<<endl<<endl;
                    break;
            }
        }
    }
    else{
        cout<<"ERROR ENTRADA NO VALIDA"<<endl;//fuera de rango
    }
    
    //Mensaje despedida
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
    cout<<"GRACIAS POR USAR EL PROGRAMA!"<<endl;
    cout<<endl<<"------------------------------------------------"<<endl<<endl;
}

//--------------------Main--------------------
int main(){
    try{ //try catch general
        menu();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        cout<<"Unexpected behavior EXITING"<<endl;
    }
    return 0;
}