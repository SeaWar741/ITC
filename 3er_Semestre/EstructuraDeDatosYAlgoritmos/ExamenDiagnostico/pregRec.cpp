// Matricula: A01652138
// Nombre: Juan Carlos Garfias Tovar
#include <iostream>

using namespace std;

// Complejidad: O(n)
int sumaRecursivaCuadrada(int n){
    // aquí va tu código
    if(n>0){
        return n*n+sumaRecursivaCuadrada(n-1); //se eleva al cuadrado y se hace llama a si misma para hacer el calculo de n-1
    }
    else{
        return n; //si n no es mayor a cero se regresa el valor de n
    }
}

int main(){
	int n;
	cin >> n;
	cout << sumaRecursivaCuadrada(n) << endl;
}