//Actividad 1.3 Implementación de la técnica de programación "backtracking" y "ramificación y poda"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m; // col and rows of matrix

void printSol(int solArray[][100]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) cout << solArray[i][j] << " ";
		cout << "\n";
	}
}

//funcion: backtrackingUtil
//Analiza las posibles casillas por las cuales se podría llegar a la solución y eventualmente determina las correctas
//Complejidad O(n^2)
bool backtrackingUtil(int matrix[][100], int l, int r, int solArray[][100]){
	if(l == n -1 && r == m - 1){
		solArray[l][r] = 1; 
		return true; // found solution
	}

	solArray[l][r] = 1; // agregar casilla a solución
	
	//move right
	if(r < n -1) if(matrix[l][r+1] == 1 && solArray[l][r+1] != 1) if(backtrackingUtil(matrix, l, r + 1, solArray)) return true;
		
	//move down
	if(l < m -1) if(matrix[l+1][r] == 1 && solArray[l+1][r] != 1) if(backtrackingUtil(matrix, l + 1, r, solArray)) return true;

	//move left
	if(r > 0) if(matrix[l][r-1] == 1 && solArray[l][r-1] != 1) if(backtrackingUtil(matrix, l, r - 1, solArray)) return true;

	//move up
	if(l > 0) if(matrix[l-1][r] == 1 && solArray[l-1][r] != 1) if(backtrackingUtil(matrix, l - 1, r, solArray)) return true;
		
	solArray[l][r] = 0; // quitar casilla de solución
	return false;

}

void backtracking(int matrix[][100]){
	int solArray[m][100];
	for (int i = 0; i < m; ++i) for(int j = 0; j < n; j++) solArray[i][j] = 0;

	if(backtrackingUtil(matrix, 0, 0, solArray)) printSol(solArray); else cout << "N hay solución..\n";
}



struct Position{
	int first;
	int second;
	Position(int f, int s)      
    {      
        first = f;      
        second = s;      
	}
	Position()      
    {      
        first = 0;      
        second = 0;      
	}
	void print(){
		cout<<"("<<first<<","<<second<<")"<<endl;
	}
};  


