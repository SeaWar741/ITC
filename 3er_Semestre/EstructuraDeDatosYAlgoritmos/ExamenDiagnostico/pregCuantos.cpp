// Matricula: A01652138 
// Nombre:  Juan Carlos Garfias Tovar
#include <iostream>

using namespace std;

// Complejidad: O(n)
int cuantos(int inf, int sup){
    // aquí va tu código
    int total = 0;
    for (int i = inf; i < sup; i++){ //se itera del inferior al superior en
        //incrementos de 1
        /* code */
        if(i %3 == 0 && i%5 ==0){ //si es divisible se suma
            total++;
        }
    }
    return total;
    
}

int main(){
	int inf, sup;
	cin >> inf >> sup;
	cout << cuantos(inf, sup) << endl;
}