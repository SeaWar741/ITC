//Juan Carlos Garfias Tovar, A01652138
#ifndef GraphM_h
#define GraphM_h

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

template<class T>
class GraphM{
    private:
        vector< vector<bool> > adjMatrix;//matriz
        vector<T> vertices;//vertices
        int qtyVertices;
        int qtyEdges;
        int findVertex(T vertex);
        
    public:
        GraphM(vector< vector<T>> list, int qtyVertices, int qtyEdges);
        void print();
};

//constructor default
//recibe una lista, cantidad de vertices y de edges
template<class T>
GraphM<T>::GraphM(vector< vector<T>> list, int qtyVertices, int qtyEdges){
    this -> qtyVertices = qtyVertices;
    this ->qtyEdges = qtyEdges;

    int source = 0;
    int target = 1;
    int pos;
    T temp;

    for(int i = 0;i<qtyVertices;i++){ //crea matriz vacia
        vector<bool> temp;
        for(int j=0; j < qtyVertices; j++){
            temp.push_back(false);
        }
        adjMatrix.push_back(temp);
    }

    for(vector<T> edge: list){ //lista de vertices
        temp = edge[source];
        pos = findVertex(temp);
        if(pos < 0){//no lo encuentra
            vertices.push_back(temp);
        }
        temp = edge[target];
        pos = findVertex(temp);
        if(pos < 0){//no lo encuentra
            vertices.push_back(temp);
        }
    }

    sort(vertices.begin(),vertices.end());
    for(vector<T> edge :list){ //llena la matriz
        int posSource = findVertex(edge[source]);
        int posTarget = findVertex(edge[target]);
        adjMatrix[posSource][posTarget] = true;
    }
}

//findVertex
//funcion para encontrar el vertice en el grafo
//utiliza un iterador, permitiendo 
//encontrar la posicion del target
//O(n)
template<class T>
int GraphM<T>::findVertex(T vertex){
    typename vector<T>::iterator it;
    it = find(vertices.begin(),vertices.end(),vertex);
    if(it != vertices.end()){
        return it - vertices.begin();
    }else{
        return -1;
    }
}

//print
//funcion para imprimir la matriz 
//O(n)
template<class T>
void GraphM<T>::print(){
    cout<<"  ";
    for(T vertex : vertices){
        cout<<vertex<<" ";
    }
    cout<<endl;
    for (int i = 0; i < qtyVertices; i++){
        cout<<vertices[i]<<" ";
        for (int j = 0; j < qtyVertices; j++){
            if(adjMatrix[i][j]){
                cout<< "T"<<" "; //se da formato
            }
            else{
                cout<<"F"<<" ";
            }
        }
        cout<<endl; 
    }
    
}

#endif