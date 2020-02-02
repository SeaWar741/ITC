#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, c, acum = 0, suma = 0, nacum;
    cin >> f;
    int arr[f] = {}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    for (int i = 0; i < f; ++i) { 
        cin >> c;
        arr[i] = c;
    }
    sort(arr, arr+n, greater<int>());

    
    for (int i = 0; i < n; ++i) {
        acum += arr[i];
    }
    for(int j=0; j<f; j++){
            suma += arr[j];
            nacum = acum - suma;
            if(suma>nacum) {
                cout << j+1;
                return 0;
            }
    }
    return 0;
}