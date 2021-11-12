//Actividad 3.3 Implementación de "Knapsack problem"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

//function to solve knapsack problem using dynamic programming and bottom-up approach
//input: peso máximo, vector de pesos, vector de valores, número de elementos
//output: valor máximo posible
//O(NM)
int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
    //table to store results of subproblems
    int K[n + 1][W + 1];

    //building table K[][] in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][W];
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