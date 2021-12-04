//Actividad Hill Climbing
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <math.h>
#include <vector>
 
#define N 4 // number of board n4
#define N2 8 // number of board n8

using namespace std;
 
//function to configure the board and states randomly
//input: board, state
//output: none
//complexity:O(n)
void configureBoard(int board[][N],int* state){
 
    // Seed for random number generator
    srand(time(0));
    for (int i = 0; i < N; i++) {
        state[i] = rand() % N; // Randomly assign a state to each cell
        
        board[state[i]][i] = 1; // Assign a 1 to the cell (queen)
    }
}


//function to print the board
//input: board
//output: board in configuration
//complexity:O(n**2)
void printBoard(int board[][N]){
 
    for (int i = 0; i < N; i++) {
        cout << "{ ";
        for (int j = 0; j < N; j++) {
            if(j == N-1)
                cout << board[i][j] << " }" << endl;
            else
                cout << board[i][j] << ",";
        }
        cout << "\n";
    }
}
 
//function to print the state of the element
//input: state
//output: state of the element
//complexity:O(n)
void printState(int* state){
    for (int i = 0; i < N; i++) {
        cout << " " << state[i] << " ";
    }
    cout << endl;
}

//function to compare the state of the element, if they are equal return true
//input: state1, state2
//output: true or false
//complexity:O(n)
bool compareStates(int* state1,int* state2){
    for (int i = 0; i < N; i++) {
        if (state1[i] != state2[i]) {
            return false;
        }
    }
    return true;
}
 
//function to apply values to the board
//input: board, value
//output: none
//complexity:O(n**2)
void applyValues(int board[][N], int value){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = value;
        }
    }
}
 
