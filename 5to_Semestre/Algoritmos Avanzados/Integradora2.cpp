//Actividad Integradora 2
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;


void findShortestPath(vector< vector<int> > &permutations, vector< vector<int> > distancias, int n){
    int min = 1000000;
    int min_index = 0;
    for(int i = 0; i < permutations.size(); i++){
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

    for (int ch = 'A'; ch <= 'Z'; ch++)
        albet[ch - 'A'] = ch;
    
    vector<char> path;
    for(int i = 0; i < permutations[min_index].size(); i++)
        cout << albet[permutations[min_index][i]] << (i != permutations[min_index].size() - 1 ? " -> " : "");
    
    cout << endl;
}

//Display elements of the array
/* void display(vector<int> a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
} */

//Edmonds-Karp algorithm
int edmondsKarp(vector< vector<int> > &permutations, vector< vector<int> > &distancias, int n){
    int max_flow = 0;
    int s = 0;
    int t = n-1;
    while(true){
        vector<int> parent(n, -1);
        vector<int> flow(n, 0);
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < permutations[u].size(); i++){
                int v = permutations[u][i];
                if(distancias[u][v] > 0 && visited[v] == 0){
                    parent[v] = u;
                    flow[v] = min(flow[u], distancias[u][v]);
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        if(parent[t] == -1)
            break;
        max_flow += flow[t];
        int v = t;
        while(v != s){
            int u = parent[v];
            distancias[u][v] -= flow[t];
            distancias[v][u] += flow[t];
            v = u;
        }
    }
    return max_flow;
}


//function to find the shortest path for a graph using Dijkstra algorithm
void dijkstra(vector< vector<int> > &graph, int source, int n, vector<string> &paths){
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    dist[source] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        for(int v = 0; v < n; v++){
            if(!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }
        if(dist[u] == INT_MAX)
            break;
        visited[u] = true;
        for(int v = 0; v < n; v++){
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
            path = "(" + string(1,albet[parnode]) + "," + string(1,albet[son]) + ")";
            if(find(paths.begin(), paths.end(), path) == paths.end())
                paths.push_back(path);
            son = parnode;
            parnode = parent[parnode];
        }
        
    }
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
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> distancias[i][j];

    cin.ignore();
    
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


    vector<string> paths;
    for(int i = 0; i < n; i++){
        dijkstra(distancias, i, n, paths);
    }

    cout << "----------------------------------------------------------------------------------------\n";
    //print pahts
    sort(paths.begin(), paths.end());
    cout << "Forma de cablear las colonias: \n";
    for(int i = 0; i < paths.size(); i++)
        cout << paths[i] << endl;
    
    cout << "\n\n";

    vector<int> numbers(n, 0);
    vector< vector<int> > permutations;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
        numbers[i] = i;

    do{
        if(numbers[0] == 0){
            vector<int> aux = numbers;
            aux.push_back(0);
            permutations.push_back(aux);
            aux.clear();
        }
    } while (next_permutation(numbers.begin(), numbers.end()));


    findShortestPath(permutations, distancias, n);

    return 0;
}