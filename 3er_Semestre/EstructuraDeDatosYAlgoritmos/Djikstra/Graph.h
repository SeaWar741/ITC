//List = {{0,2,1},{0,3,7},{2,0,1},{2,1,1},{2,6,3},{1,2,1},{1,6,3},{1,5,4},{5,1,4},{5,6,4},{5,3,7},{3,0,7},{3,5,7},{3,7,1},{6,2,3},{6,1,3},{6,5,4},{6,4,6},{6,7,6},{7,6,6},{7,3,1},{4,6,6}};
#include stack;

class Graph
{
private:
    /* data */
    vector
    int minWeight(vector<int> weight,vector<bool>status);
public:
    Graph(/* args */);
    ~Graph();
};

Graph::Graph(/* args */){
}

Graph::~Graph(){
}

template<class T>
int Graph<T>::minWeight(vector<int>,vector<bool> status){
    int min = INT_MAX;
    int pos = -1;
    for(int v = 0; v<vertices.size();v++){
        if(!status[v]){
            if(min>weight[v]){
                pos = v;
                min = weight[v];
            }
        }
    }
    return pos;
}

template<class T>
void Graph<T>::shortestPath(T vertex){
    int pos= findVertex(vertex);
    if(pos >=0){
        vector<bool> status(vertices.size(),false);
        vector<int> weight(vertices.size(),INT_MAX);
        vector<int> path(vertices.size(),-1);
        stack<int> sp;
        weight[pos] = 0;
        int next = minWeight(weight,status);
        while(next >= 0){
            status[next]=true;
            for(int v=0;v<adjList[next].size();v++){
                int posAdj= findVertex(adjList[next][v].vertex)
                if(!status[posAdj]){
                    if(weight[posAdj]>weight[next]+adjList[next][v].weight){
                        weight[posAdj] = weight[next]+adjList[next][v].weight;
                        path[posAdj] = next;
                    }
                }
            }
            next = minWeight(weight,status);
        }

        for (int v = 0; v < vertices.size(); v++){
            sp.push(v);
            int p = path[v];
            while (p>=0){
                sp.push(p);
                p = path[p];
            }
            while (!sp.empty()){
                cout<<sp.top()<<" ";
                sp.pop();
            }
            cout<<"\t"<<weight[v]<<endl;

        }
        
    }
}