//function to calculate the objective value of the state (if there is a queen attacking each other)
//input: board
//output: objective value
//complexity:O(n)
int calculateObjective(int board[][N],int* state){

    int attacking = 0; // Number of queens attacking each other
 
    int row, col;
 
    for (int i = 0; i < N; i++) {

        //The queen is placed at row 'state[i]'. To the 
        //left of the queen, we check if there is a queen
        row = state[i], col = i - 1;

        while (col >= 0 && board[row][col] != 1) {
            col--;
        }
        if (col >= 0 && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the right 
        row = state[i], col = i + 1;
        while (col < N
               && board[row][col] != 1) {
            col++;
        }
        if (col < N
            && board[row][col] == 1) {
            attacking++;
        }
 
        //check if there is a queen to the left up
        row = state[i] - 1, col = i - 1;
        while (col >= 0 && row >= 0
               && board[row][col] != 1) {
            col--;
            row--;
        }
        if (col >= 0 && row >= 0
            && board[row][col] == 1) {
            attacking++;
        }
 
        //check if there is a queen to the right down
        row = state[i] + 1, col = i + 1;
        while (col < N && row < N
               && board[row][col] != 1) {
            col++;
            row++;
        }
        if (col < N && row < N
            && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the left down
        row = state[i] + 1, col = i - 1;
        while (col >= 0 && row < N
               && board[row][col] != 1) {
            col--;
            row++;
        }
        if (col >= 0 && row < N
            && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the right up
        row = state[i] - 1, col = i + 1;
        while (col < N && row >= 0
               && board[row][col] != 1) {
            col++;
            row--;
        }
        if (col < N && row >= 0
            && board[row][col] == 1) {
            attacking++;
        }
    }
 
    // Return pairs.
    return (int)(attacking / 2);
}
 
//function to generate the board configuration
//input: board, state
//output: none
//complexity:O(n)
void generateBoard(int board[][N],int* state){
    applyValues(board, 0);
    for (int i = 0; i < N; i++) {
        board[state[i]][i] = 1;
    }
}
 
//function to copy the state
//input: state1, state2
//output: none
//complexity:O(n)
void copyState(int* state1, int* state2){
    for (int i = 0; i < N; i++) {
        state1[i] = state2[i];
    }
}
 

//function to get the neighour of the current state
//input: board, state, currentState
//output: neighbour state
//complexity:O(n**2)
void getNeighbour(int board[][N],int* state){
 
    int opBoard[N][N];
    int opState[N];
 
    copyState(opState,state); // Copy the current state to the optimal state
    generateBoard(opBoard,opState); // Generate the optimal board
 
    int opObjective = calculateObjective(opBoard,opState); // Calculate the objective value of the optimal board
 
    int NeighbourBoard[N][N];
    int NeighbourState[N];
 
    copyState(NeighbourState,state);
    generateBoard(NeighbourBoard,NeighbourState);
 
    for (int i = 0; i < N; i++) { // Iterating through all possible neighbours
        for (int j = 0; j < N; j++) {
 
            // Condition for skipping the
            // current state
 
            if (j != state[i]) { 
 
                NeighbourState[i] = j;//Initializing the neighbour state with the current state
                NeighbourBoard[NeighbourState[i]][i] = 1;
                NeighbourBoard[state[i]][i]= 0;
 
                int temp = calculateObjective(NeighbourBoard,NeighbourState); //calculating the objective value of the neighbour
 
                if (temp <= opObjective) { //Comparing temporary and optimal neighbour objectives, if less than optimal then update
                    opObjective = temp;
                    copyState(opState,NeighbourState);
                    generateBoard(opBoard,opState);
                }
 
                NeighbourBoard[NeighbourState[i]][i] = 0; // Reset the neighbour board for the next iteration
                NeighbourState[i] = state[i];
                NeighbourBoard[state[i]][i] = 1;
            }
        }
    }

    copyState(state, opState); // Copy the optimal state to the current state
    applyValues(board, 0);
    generateBoard(board, state);
}


//function to get the best state
//input: board, state
//output: none
//complexity:O(NN)
void hillClimbing(int board[][N],int* state){
    int neighbourBoard[N][N] = {};
    int neighbourState[N];
 
    copyState(neighbourState, state);
    generateBoard(neighbourBoard,neighbourState);
 
    do { 
        copyState(state, neighbourState); //copy the neighbour state to the current state (neighbour becomes current after the jump)
        generateBoard(board, state);
 
        getNeighbour(neighbourBoard,neighbourState); //get optimal neighbour
 
        if (compareStates(state,neighbourState)) { //if neihgbour and current are equal then no optimal neighbour exists
            printBoard(board);
            break;
        }
        else if (calculateObjective(board,state)== calculateObjective(neighbourBoard,neighbourState)) {
            //If neighbour and current are not equal then we aproach a shoulder local optimum. 
            //jump to random neighbour to get a better local optimum
 
            // Random neighbour
            neighbourState[rand() % N] = rand() % N;
            generateBoard(neighbourBoard,neighbourState);
        }
 
    } while (true);
}


//----------------------------------------------------------------------------------------------------------------------

//para n=8


//function to configure the board and states randomly
//input: board, state
//output: none
//complexity:O(n)
void configureBoard2(int board[][N2],int* state){
 
    // Seed for random number generator
    srand(time(0));
    for (int i = 0; i < N2; i++) {
        state[i] = rand() % N2; // Randomly assign a state to each cell
        
        board[state[i]][i] = 1; // Assign a 1 to the cell (queen)
    }
}


//function to print the board
//input: board
//output: board in configuration
//complexity:O(n**2)
void printBoard2(int board[][N2]){
 
    for (int i = 0; i < N2; i++) {
        cout << "{ ";
        for (int j = 0; j < N2; j++) {
            if(j == N2-1)
                cout << board[i][j] << " }" << endl;
            else
                cout << board[i][j] << ",";
        }
        cout << "\n";
    }
}
 
//function to print the state of the element
//input: state
//output: state of the element
//complexity:O(n)
void printState2(int* state){
    for (int i = 0; i < N2; i++) {
        cout << " " << state[i] << " ";
    }
    cout << endl;
}

//function to compare the state of the element, if they are equal return true
//input: state1, state2
//output: true or false
//complexity:O(n)
bool compareStates2(int* state1,int* state2){
    for (int i = 0; i < N2; i++) {
        if (state1[i] != state2[i]) {
            return false;
        }
    }
    return true;
}
 
//function to apply values to the board
//input: board, value
//output: none
//complexity:O(n**2)
void applyValues2(int board[][N2], int value){
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            board[i][j] = value;
        }
    }
}
 
//function to calculate the objective value of the state (if there is a queen attacking each other)
//input: board
//output: objective value
//complexity:O(n)
int calculateObjective2(int board[][N2],int* state){

    int attacking = 0; // Number of queens attacking each other
 
    int row, col;
 
    for (int i = 0; i < N2; i++) {

        //The queen is placed at row 'state[i]'. To the 
        //left of the queen, we check if there is a queen
        row = state[i], col = i - 1;

        while (col >= 0 && board[row][col] != 1) {
            col--;
        }
        if (col >= 0 && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the right 
        row = state[i], col = i + 1;
        while (col < N2
               && board[row][col] != 1) {
            col++;
        }
        if (col < N2
            && board[row][col] == 1) {
            attacking++;
        }
 
        //check if there is a queen to the left up
        row = state[i] - 1, col = i - 1;
        while (col >= 0 && row >= 0
               && board[row][col] != 1) {
            col--;
            row--;
        }
        if (col >= 0 && row >= 0
            && board[row][col] == 1) {
            attacking++;
        }
 
        //check if there is a queen to the right down
        row = state[i] + 1, col = i + 1;
        while (col < N2 && row < N2
               && board[row][col] != 1) {
            col++;
            row++;
        }
        if (col < N2 && row < N2
            && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the left down
        row = state[i] + 1, col = i - 1;
        while (col >= 0 && row < N2
               && board[row][col] != 1) {
            col--;
            row++;
        }
        if (col >= 0 && row < N2
            && board[row][col] == 1) {
            attacking++;
        }

        //check if there is a queen to the right up
        row = state[i] - 1, col = i + 1;
        while (col < N2 && row >= 0
               && board[row][col] != 1) {
            col++;
            row--;
        }
        if (col < N2 && row >= 0
            && board[row][col] == 1) {
            attacking++;
        }
    }
 
    // Return pairs.
    return (int)(attacking / 2);
}
 
//function to generate the board configuration
//input: board, state
//output: none
//complexity:O(n)
void generateBoard2(int board[][N2],int* state){
    applyValues2(board, 0);
    for (int i = 0; i < N2; i++) {
        board[state[i]][i] = 1;
    }
}
 
//function to copy the state
//input: state1, state2
//output: none
//complexity:O(n)
void copyState2(int* state1, int* state2){
    for (int i = 0; i < N2; i++) {
        state1[i] = state2[i];
    }
}
 

//function to get the neighour of the current state
//input: board, state, currentState
//output: neighbour state
//complexity:O(n**2)
void getNeighbour2(int board[][N2],int* state){
 
    int opBoard[N2][N2];
    int opState[N2];
 
    copyState2(opState,state); // Copy the current state to the optimal state
    generateBoard2(opBoard,opState); // Generate the optimal board
 
    int opObjective = calculateObjective2(opBoard,opState); // Calculate the objective value of the optimal board
 
    int NeighbourBoard[N2][N2];
    int NeighbourState[N2];
 
    copyState2(NeighbourState,state);
    generateBoard2(NeighbourBoard,NeighbourState);
 
    for (int i = 0; i < N2; i++) { // Iterating through all possible neighbours
        for (int j = 0; j < N2; j++) {
 
            // Condition for skipping the
            // current state
 
            if (j != state[i]) { 
 
                NeighbourState[i] = j;//Initializing the neighbour state with the current state
                NeighbourBoard[NeighbourState[i]][i] = 1;
                NeighbourBoard[state[i]][i]= 0;
 
                int temp = calculateObjective2(NeighbourBoard,NeighbourState); //calculating the objective value of the neighbour
 
                if (temp <= opObjective) { //Comparing temporary and optimal neighbour objectives, if less than optimal then update
                    opObjective = temp;
                    copyState2(opState,NeighbourState);
                    generateBoard2(opBoard,opState);
                }
 
                NeighbourBoard[NeighbourState[i]][i] = 0; // Reset the neighbour board for the next iteration
                NeighbourState[i] = state[i];
                NeighbourBoard[state[i]][i] = 1;
            }
        }
    }

    copyState2(state, opState); // Copy the optimal state to the current state
    applyValues2(board, 0);
    generateBoard2(board, state);
}


//function to get the best state
//input: board, state
//output: none
//complexity:O(NN)
void hillClimbing2(int board[][N2],int* state){
    int neighbourBoard[N2][N2] = {};
    int neighbourState[N2];
 
    copyState2(neighbourState, state);
    generateBoard2(neighbourBoard,neighbourState);
 
    do { 
        copyState2(state, neighbourState); //copy the neighbour state to the current state (neighbour becomes current after the jump)
        generateBoard2(board, state);
 
        getNeighbour2(neighbourBoard,neighbourState); //get optimal neighbour
 
        if (compareStates2(state,neighbourState)) { //if neihgbour and current are equal then no optimal neighbour exists
            printBoard2(board);
            break;
        }
        else if (calculateObjective2(board,state)== calculateObjective2(neighbourBoard,neighbourState)) {
            //If neighbour and current are not equal then we aproach a shoulder local optimum. 
            //jump to random neighbour to get a better local optimum
 
            // Random neighbour
            neighbourState[rand() % N2] = rand() % N2;
            generateBoard2(neighbourBoard,neighbourState);
        }
 
    } while (true);
}


int main(){

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Solucion Hill Climbing\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    //input n  
    int n;
    cout<<"Ingrese el numero: ";
    cin>>n;
    cout<<endl;

    if(n == 4){

        int state[N] = {};
        int board[N][N] = {};


        configureBoard(board, state); //start configuration
        hillClimbing(board, state); //Hill climbing on the board obtained

    }
    else if (n == 8){
        int state2[N2] = {};
        int board2[N2][N2] = {};

        configureBoard2(board2, state2); //start configuration
        hillClimbing2(board2, state2); //Hill climbing on the board obtained
    }
    else{
        cout<<endl;
        cout<<"Invalid board size"<<endl;
    }
 
    return 0;
}