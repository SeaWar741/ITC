//Actividad 5.3  N Quuens problem using Branch and Bound Algorithm
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result; // To store the list of results (positions of queens)

//function to get N queens
//input: chess (board), row (current row), cols (columns),ndiagonals and rdiagonals
void getNQueen(vector<vector<bool>>& chess, int row, bool*cols, bool* ndiag, bool* rdiag){
    if(row == chess.size()){ //checks if the row is the last row
        vector<int> qsf; //vector to store the positions of queens
        for(int i=0; i<chess.size(); i++){ //iterates through the rows
            for(int j=0; j<chess[0].size(); j++){
                if(chess[i][j] == 1)
                    qsf.push_back(j+1);//adds the position of the queen to the vector
            }
        }
        
        result.push_back(qsf); //adds the vector to the result vector
        
        return;
    }
    
    for(int col=0; col < chess[0].size(); col++){ //iterates through the columns
        if(cols[col]==false && ndiag[row+col] == false && rdiag[row-col+chess.size()-1] == false){ //checks if the column is available
            chess[row][col] = true;
            cols[col] = true;
            ndiag[row+col] = true;
            rdiag[row-col+chess.size()-1] = true;
            
            getNQueen(chess, row+1, cols, ndiag, rdiag); //recursive call to get the next row
            
            chess[row][col] = false;
            cols[col]=false;
            ndiag[row+col] = false;
            rdiag[row-col+chess.size()-1] = false;
        }
    }
}

//function to solve n queens problem
//input: n (board size)
//output: vector of vector of ints (positions for the queens (from 1 to n))
//complexity: O(n!)
vector<vector<int>> nQueen(int n) {
    vector<vector<bool>> chess(n, vector<bool>(n));
    
    bool* cols = new bool[n];
    bool* ndiag = new bool[2*n-1];
    bool* rdiag = new bool[2*n-1];
    for(int i=0; i<n; i++){
        cols[i] = false;
    }
    for(int j=0; j<2*n-1; j++){
        ndiag[j] = false;
    }
    for(int j=0; j<2*n-1; j++){
        rdiag[j] = false;
    }
    getNQueen(chess, 0, cols, ndiag, rdiag); //calls the function to get the positions of the queens
    return result;
}

//Function to drive solutions and print them
//input: n(size of the board) and allsolutions(to decide if they want to be shown)
//output: displays solutions for the n-queens puzzle or one
//complexity O(n)
void solveNQueens(int n, bool allSolutions = false){
    result.clear();
    nQueen(n);
    sort(result.begin(),result.end());
    
    if(allSolutions){
        for(int i = 0; i < result.size(); i++){
            vector<int> commonResult = result[i];

            //create a matrix of size n*n of 0s
            vector<vector<int>> matrix(n, vector<int>(n, 0));

            //fill the matrix with ones on the positions of the queens
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++){
                    if (commonResult[i] == j + 1){
                        matrix[i][j] = 1;
                    }
                }
            }

            //print the matrix
            for (int i = 0; i < n; i++) {
                cout << "{ ";
                for (int j = 0; j < n; j++){
                    if(j != n-1){
                        cout << matrix[i][j] << ", ";
                    }
                    else{
                        cout << matrix[i][j];
                    }
                }
                cout <<"}"<<endl;
            }
            cout<<endl;
        }
    }
    else{
        vector<int> commonResult = result[0];
        //create a matrix of size n*n of 0s
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        //fill the matrix with ones on the positions of the queens
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (commonResult[i] == j + 1) {
                    matrix[i][j] = 1;
                }
            }
        }

        //print the matrix
        for (int i = 0; i < n; i++) {
            cout << "{ ";
            for (int j = 0; j < n; j++) {
                if(j != n-1)
                    cout << matrix[i][j] << ", ";
                else
                    cout << matrix[i][j];
            }
            cout <<"}"<<endl;
        }
        cout<<endl;
    }
}

int main(){
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementacion N Quuens problem using Branch and Bound Algorithm\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el size del tablero (4 u 8)> ";

    // Board size
    int n;
    cin>>n;cout<<endl;

    if(n == 4 || n == 8)
        solveNQueens(n);
        //if you want all the solutions
        //solveNQueens(n, true);
    else
        cout<<"Invalid board size"<<endl;

    return 0;
}