//List = {{0,2,1},{0,3,7},{2,0,1},{2,1,1},{2,6,3},{1,2,1},{1,6,3},{1,5,4},{5,1,4},{5,6,4},{5,3,7},{3,0,7},{3,5,7},{3,7,1},{6,2,3},{6,1,3},{6,5,4},{6,4,6},{6,7,6},{7,6,6},{7,3,1},{4,6,6}};
//Juan Carlos Garfias Tovar, A01652138
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

//struct para los edges
template<class T>
struct Edge {
    T vertex; //vertice 
    int weight; //peso
};


template<class T>
class Graph{
private:
    /* data */
    vector< vector< Edge<T> > > adjList;
    vector<T> vertices;
    int qtyVertices;
    int qtyEdges;
    int findVertex(T vertex);
    void dfsR(T vertex, vector<bool> &status);

    int minWeight(vector<int> weight, vector<bool> status);
    void topologicalSortR(int n, vector<bool> &status, stack<int> &s);
    bool isBipartiteR(int n, vector<int> &colors, int color);
public:
    Graph(vector< vector<T> > list);
    void bfs();
    void dfs();
    void bfsPrint(T vertex);
    void dfsPrint(T vertex);

    void shortestPath(T vertex);
    void topologicalSort();
    bool isBipartite();

    void print();
};

//constructor
template <class T>
Graph<T>::Graph(vector< vector<T> > list){
    int source = 0;
    int target = 1;
    int weight = 2;
    //Hacer add de los vertices con sus respectivo vector y su lista de adyacencia
    for(vector<T> edge: list){
        T temp = edge[source];
        int pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);// se inserta
        }
        temp = edge[target];
        pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);//se inserta
        }
    }
    sort(vertices.begin(), vertices.end());//los ordena
    
    for(auto vertex: vertices){
        vector< Edge<T> > temp;
        Edge<T> edge;
        edge.vertex = vertex;
        edge.weight = 0;
        temp.push_back(edge);
        adjList.push_back(temp);//se insertan
    }
    
    vector< Edge<T> > temp; //lista temporal
    vector< vector< Edge<T> > > tempList(vertices.size(), temp);
    adjList = tempList;
    
    for(auto path: list){
        int pos = findVertex(path[source]);
        Edge<T> edge;
        edge.vertex = path[target];
        edge.weight = path[weight];
        adjList[pos].push_back(edge);//se insertan
    }
}

//findVertex
//funcion para encontrar el vertice en el grafo
//utiliza un iterador, permitiendo 
//encontrar la posicion del target
//O(n)
template<class T>
int Graph<T>::findVertex(T vertex){
    typename vector<T>::iterator iter;
    iter = find(vertices.begin(), vertices.end(), vertex);
    return (iter != vertices.end() ? (int(iter - vertices.begin())) : -1);
}


//dfsR
//funcion complementaria para el recorrido dfs
//O(n^2)
template<class T>
void Graph<T>::dfsR(T vertex, vector<bool> &status){
    int pos = findVertex(vertex);
    if(!status[pos]){//si el estatus es false en la posicion
        cout << vertex << " ";
        status[pos] = true;
        for(auto adj: adjList[pos]){
            int posAd = findVertex(adj.vertex);
            !status[posAd] ? dfsR(adj.vertex, status) : void();
        }
    }

}


//calcula el edge con menor peso
template<class T>
int Graph<T>::minWeight(vector<int> weight, vector<bool> status){
    int min = INT_MAX; //valor maximo posible
    int pos = -1;
    for(int i = 0; i < vertices.size(); i++){
        if(!status[i]){//si el estatus es negativo
            if(min > weight[i]){//compara el valor contra maximo contra el peso
                pos = i;
                min = weight[i];
            }
        }
    }
    return pos;
}

//bfs
//funcion para el recorrido bfs
//O(n^2)
template<class T>
void Graph<T>::bfs(){
    vector<bool> status(vertices.size(),false);
    queue<T> q;
    //agregar el primer vertice a la fila
    q.push(vertices[0]);
    status[0] = true;
    while (!q.empty()){
        T vertex = q.front();
        cout<<vertex<<" ";
        int pos = findVertex(vertex);
        for(auto adj: adjList[pos]){
            pos = findVertex(adj);
            if(!status[pos]){
                q.push(adj);
                status[pos] = true;
            }
        }        
        q.pop();
    }
    cout<<endl;
}


//dfs
//funcion para el recorrido dfs
//O(n)
template<class T>
void Graph<T>::dfs(){
    vector<bool> status(vertices.size(), false);
    dfsR(vertices[0], status);
    cout<<endl;
}

