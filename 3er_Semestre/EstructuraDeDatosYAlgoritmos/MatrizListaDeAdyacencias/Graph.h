//Juan Carlos Garfias Tovar, A01652138
#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class Graph{
    private:
        vector<vector<T>>  adjList; //adjacency list
        vector<T> vertices; //vertices del grafo
        int qtyVertices;
        int qtyEdges;
        int findVertex(T vertex);
    public:
        Graph(vector<vector<T>> list,int qtyVertices, int qtyEdges);
        void print();
};

//constructor default
//recibe una lista, cantidad de vertices y de edges
template<class T>
Graph<T>::Graph(vector <vector<T> > list, int qtyVertices, int qtyEdges){
    this ->qtyEdges = qtyEdges;
    this ->qtyVertices = qtyVertices;

    int source = 0;
    int target = 1;

    for(vector<T> edge : list){ //itera sobre la lista y hace add a los valores
        T temp = edge[source];
        int pos = findVertex(temp);
        if(pos>= 0){
            adjList[pos].push_back(edge[target]);
        }else{
            vertices.push_back(temp);
            adjList.push_back(edge);
        }
    }
    if(vertices.size()<qtyVertices){
        for(vector<T> edge:list){
            T temp = edge[target];
            int pos = findVertex(temp);
            if(pos<0){//Cuando no lo encuentra
                vertices.push_back(temp);
                vector<T> tempVertex;
                tempVertex.push_back(temp);
                adjList.push_back(tempVertex);
            }
        }
    }
}

//findVertex
//funcion para encontrar el vertice en el grafo
//utiliza un iterador, permitiendo 
//encontrar la posicion del target
//O(n)
template<class T>
int Graph<T>::findVertex(T vertex){
    typename vector<T>::iterator it;
    it = find(vertices.begin(),vertices.end(),vertex);
    if(it != vertices.end()){
        return it - vertices.begin();
    }else{
        return -1;
    }
}

//print
//funcion para imprimir la lista 
//se itera sobre los nodos y vertices
//O(n)
template<class T>
void Graph<T>::print(){
    for (vector<T> vertex: adjList){
        for(T node: vertex){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    
}

#endif