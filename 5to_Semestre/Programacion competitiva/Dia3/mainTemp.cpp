#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  vector< vector<int> >vec; 
  int n, m;
  cin >> n >> m;
  int arr[502][502];
  for(int i= 1; i <= n; i++){
    for(int j=1; j <= m; j++){
      cin >> arr[i][j];
    }
  }
  bool primeArr[100010];
  primeArr[1] = true;
  for(int s = 2; s<100010; s++){
    if(!primeArr[s]){
      for(int i = s+s; i <= 100010; i+=s){
        primeArr[i] = true;
      }
    }
  }
  int tmp[100015];
  for(int i = 100010; i>=0; i--){
    tmp[i] = (!primeArr[i]) ? 0 :  tmp[i + 1] + 1;
  }
  int res = INT_MAX;
  int min;
  for(int i= 1; i <= n; i++){
    min = 0;
    for(int j=1; j <= m; j++){
      min += tmp[arr[i][j]];
    }
    res = (min < res) ? min : res;
  }
  for(int i= 1; i <= m; i++){
    min = 0;
    for(int j=1; j <= n; j++){
      min += tmp[arr[j][i]];
    }
    res = (min < res) ? min : res;
  }
 
  cout << res;
 
}