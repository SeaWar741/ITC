//Actividad 2.1 Implementación de "Hash string"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decToHexa(int n){
    int  i = 1, j, r;
    char hex[50];
    while (n != 0){
        r = n % 16;
        hex[i++] = r < 10 ? (r + 48) : (r + 55);
        n = n / 16;
    }
    string hexa;
    for (j = i; j > 0; j--) hexa += hex[j];
    return hexa.substr(1);
}


string getHash(int n, string txt){
    vector< vector<int> > table; //table
    vector<int> temp; //temp row
    
    //max is the number of positions in table, n * times rows needed
    int j = 0, i  = 0, max = n * (txt.size()/n) + (txt.size() % n != 0 ? n : 0), acum = 0;

    //create table
    for(i = 0; i < max; i++){
        if(i/n != j){
            //add and go to next row
            j++;
            table.push_back(temp);
            temp.clear();
        }
        //add row
        temp.push_back(i < txt.size() ? txt[i] : n);
    }
    //add final row
    table.push_back(temp);

    //print table
    cout << "\ntable..\n";
    for(i = 0; i < table.size(); i++){
        for(j = 0; j < table[i].size(); j++) cout << table[i][j] << " ";
        cout << "\n";
    }

    //vector for sums
    vector<int> sums(n, 0);

    //caculate sums
    for(int i = 0; i < n; i++){
        for(j = 0; j < table.size(); j++) acum += table[j][i];
        sums[i] = acum % 256;
        acum = 0;
    }

    //print sums
    cout << "\nsums and module..\n";
    for(j = 0; j < n; j++) cout << sums[j] << " ";
    
    //vector for hexadecimals
    vector<string> hexes;

    //calculate hexadecimals
    for(j = 0; j < n; j++) hexes.push_back(decToHexa(sums[j]));

    //print hexadecimals
    cout << "\nhexadecimals..\n";
    for(j = 0; j < n; j++) cout << hexes[j] << " ";

    //create hash key
    string hash;
    for(j = 0; j < n; j++) hash += hexes[j];
    return hash;
}


int main(){
    int n;
    string txt;

    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Programacion Hash String\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "\nIngresa n: >\n";
    cin >> n;
    cin.ignore();
    cout << "Ingrese el texto: \n";
    getline(cin, txt);
    
    string hash = getHash(n, txt);
    cout << "\n\nHash key: " << hash << "\n\n";

    return 0;
}
