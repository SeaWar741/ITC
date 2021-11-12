//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666

#include<iostream>
#include<vector>
using namespace std;


//Funcion Merge
//funcion para hacer el sorting y juntar los doubleervalos
void Merge(vector<double>& lista, int s, int m, int e) {
	
    //La lista temporal guarda los valores obtenidos por el merge
	vector<double> listaTemporal;
	int i = s;
	int j = m + 1;
    
    //itera haciendo comparaciones en los elementos y reordenandolos en 
    //la lista temporal
	while (i <= m && j <= e) {
		if (lista[i] >= lista[j]) {
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
void MergeSort(vector<double>& lista, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(lista, s, m);
		MergeSort(lista, m + 1, e);
		Merge(lista, s, m, e);
	}
}

int main() {

	double n;
	vector<double> lista;

    cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

    cout<<"MERGE SORT ALGORITHM | DIVIDE Y VENCERAS"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

	cout << "\nIngresa el numero de elementos del arreglo >";cin >> n; cout<<endl;
	lista = vector<double>(n);
	cout << "Ingresa los elementos del arreglo (uno por linea):"; cout<<endl;
	for (double i = 0; i < n; ++i) {
		cin >> lista[i];
	}

	MergeSort(lista, 0, n - 1);

	cout << "\nArreglo ordenado: "<<endl;
	for (double i = 0; i < n; ++i) {
		cout << lista[i] << ' ';
	}
    cout<<endl<<endl;

}