//Programacion con algoritmos avaros
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666

#include<iostream>
#include<vector>
using namespace std;

//Funcion Merge
//funcion para hacer el sorting y juntar los doubleervalos
void Merge(vector<int>& lista, int s, int m, int e) {
	
    //La lista temporal guarda los valores obtenidos por el merge
	vector<int> listaTemporal;
	int i = s;
	int j = m + 1;
    
    //itera haciendo comparaciones en los elementos y reordenandolos en 
    //la lista temporal
	while (i <= m && j <= e) {
		if (lista[i] <= lista[j]) {
			listaTemporal.push_back(lista[i]);
			++i;
		}
		else {
			listaTemporal.push_back(lista[j]);
			++j;
		}

	}
	while (i <= m) {
		listaTemporal.push_back(lista[i]);
		++i;
	}
	while (j <= e) {
		listaTemporal.push_back(lista[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		lista[i] = listaTemporal[i - s];

}

//Funcion MergeSort
//Hace el sorting del vector  
//Complejidad O(n*Log n)
void MergeSort(vector<int>& lista, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(lista, s, m);
		MergeSort(lista, m + 1, e);
		Merge(lista, s, m, e);
	}
}

//Funcion calculate
//Calcula la cantidad de monedas necesarias de cada valor para sumar el cambio
//Complejidad O(n)
void calculate(int num, vector<int> monedas, vector<int> &monedasUtilizadas){
	int acum = 0, i = monedas.size()-1, rem = num, count = 0;
	while(acum < num && i >= 0){
		count = rem / monedas[i];
		rem = rem % monedas[i];
		monedasUtilizadas[i] = count;
		acum = count * monedas[i];
		i--;
	}
}

int main() {

	int n, p, q;
	vector<int> monedas;

    cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

    cout<<"Programación dinámica y algoritmos avaros"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

	cout << "\nIngresa el numero de monedas disponibles >";cin >> n; cout<<endl;
	monedas = vector<int>(n);
	vector<int> monedasUtilizadas(n, 0);
	cout << "Ingresa el valor de cada moneda (uno por linea) >"; cout<<endl;
	for (int i = 0; i < n; ++i) {
		cin >> monedas[i];
	}
	MergeSort(monedas, 0, n - 1);

	cout << "Ingresa el precio del producto";  cin >>  p; cout << endl;
	cout << "Ingresa el billete o moneda con el que se paga dicho producto";  cin >>  q; cout << endl;

	cout << endl;

	calculate(q-p, monedas, monedasUtilizadas);

	for (int i = 0; i < monedasUtilizadas.size(); i++) cout << monedasUtilizadas[i] << " ";

	cout<<endl<<endl;

}