void rampoda2(int matrix[][100]){
	//Prepare an empty queue and an empty 2D array
	queue<Position> dataQueue;
	queue<Position> path;
	int a[m][100];

	Position temporal(0,0);

			
	for (int i = 0; i < m; i++){//Start at the upper left corner and push the position to queue
		for(int j = 0; j < n; j++){
		
			temporal.first = i;
			temporal.second = j; 

			dataQueue.push(temporal);
		}
	}

	
	cout<<endl;

	//=============================================
	queue<Position> dataQueue2 = dataQueue;
	for (int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
		
			cout << matrix[i][j] << "(" << dataQueue2.front().first <<","<< dataQueue2.front().second << ") ";
			dataQueue2.pop();
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	//=============================================

	/*
	Position pos;

	int i = 0;
	int j = 0;


	while (i != (m-1) && j != (n-1)){
		a[i][j] = 1;
		
		if(a[i][j+1] == 1){
			temporal.first = i;
			temporal.second = j;
			path.push(temporal);
			j++;
		}
		if(a[i+1][j] == 1){
			temporal.first = i;
			temporal.second = j;
			path.push(temporal);
			i++;
		}
		if(a[i][j-1] == 1){
			temporal.first = i;
			temporal.second = j;
			path.push(temporal);
			j--;
		}
		if(a[i-1][j] == 1){
			temporal.first = i;
			temporal.second = j;
			path.push(temporal);
			i--;
		}
		path.pop();
	}
	*/
	

	
	Position pos  = dataQueue.front();
	path.push(pos);
	//dataQueue.pop();


	while(!dataQueue.empty()){
		
		pos  = dataQueue.front();
		dataQueue.pop();

		temporal.first = pos.first;
		temporal.second = pos.second;
		
		matrix[pos.first][pos.second] = 0;

		

		cout << "current:  ";
		temporal.print();
		//check adkacent cells whose value is zero and push to queue
		//arriba
		if(matrix[pos.first -1][pos.second] == 1){
			temporal.first = pos.first-1;
			temporal.second = pos.second;
			cout << "pushing:  ";
			temporal.print();
			
			path.push(temporal);
			//i--;
		}	

		//derecha
		if(matrix[pos.first][pos.second +1] == 1){
			temporal.first = pos.first;
			temporal.second = pos.second +1;
			cout << "pushing:  ";
			temporal.print();
			path.push(temporal);
			//j++;
		}		

		//abajo
		if(matrix[pos.first + 1][pos.second] == 1){
			temporal.first = pos.first +1;
			temporal.second = pos.second;
			cout << "pushing  ";
			temporal.print();
			path.push(temporal);
			//i++;
		}
		//izquierda
		if(matrix[pos.first][pos.second -1] == 1){
			temporal.first = pos.first;
			temporal.second = pos.second -1;
			cout << "pushing  ";
			temporal.print();
			path.push(temporal);
			//j--;
		}
		
		//path.pop();

	}
	
	

	//pruebas


	cout<<endl;
	cout<<"Posiciones validas para el path (Encontrar el shortest path)"<<endl;
	while(!path.empty()){
		cout<<" " <<path.front().first<<","<<path.front().second<<endl;
		path.pop();
	}
	cout<<endl;

	
}



void rampoda(int laberinto[][100]){
    int fila = 0;
    int columna = 0;
    string camino;
    string caminoActual;
    queue<int> queueMain;
    queue<string> queue2;
    queueMain.push(fila);
    queueMain.push(columna);
    queue2.push("0,0");

    while(fila < m-1 || columna < n-1){
        fila = queueMain.front();
        queueMain.pop();
        columna = queueMain.front();
        queueMain.pop();

        caminoActual = queue2.front();
        camino = caminoActual;
        queue2.pop();

        if(columna + 1 < n && laberinto[fila][columna+1] == 1){ // Derecha
            queueMain.push(fila);
            queueMain.push(columna+1);

            camino = caminoActual + " " + to_string(fila) + "," + to_string(columna+1);
            queue2.push(camino);
        }
        if(fila + 1 < m && laberinto[fila+1][columna] == 1){ // Abajo
            queueMain.push(fila+1);
            queueMain.push(columna);

            camino = caminoActual + " " + to_string(fila+1) + "," + to_string(columna);
            queue2.push(camino);
        }

        if(columna-1 >= 0 && laberinto[fila][columna-1] == 1){ // Izquierda
            queueMain.push(fila);
            queueMain.push(columna-1);

            camino = caminoActual + " " + to_string(fila) + "," + to_string(columna-1);
            queue2.push(camino);
        }

        if(fila-1 >= 0 && laberinto[fila-1][columna] == 1){ // Arriba
            queueMain.push(fila-1);
            queueMain.push(columna);

            camino = caminoActual + " " + to_string(fila-1) + "," + to_string(columna);
            queue2.push(camino);
        }

        laberinto[fila][columna] = 0;
    }
    
    vector<vector<int>> path;
    for(int i=0; i<m; i++){
        path.push_back(vector<int>());
        for(int j=0; j<n; j++){
            path[i].push_back(0);
        }
    }

    int aux = 0;
    string str = "";
    fila = 0;
    columna = 0;
    while(fila < m-1 || columna < n-1){
        while(camino[aux] != ','){
            str = str + camino[aux];
            aux++;
        }
        fila = stoi(str);
        str = "";
        aux++;
        while(camino[aux] != ' '){
            str = str + camino[aux];
            aux++;
        }
        columna = stoi(str);
        str = "";
        aux++;
        path[fila][columna] = 1;
        camino.erase(0,aux-1);
        aux = 0;
    }
    cout << "Solucion Branch and Bound: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Programacion 'backtracking' y 'ramificacion poda'\n";
    cout<<"----------------------------------------------------------------------------------------\n";

	cout << "\nIngresa el numero filas >";cin >> m; cout << "\n";
	cout << "\nIngresa el numero columnas >";cin >> n; cout<< "\n";
	cout << "Ingresa la fila del tablero (casilla por casilla separado por espacio) >"; cout << "\n";
	
	int matrix[m][100];
	for (int i = 0; i < m; ++i) for(int j = 0; j < n; j++) cin >> matrix[i][j];
	cout << "\n";

	cout << "backtracking: \n";
	backtracking(matrix);

	cout << "\n\nramificacion y poda: \n";
	rampoda(matrix);

	cout<<"\n\n";

}