#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<vector<string>> vec){
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}

//O(m+n)
void isIntersection(vector<string> arr1, vector<string> arr2){
    set<string> hs;
    int counter = 0;
 
    // Insert the elements of arr1[] to set S
    for (int i = 0; i < arr1.size(); i++)
        hs.insert(arr1[i]);
 
    for (int i = 0; i < arr2.size(); i++)
 
        // If element is present in set then
        // push it to vector V
        if (hs.find(arr2[i]) != hs.end())
            //cout << arr2[i] << endl;
            counter++;
    if(counter>0){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
 
//O(n^2) En programacion dinamica tiene la misma complejidad
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
    vector<int> result = {start, start + maxLength - 1,maxLength};
    
    return result;
}


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

    cout<<"Inicial: "<<posI<<" Final:"<<posF<<" Linea: "<<linea<<" Longitud: "<<longest<<endl;
}

//O(nm)
int longestCommonSubstringAux(string &a, string &b) {
    if (a.size() < b.size()) return longestCommonSubstringAux(b, a);
    vector<vector<short>> m(2, vector<short>(b.size() + 1));
    for (auto i = 1; i <= a.size(); ++i){
        for (auto j = 1; j <= b.size(); ++j){
            if (a[i - 1] == b[j - 1]){
                m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
            }
            else{ 
                m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
            }
        }
    }
    /*
    //Esto es para ver la matriz, para la explicacion de como funciona:
    //https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)

    cout<<endl<<endl;
    for(auto i = 0;i<m.size();i++){
        for(auto j = 0;j<m[0].size();j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    return m[a.size() % 2][b.size()]; //esto deberia de regresar  [pos inicial, final y el size]
}

void longestCommonSubstring(vector<string> arry1, vector<string> arry2){
    int longest = 0;
    for (int i = 0; i < arry1.size(); i++){
        for (int j = 0; j < arry2.size(); j++){
            
            int temp = longestCommonSubstringAux(arry1[i],arry2[j]);
            if (temp>longest){
                longest = temp;
            }
        }
    }
    cout<<"Longest Common Substring: "<<longest<<endl;
}


int main(){
    string myText;
    string filename1 = "transmission"; 
    string filename2 = "mcode"; 
    vector<vector<string>> transmissions;
    vector<vector<string>> malicious;

    for (int i = 1; i <=2; i++){
        ifstream MyReadFile(filename1+to_string(i)+".txt");

        vector<string> temporalData;
        map<size_t,string> temporalMap;
        hash<string> hasher;


        while (getline (MyReadFile, myText)) {
            //cout << myText<<'\t'<<endl;

            temporalData.push_back(myText);
            //temporalMap.insert({hash,myText});

        }

        transmissions.push_back(temporalData);
        //transmissionsHashes.push_back(temporalMap);

        MyReadFile.close();

    }

    for (int i = 1; i <=3; i++){
        ifstream MyReadFile(filename2+to_string(i)+".txt");

        vector<string> temporalData;
        map<size_t,string> temporalMap;
        hash<string> hasher;


        while (getline (MyReadFile, myText)) {
            //cout << myText<<'\t'<<endl;

            temporalData.push_back(myText);
            //temporalMap.insert({hash,myText});

        }

        malicious.push_back(temporalData);
        //transmissionsHashes.push_back(temporalMap);

        MyReadFile.close();

    }
    cout<<endl<<"Intersecciones conjuntos (estan contenidos)"<<endl;
    cout<<endl<<"File1"<<endl;
    isIntersection(transmissions[0],malicious[0]); //malicious1
    isIntersection(transmissions[0],malicious[1]); //malicious2
    isIntersection(transmissions[0],malicious[2]); //malicious3

    cout<<endl<<"File2"<<endl;
    isIntersection(transmissions[1],malicious[0]); //malicious1
    isIntersection(transmissions[1],malicious[1]); //malicious2
    isIntersection(transmissions[1],malicious[2]); //malicious3
    cout<<endl<<endl;

    cout<<"Longest Palindrome"<<endl;
    cout<<endl<<"File1"<<endl;
    findLongestPalindrome(transmissions[0]);
    cout<<endl<<"File2"<<endl;
    findLongestPalindrome(transmissions[1]);
    cout<<endl<<endl;

    cout<<"Longest common substring"<<endl;
    //https://www.geeksforgeeks.org/suffix-tree-application-5-longest-common-substring-2/
    longestCommonSubstring(transmissions[0],transmissions[1]);
    
    cout<<endl<<endl;
    return 0;
}
