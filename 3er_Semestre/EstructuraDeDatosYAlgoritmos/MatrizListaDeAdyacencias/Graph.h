#include <iostream>
#include <vector>
#include<algorithm>

template<class T>
class Graph{
private:
    vector<vector<T>> adjList;
    vector<T> verticess;
    int qtyVertices;
    int qtyEdges;
public:
    Graph(vector<vector<T>> lista,int qtyVerticess, intqtyEdges);
    void print();
};

template<class T>
Graph<T>::Graph(/* args */){
}
