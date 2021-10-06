#include<bits/stdc++.h>
using namespace std;

#define INF 99999

//djikstra
//input: matriz y size de la matriz
//output: distancias mas cortas del nodo a los otros
//O(V^2)
void djikstra(vector<vector<int>> mat, int n){
    for(int src=0;src<n;src++){ //itera sobre todos los nodos
        int count = 1;
        
        int path[n];
        for(int i=0;i<n;i++)
            path[i] = mat[src][i];
        
        int visited[n] = {0};
        visited[src] = 1;
        
        while(count<n)
        {
            int minNode;
            int minVal = INF;
            
            for(int i=0;i<n;i++)
                if(visited[i] == 0 && path[i]<minVal)
                {
                    minVal = path[i];
                    minNode = i;
                }
            
            visited[minNode] = 1;
            
            for(int i=0;i<n;i++)
                if(visited[i] == 0)
                    path[i] = min(path[i],minVal+mat[minNode][i]);
                        
            count++;
        }
        
        path[src] = 0;
        for(int i=0;i<n;i++)
            if(i !=src){
                cout<<"node "<<src+1<<" to node "<<i+1<<" -> "<<path[i]<<endl;
            }
    }    
}


//printSolution
//input: matriz y size de la matriz
//output: Matriz de distancias mas cortas
//funcion complementaria para imprimir
//O(n^2)
void printSolution(vector<vector<int>> dist,int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

//floydWarshall
//input: matriz y size de la matriz
//output: Matriz de distancias mas cortas
//O(V^3)
void floydWarshall(vector<vector<int>> graph, int n){

    int i, j, k;

    vector<vector<int>> dist(n, vector<int>(n, 0));
 

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
 

    for (k = 0; k < n; k++) {
        // toma los nodos como source uno por uno
        for (i = 0; i < n; i++) {
            //toma todos los vertices como destino
            for (j = 0; j < n; j++) {
                //si el vertice es en la ruta mas corta de i a j 
                //hace un update
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    printSolution(dist,n);
}
 



int main(){
	int n = 4;

    vector<vector<int>> matrix = {   {0, 2, INF, 3},
                        {INF, 0, 1, 5},
                        {2, 3, 0, INF},
                        {3, INF, 4, 0}
                    };


	djikstra(matrix,n);

    cout<<endl;
    
    floydWarshall(matrix,n);

	
	return(0);
}