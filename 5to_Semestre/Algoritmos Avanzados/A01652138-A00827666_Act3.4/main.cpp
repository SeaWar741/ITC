//Actividad 3.4 Implementación de "Graph coloring"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool safe(int v, vector< vector<bool> > graph, vector<int> colors, int c){
    for(int i = 0; i < graph[0].size(); i++) if (graph[v][i] && c == colors[i]) return false;
    return true;
}
 
bool graphColoringUtil(vector< vector<bool> > graph, int m, vector<int> &colors, int v){
    if (v == graph[0].size()) return true;
 
    for(int i = 1; i <= m; i++){
        if (safe(v, graph, colors, i)){
            colors[v] = i;
 
            if (graphColoringUtil(graph, m, colors, v + 1) == true) return true;
 
            colors[v] = 0;
        }
    }
    return false;
}

void printSolution(vector<int> colors){
    cout << "Solución: \n";
    for (int i = 0; i < colors.size(); i++) cout << "Node: " << i << ", Assigned Color: " << (colors[i]-1) << "\n";
    cout << "\n";
}

void graphColoring(vector< vector<bool> > graph, int m){
    vector<int> colors(graph[0].size(), 0);
 
    if(!graphColoringUtil(graph, m, colors, 0)) {
        cout << "No hay solucion";
     } else {
        printSolution(colors);
     }
}

int main(){
	int n, num;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación de Graph coloring\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout<<"Ingresa el valor de n: >\n"; cin >> n;
    vector< vector<bool> > graph(n, vector<bool>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            graph[i][j] = num == 1;
        }    
    }



    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }    
        cout << "\n";
    }

    int m = 3;
    graphColoring(graph, m);
    
    return(0);
}