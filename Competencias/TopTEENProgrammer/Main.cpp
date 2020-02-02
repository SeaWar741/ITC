#include <stdio.h>
#define TAM 1002
#define MOD 10000

int L; // valor máximo del arreglo, hasta 100,000,000
int N; // cantidad de inters, hasta 1,000
int M; // cantidad de queries, hasta 1,000
int inicio, fin; // inicio y fin de un par
int menor, mayor;
int inters[TAM][2];
int suma;

void leerinters() {
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &inicio, &fin);
		inters[i][0] = inicio;
		inters[i][1] = fin;
	}
}

int gaus(int n) {
   if ((n % 2) == 0)
       return (((n / 2) % MOD) * ((n + 1) % MOD)) % MOD;
   else
      return ((n % MOD) * ( ((n + 1) / 2) % MOD)) % MOD;  

}

void sumar(int query1, int query2, int inter1, int inter2) {
	// no se traslapa el intervalo con el query
	if (query1 > inter2) {
		return;
	}
	if (inter1 > query2) {
		return;
	}
	// inicio
	if (inter1 > query1) {
		menor = 0;
	}
	else {
		menor = query1 - inter1;
	}
	// fin
	if (inter2 < query2) {
		mayor = inter2 - inter1 + 1;
	}
	else {
		mayor = (inter2 - inter1 + 1) - (inter2 - query2);
	}
	// formula de gaus
	suma += gaus(mayor) - gaus(menor);
	suma %= MOD;
   if (suma < 0)
     suma += MOD;
}

void leerQuerries() {
	for (int i = 0; i < M; i++) {
		suma = 0;
		scanf("%d %d", &inicio, &fin);
		// sumarla aportacion de cada intervalo
		for (int j = 0; j < N; j++) {
			sumar(inicio, fin, inters[j][0], inters[j][1]);
		}
		printf("%d\n", suma);
	}
}

int main() {
	scanf("%d %d %d", &L, &N, &M);
	leerinters();
	leerQuerries();
	return 0;
}