//bfsPrint
//imprime el primer elemento a partir del vertice (input) en recorrido
//bfs
//O(n^2)
template<class T>
void Graph<T>::bfsPrint(T vertex){
    vector<bool> status(vertices.size(), false);
    queue<T> q;
    int pos = findVertex(vertex);
    if(pos >= 0){
        q.push(vertices[pos]);
        status[pos] = true;
        while (!q.empty()) {
            T vertex = q.front();
            cout << vertex << " ";
            pos = findVertex(vertex);
            for(auto adj : adjList[pos]){
                pos = findVertex(adj.vertex);
                if(!status[pos]){
                    q.push(adj.vertex);
                    status[pos] = true;
                }
            }
            q.pop();
        }
        cout << endl;
    }
}

//bfs
//imprime el primer elemento a partir del vertice (input) en recorrido bfs
//O(n^2)
template<class T>
void Graph<T>::dfsPrint(T vertex){
    int pos = findVertex(vertex);
    if(pos >= 0){
        vector<bool> status(vertices.size(), false);
        dfsR(vertices[pos], status);
        cout << endl;
    }
    
}

//shortestPath
//imprime el peso a partir del camino del vertice dado
//O(n^2)
template<class T>
void Graph<T>::shortestPath(T vertex){
    int pos = findVertex(vertex);
    if(pos >= 0){
        vector<bool> status(vertices.size(), false);
        vector<int> weight(vertices.size(), INT_MAX);
        vector<int> path(vertices.size(), -1);
        weight[pos] = 0;
        int next = pos;
        while(next >= 0){
            status[next] = true;
            for(int i = 0; i < adjList[next].size(); i++){
                int posAd = findVertex(adjList[next][i].vertex);
                if(!status[posAd]){
                    if(weight[posAd] > (weight[next] + adjList[next][i].weight)){
                        weight[posAd] = weight[next] + adjList[next][i].weight;
                        path[posAd] = next;
                    }
                }
            }
            next = minWeight(weight, status);
        }
        
        for(int i = 0; i < vertices.size(); i++){
            stack<int> s;
            s.push(i);
            int p = path[i];
            while(p >= 0){
                s.push(p);
                p = path[p];
            }
            int times = int(20 - s.size()*2);
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
            for(int j = 0; j < times; j++){
                cout << ".";
            }
            cout << "Weight: " << weight[i] << "\n";
        }
    }
}

//topologicalSortR
//ordena los vertices en orden topologico
//O(n)
template<class T>
void Graph<T>::topologicalSortR(int n, vector<bool> &status, stack<int> &s){
    status[n] = true;
    int pos = findVertex(vertices[n]);
    for(int i  = 0; i < adjList[pos].size(); i++){
        int posAd =  findVertex(adjList[pos][i].vertex);
        if(!status[posAd]){
            topologicalSortR(posAd, status, s);
        }
    }
    s.push(vertices[n]);
}

//hace el ordenamiento, se mueve por status y regresa
//un stack con los valores
//O(n)
template<class T>
void Graph<T>::topologicalSort(){
    vector<bool> status(vertices.size(), false);
    stack<int> s;
    for(int i = 0; i < vertices.size(); i++){
        if(!status[i]){
            topologicalSortR(i, status, s);
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

//isBipartiteR
//checa que los vertices adyacentes de un vertice(input)
//sean colored o no y verifica si son similares
//O(n)
template<class T>
bool Graph<T>::isBipartiteR(int n, vector<int> &colors, int color){
    if(colors[n] != 0){
        return colors[n] == color;
    } else{
        colors[n] = color;
        for(int i = 0; i < adjList[n].size(); i++){
            if(!isBipartiteR(findVertex(adjList[n][i].vertex), colors, -color)){
                return false;
            }
        }
    }
    return true;
}

//isBipartite
//checa si es bipartite para cada vertice
//O(n)
template<class T>
bool Graph<T>::isBipartite(){
    vector<int> colors(vertices.size(), 0);
    for(int i = 0; i < vertices.size(); i++){
        if(colors[i] == 0 && !isBipartiteR(i, colors, 1)){
            return false;
        }
    }
    return true;
}

//print
//imprime el grafo como lista de adyacencias de cada vertice
//o(n)
template<class T>
void Graph<T>::print(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i] << " --> ";
        for(auto edge: adjList[i]){
            cout << "[" <<  edge.vertex << "|" << edge.weight << "] ";
        }
        cout << endl;
    }
}


