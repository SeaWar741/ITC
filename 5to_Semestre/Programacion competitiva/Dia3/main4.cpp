#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    string data;
    cin >> n >> k;
    cin >> data;

    vector<vector<int>> grid(n,vector<int> (k,0));

    for(auto j = 0; j<k; j++){
        grid[0][j] = 1;
    }

    grid[0][data[0]-'A'] = 0;

    for(auto i = 1; i<n; i++){
        for (auto j = 0; j < k; j++){
            /* code */
            int prev = INT_MAX;
            for(auto l=0; l<k;l++){
                if(l==j) continue;
                prev = min(prev,grid[i-1][l]);
            }
            grid[i][j] = data[i] - 'A' == j?prev:prev+1;
        }
        
    }

    int result = grid[n-1][0];
    int ind = 0;
    for(auto j=1;j<k;j++){
        if(grid[n-1][j]<result){
            result = grid[n-1][j];
            ind = j;
        }
    }

    string resultString;
    int i = n-1;
    resultString+=ind+'A';
    int j = ind;
    while (i>0){
        int prev = INT_MAX;
        int prev_ind = -1;
        for(int l=0; l<k; l++){
            if(l==j) continue;
            if(grid[i-1][l]<prev){
                prev = grid[i-1][l];
                prev_ind = l;
            }
        }
        resultString+=prev_ind+'A';
        j=prev_ind;
        i--;
    }

    reverse(resultString.begin(),resultString.end());
    cout<<result<<endl;
    cout<<resultString<<endl;
    

    return 0;
}
