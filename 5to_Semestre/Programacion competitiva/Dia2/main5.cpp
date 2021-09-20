#include <bits/stdc++.h>
using namespace std;

int n;
long long times = 0;

int main() {
  cin >> n;
  long long a;
  cin >> a;
  int ok = 1;
  while (a > 1 && a % 2 == 0){
    a = a / 2;
  }
  while (a > 1 && a % 3 == 0){
    a = a / 3;
  }
  times = a;
  for (int i=1;i<n;i++){
    long long b;
    cin >> b;
    if (!ok) continue;
    if (b % times != 0){
      ok = 0; continue;
    }
    else {
      b = b / times;
      while (b > 1 && b % 2 == 0){
        b = b / 2;
      }
      while (b > 1 && b % 3 == 0){
        b = b / 3;
      }
      if (b > 1){
        ok = 0; continue;
      }
    }
  }
  if (ok) cout << "Yes"<<endl;
  else cout << "No"<<endl;
  return 0;
}