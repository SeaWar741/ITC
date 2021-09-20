#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkNumber(int n){
    unordered_set<int> numbers;
    int i = 1;
    while (1){
        int x = i *(i+1)/2;
        if(x >= n)
            break;
        numbers.insert(x);
        i++;
    }
    for(auto itr : numbers)
        if(numbers.find(n-itr) != numbers.end())
            return true;
    return false;
}

int main(){
    int number;
    cin>>number;
    bool evaluation = checkNumber(number);
    if(evaluation){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
