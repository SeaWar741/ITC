//Actividad 3.3 Implementación de "Knapsack problem"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

//knapsack
//input: peso máximo, vector de pesos, vector de valores, número de elementos
//output: valor máximo posible
//O(NM)
int knapsack(int m, vector<int> weights, vector<int> values, int n){
    vector< vector<int> > matrix(n+1, vector<int>(m+1,0));

    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            //if j es menor al peso en i se asigna el valor de arriba
            //else se asigna el valor máximo entre dos valores
            matrix[i][j] = (j < weights[i]) ? matrix[i - 1][j] : max(matrix[i - 1][j - weights[i]] + values[i], matrix[i - 1][j]);
        }
    }

    return matrix[n][m];
}


int main(){
	int n, m;
    string str;

    
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación de Knapsack problem\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout<<"Ingresa el valor de n: >\n"; cin >> n;
    vector<int> values;
    vector<int> weights;
    values.push_back(0);
    weights.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> str;
        values.push_back(stoi(str.substr(0,1)));
        weights.push_back(stoi(str.substr(2,1)));
    }

	cout<<"Ingresa el valor máximo: >\n"; cin >> m;
    cout << "\n\nResultado: " << knapsack(m, weights, values, n) << "\n";

	return(0);
}