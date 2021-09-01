#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int **p = new int*[n];
	for (int i = 0; i < n; i++){
		p[i] = new int[2];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			cin >> p[i][j];
		}
	}
	int games = 0;
	int j = 0;
	for (int i = 0; i < n; i++){
		j = 0;
		while (j < n){
			if (p[i][0] == p[j][1]) { 
                games++; 
            }
			if (j == i - 1 && i != n - 1) {
                j += 2; 
            }
			else{
                j++;
            }
		}
	}
	cout << games;
	return 0;
}
