//Programacion dinamica
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666

#include<iostream>
#include<vector>
#include <limits.h>
#include "math.h"
using namespace std;


//Function insertionSort
//Ordena el arreglo
//Complejidad O(n^2)
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


//Funcion calculate
//Calcula la cantidad de monedas necesarias de cada valor para sumar el cambio
//Complejidad O(n)
void minCoins(int monedas[], int n, int num){
    int table[n][num+1];
	for(int i = 0; i < n; i++) table[i][0] = 0;

	for(int i = 0; i < 1; i++) for(int j = 1; j < num+1; j++) table[i][j] = monedas[i] <= j ? j/monedas[i] : 0;
		
	for(int i = 1; i < n; i++) for(int j = 1; j < num + 1; j++) table[i][j] = monedas[i] <= j ? min(abs(table[i - 1][j]), 1 + table[i][j - monedas[i]]) : table[i - 1][j];
		

	int min = INT_MAX;
	int l = 0, r = num, count = 0;
	for(int i = 0; i < n; i++){
		if(table[i][num] <= min){
			min = table[i][num];
			l = i;
		}
	}


	bool found = false;
	int coins[min];
	while(!found){
		if(table[l-1][r] < abs(table[l][r - monedas[l]])){
			l--;
		} else{
			r -= monedas[l];
			coins[count] = monedas[l];
			count++;
			if(r == 0){
				found = true;
			}
		}
	}


	for(int i = 0; i < n; i++){
		count = 0;
		for(int j = 0; j < min; j++) if(monedas[i] == coins[j]) count++;
		cout << monedas[i] << ": " << count << endl;
	}

}


int main() {

	int n, p, q;


    cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

    cout<<"Programación dinámica y algoritmos avaros"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

	cout << "\nIngresa el numero de monedas disponibles >";cin >> n; cout<<endl;
	int monedas[n];
	cout << "Ingresa el valor de cada moneda (uno por linea) >"; cout<<endl;
	for (int i = 0; i < n; ++i) {
		cin >> monedas[i];
	}
	insertionSort(monedas, n);

	cout << "Ingresa el precio del producto";  cin >>  p; cout << endl;
	cout << "Ingresa el billete o moneda con el que se paga dicho producto";  cin >>  q; cout << endl;

	cout << endl;

	minCoins(monedas, n, q-p);

	cout<<endl<<endl;

}