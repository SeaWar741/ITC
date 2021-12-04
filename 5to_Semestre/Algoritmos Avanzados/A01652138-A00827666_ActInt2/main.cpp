//Actividad Integradora 2
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

//Function to find the shortest path for a given graph based on permutations
//Input: Graph, distances, n
//Output: Shortest path
//O(n^2)
void findShortestPath(vector< vector<int> > &permutations, vector< vector<int> > distancias, int n){
    int min = INT_MAX;
    int min_index = 0;
    for(int i = 0; i < permutations.size(); i++){ //evaluates all permutations
        int sum = 0;
        for(int j = 0; j < permutations[i].size()-1; j++)
            sum += distancias[permutations[i][j]][permutations[i][j+1]];
        
        if(sum < min){
            min = sum;
            min_index = i;
        }
    }
    cout << "El camino mas corto es de: " << min << endl;
    char albet[26];

    for (int ch = 'A'; ch <= 'Z'; ch++) //changes the numbers to letters
        albet[ch - 'A'] = ch;
    
    vector<char> path;
    for(int i = 0; i < permutations[min_index].size(); i++)
        cout << albet[permutations[min_index][i]] << (i != permutations[min_index].size() - 1 ? " -> " : ""); //prints the path
    
    cout << endl;
}


//Function to find the shortest path for a graph using Dijkstra algorithm
//Input: adjacency matrix of the graph, source vertex
//Output: vector of the shortest path from source to all other vertices
//Complexity: O(V^2)
void dijkstra(vector< vector<int> > &graph, int source, int n, vector<string> &paths){
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    dist[source] = 0;
    for(int i = 0; i < n; i++){ //runs n times
        int u = -1;
        for(int v = 0; v < n; v++){
            if(!visited[v] && (u == -1 || dist[v] < dist[u])) //finds the vertex with the minimum distance
                u = v;
        }
        if(dist[u] == INT_MAX) //if there is no path to any vertex
            break;
        visited[u] = true;
        for(int v = 0; v < n; v++){ //updates the distances
            if(!visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }


    char albet[26];

    for (int ch = 'A'; ch <= 'Z'; ch++)
        albet[ch - 'A'] = ch;
    

    for(int i = 0; i < n; i++){
        int parnode = parent[i];
        int son = i;
        string path = "";
        while(parnode != -1){
            path = "(" + string(1,albet[parnode]) + "," + string(1,albet[son]) + ")"; //creates the path
            if(find(paths.begin(), paths.end(), path) == paths.end())
                paths.push_back(path);
            son = parnode;
            parnode = parent[parnode];
        }
        
    }
}


//Function to check If we find a connection to the sink node using breadth first search
//Input: graph, source, sink, n, temporary parent vector
//Output:Returns true if the graph is connected, false otherwise.
//Complexity: O(V)
bool bfs(vector< vector<int> > &rGraph, int s, int t,int n, vector<int> &parent){
    // Create a visited array and mark all vertices as not
    // visited
    vector<bool> visited(rGraph[0].size(),false);
 
    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < rGraph[0].size(); v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}
 

//Function to find the maximum flow from s to t in a graph
//Input: capacity graph, source, sink, temporary parent vector and number of vertices
//Output: Returns the maximum flow from s to t in the given graph
//Complexity: O( ∣ E ∣ ⋅ f ∗ )
int fordFulkerson(vector< vector<int> > &graph, int s, int t, vector<int> &parent,int n){
    int u, v;

    int V = n;
 
    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
   vector< vector<int> > rGraph(V, vector<int>(V, 0));

    // Add all the edges one by one to the residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 

    int max_flow = 0; // There is no flow initially
 
    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, s, t, V, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}




int  main(){
    int n;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Actividad Integradora 2\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el numero de puntos> ";
    cin >> n;

    cin.ignore();
    
    vector< vector<int> > distancias(n, vector<int>(n, 0));
    vector< vector<int> > capacidades(n, vector<int>(n, 0));
    
    //Fill the matrix with the distances
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> distancias[i][j];

    cin.ignore();
    
    //Fill the matrix with the capacities
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> capacidades[i][j];
    
    cin.ignore();
    

    string input;
    vector< vector<int> > coordinates(n, vector<int>(2, 0));
    
    for(int i = 0; i < n; i++){
        cin >> input;
        input.pop_back();
        input.erase(0, 1);
        int pos = input.find(",");
        string coord1 = input.substr(0, pos);
        coordinates[i][0] = stoi(coord1);
        input.erase(0, pos + 1);
        coordinates[i][1] = stoi(input);
        input.clear();
    }

    cout <<endl<< "----------------------------------------------------------------------------------------\n";


    //PUNTO 1
    vector<string> paths;
    for(int i = 0; i < n; i++){
        dijkstra(distancias, i, n, paths);
    }

    //print pahts
    sort(paths.begin(), paths.end());
    cout << "Forma de cablear las colonias: \n";
    for(int i = 0; i < paths.size(); i++)
        cout << paths[i] << endl;
    
    cout << "\n\n";
    
    //PUNTO 2
    vector<int> numbers(n, 0);
    vector< vector<int> > permutations;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
        numbers[i] = i;

    do{
        if(numbers[0] == 0){ //case 0
            vector<int> aux = numbers;
            aux.push_back(0); //add 0 to the end to complete connection
            permutations.push_back(aux);
            aux.clear();
        }
    } while (next_permutation(numbers.begin(), numbers.end())); //permutations are created while possible


    findShortestPath(permutations, distancias, n); //find the shortest path overall


    //PUNTO 3
    vector<int> parent(n, -1); //parent vector for BFS

    int maxFlow = fordFulkerson(capacidades, 0, n-1, parent,n);  //implement Ford Fulkerson for path with max flow
    
    cout << endl << "El flujo maximo es: " << maxFlow << endl;

    return 0;
}