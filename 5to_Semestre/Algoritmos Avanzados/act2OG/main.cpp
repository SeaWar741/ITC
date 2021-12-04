//Actividad Integradora 2
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void findShortestPath(vector< vector<int> > &permutations, vector< vector<int> > distancias, int n){
    int min = 1000000;
    int min_index = 0;
    for(int i = 0; i < permutations.size(); i++){
        int sum = 0;
        for(int j = 0; j < permutations[i].size()-1; j++)
            sum += distancias[permutations[i][j]][permutations[i][j+1]];
        
        if(sum < min){
            min = sum;
            min_index = i;
        }
    }
    cout << "El camino mas corto es de: " << min << endl;
    char albet[26];

    for (int ch = 'A'; ch <= 'Z'; ch++)
        albet[ch - 'A'] = ch;
    
    vector<char> path;
    for(int i = 0; i < permutations[min_index].size(); i++)
        cout << albet[permutations[min_index][i]] << (i != permutations[min_index].size() - 1 ? " -> " : "");
    
    cout << endl;
}

int  main(){
    int n;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Actividad Integradora 2\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el numero de puntos> ";
    cin >> n;

    cin.ignore();
    
    vector< vector<int> > distancias(n, vector<int>(n, 0));
    vector< vector<int> > capacidades(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> distancias[i][j];

    cin.ignore();
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> capacidades[i][j];
    
    cin.ignore();
    
    string input;
    vector< vector<int> > coordinates(n, vector<int>(2, 0));
    
    for(int i = 0; i < n; i++){
        cin >> input;
        input.pop_back();
        input.erase(0, 1);
        int pos = input.find(",");
        string coord1 = input.substr(0, pos);
        coordinates[i][0] = stoi(coord1);
        input.erase(0, pos + 1);
        coordinates[i][1] = stoi(input);
        input.clear();
    }

    vector<int> numbers(n, 0);
    vector< vector<int> > permutations;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
        numbers[i] = i;

    do{
        if(numbers[0] == 0){
            vector<int> aux = numbers;
            aux.push_back(0);
            permutations.push_back(aux);
            aux.clear();
        }
    } while (next_permutation(numbers.begin(), numbers.end()));



    cout << "Numero de permutaciones: " << permutations.size() << endl;
    findShortestPath(permutations, distancias, n);

    return 0;
}