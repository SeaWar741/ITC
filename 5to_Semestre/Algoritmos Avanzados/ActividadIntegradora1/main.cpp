//Actividad Integradora 1
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;


//funcion calculateLines
//input pos, num, length
//output positions
//regresa el inicial y el final
//o(1)
vector<short> calculateLines(short pos, short  num, int length){
    //return initial and final
    short initialPos = (pos - num) % length + 1;
    short finalPos = pos % length;
    short finalLine = pos / length + (finalPos > 0 ? 1 : 0);
    short initialLine = (pos-num) / length + (initialPos > 0 ? 1 : 0);
    vector<short> positions;
    positions.push_back(initialLine); 
    positions.push_back(initialPos);
    positions.push_back(finalLine);
    positions.push_back(finalPos);
    
    
    return positions;
}

//funcion isIntersection
//input arr1, code
//toma los valores de los strings y encuentra los comunes
//O(m+n)
void isIntersection(vector<string> arr1, string code){
    string trans;
    int j = 0, i;
    for (i = 0; i < arr1.size(); i++) trans += arr1[i];
    for (i = 0; i < trans.size(); i++) {
        while(trans[i+j] == code[j] && j < code.size()) j++;
        if(j == code.size()) break;
        j = 0;
    }
    
    if(j == code.size()){
        vector<short> pos = calculateLines(i+j, j, arr1[0].size());
        cout << "True" << " (línea: " << pos[0] << " pos: " << pos[1] << ")\n";
    } else {
        cout << "False\n";
    }
}
 
//funcion longestPalSubstr
//input string
//regresa el palindromo substring mas largo
//O(n^2)
vector<int> longestPalSubstr(string str){
    // get length of input string
    int n = str.size();
 
    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
 
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1;
 
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    //printSubStr(str, start, start + maxLength - 1);
 
    // return length of LPS
    //vector<int> result = {start, start + maxLength - 1,maxLength};
    //vector<int> result{ start, start + maxLength - 1, maxLength};
    vector<int> result;
    result.push_back(start);
    result.push_back(start + maxLength - 1);
    result.push_back(maxLength);

    return result;
}


//Funcion findLongestPalindrome
//input array
//itera sobre el array(lineas) y busca el palindromo 
//mas largo 
//O(n)
void findLongestPalindrome(vector<string> arry){

    int longest =0;
    int posI = 0;
    int posF = 0;
    int linea = 0;

    for (int i = 0; i < arry.size(); i++){
        vector<int> temp = longestPalSubstr(arry[i]);
        int tempLongest  = temp[2];
        if(tempLongest > longest){
            longest = tempLongest;
            posI = temp[0];
            posF = temp[1];
            linea = i;
        }
    }

    cout<<"Inicial: "<<posI<<" Final: "<<posF<<" Linea: "<<(linea+1)<<" Longitud: "<<longest<<endl;
}

//Funcion longestCommonSubstringAux
//input: string a, string b
//toma los valores y regresalas posiciones iniciales, finales y el size
//O(nm)
vector<short> longestCommonSubstringAux(string &a, string &b) {
    if (a.size() < b.size()) return longestCommonSubstringAux(b, a);
    
    vector<short> results(4,0);
    vector< vector<short> > m(a.size(), vector<short>(b.size(), 0));
    
    for (auto i = 1; i < a.size(); ++i){
        for (auto j = 1; j < b.size(); ++j){
            if(a[i-1] == b[j-1]){
                m[i][j] = m[i-1][j-1] + 1;
                if(results[0] < m[i][j]){
                    results[0] = m[i][j];
                    results[1] = i;
                    results[2] = j;
                }
                
            }
        }
    }
    if(a.size() < b.size()) results[3] = 1;
    return results; //esto deberia de regresar  [pos inicial, final y el size]
}



//Funcion longestCommonSubstring
//input: arry1, arry2
//toma los valores e imprime los datos del  longestCommonSubstring
//o(1)
void longestCommonSubstring(vector<string> arry1, vector<string> arry2){
    
    string text1, text2;
    for (int i = 0; i < arry1.size(); i++) text1 += arry1[i];
    for (int i = 0; i < arry2.size(); i++) text2 += arry2[i];

    vector<short> results = longestCommonSubstringAux(text1, text2);

    //calculate lines and pos
    vector<short> pos1 = calculateLines(results[1], results[0], arry1[0].size()), pos2 = calculateLines(results[2], results[0], arry2[0].size());
    cout << "\nLongitud: " << results[0] << "\n";
    cout << "\nFile1\n";
    cout << "Posición inicial: " << "linea: " << pos1[0] << " posición: " << pos1[1] << "\n";
    cout << "Posición final: " << "linea: " << pos1[2] << " posición: " << pos1[3] << "\n";
    cout << "\nFile2\n";
    cout << "Posición inicial: " << "linea: " << pos2[0] << " posición: " << pos2[1] << "\n";
    cout << "Posición final: " << "linea: " << pos2[2] << " posición: " << pos2[3] << "\n";
    //cout << "char1: " << text1[results[1]] << " char2: " << text2[results[2]] << " Longest Common Substring: " << results[0] << " inicial: " << results[1] << " final: " << results[2] << "\n";
}


int main(){
    string myText;
    string filename1 = "transmission"; 
    string filename2 = "mcode"; 
    vector< vector<string> > transmissions;
    vector< vector<string> > malicious;

    //itera sobre los archivos de lectura
    for (int i = 1; i <=2; i++){
        ifstream MyReadFile(filename1+to_string(i)+".txt");

        vector<string> temporalData;
        while (getline (MyReadFile, myText)) {
            if(!isxdigit(myText[myText.size()-1])) myText.pop_back();
            
            temporalData.push_back(myText);
        }

        transmissions.push_back(temporalData);

        MyReadFile.close();

    }

    //itera sobre los archivos malicious
    for (int i = 1; i <= 3; i++){
        ifstream MyReadFile(filename2+to_string(i)+".txt");

        vector<string> temporalData;


        while (getline (MyReadFile, myText)) temporalData.push_back(myText);

        malicious.push_back(temporalData);

        MyReadFile.close();

    }

    //Mensajes informativos

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Solucion Actividad Integradora 1\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<endl<<"Intersecciones conjuntos (estan contenidos)"<<endl;
    cout<<endl<<"File1"<<endl;
    isIntersection(transmissions[0], malicious[0][0]); //malicious1
    isIntersection(transmissions[0], malicious[1][0]); //malicious2
    isIntersection(transmissions[0], malicious[2][0]); //malicious3

    cout<<endl<<"File2"<<endl;
    isIntersection(transmissions[1], malicious[0][0]); //malicious1
    isIntersection(transmissions[1], malicious[1][0]); //malicious2
    isIntersection(transmissions[1], malicious[2][0]); //malicious3
    cout<<endl<<endl;

    cout<<"Longest Palindrome"<<endl;
    cout<<endl<<"File1"<<endl;
    findLongestPalindrome(transmissions[0]);
    cout<<endl<<"File2"<<endl;
    findLongestPalindrome(transmissions[1]);
    cout<<endl<<endl;

    cout<<"Longest common substring"<<endl;
    longestCommonSubstring(transmissions[0],transmissions[1]);
    
    cout<<endl<<endl;
    return 0;
}
