#include <iostream>
#include <vector>

//#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count = 0, total = 0, sum = 0;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        total += nums[i];
    }

    // sort array
    int temp;
    for(int i = 0; i < n -1; i++){
        for(int k = 0; k < n-i-1; k++){
            if(nums[k+1] < nums[k]){
                temp = nums[k];
                nums[k] = nums[k+1];
                nums[k+1] = temp;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;


    int i = n-1;
    while(sum <= total/2){
        sum += nums[i];
        i--;
    }
    cout << (n - i - 1) << "\n";
    return 0;
}