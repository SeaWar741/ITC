#include <bits/stdc++.h>
using namespace std;
 
int N, R;
int pos[1010];
 
int main() {
  scanf("%d%d", &N, &R);
  for(int i = 0; i < N; i ++)
    scanf("%d", &pos[i]);
   
  vector<int> T;

  
  int st = -1;
  for(int i = N - 1; i >= 0; i --) {
    if(pos[i] == 1 && i < R) {
      st = i;
      break;
    }
  }
   
  if(st == -1) {
    cout<<"-1"<<endl;
    return 0;
  }
   
  if(N - st <= R) {
    cout<<"1"<<endl;
    return 0;
  }
   
  T.push_back(st);
   
  while(true) {
    bool flag = false;
    for(int i = N - 1; i >= st + 1; i --) {
      if(i - st + 1 <= 2 * R && pos[i]) {
        st = i;
        flag = true;
        break;
      }
    }
    if(!flag) {
      break;
    }
     
    T.push_back(st);
     
    if(N - st <= R) {
      cout<<T.size()<<endl;
      return 0;
    }
  }
   
  cout<<"-1"<<endl;
   
  return 0;
}