#include<bits/stdc++.h>

using namespace std;

int maximumLength(vector<int> arr,int n){
    int max = 1, tempMax = 1;

    for (int i = 1; i < n; i++){
        //checar si el elemento actual es mayor
        //al elemento anterior
        if(arr[i]>arr[i-1]){
            tempMax++;
        }
        else{
            //checar si el max es menor al length
            //del subarray actual
            //establece el valor en max
            if(max<tempMax){
                max = tempMax;
            }
            //se resetea tempMax
            tempMax = 1;
        }
    }

    //compara el lenght del ultimo 
    //subarray con el maximo
    if(max< tempMax){
        max = tempMax;
    }

    return max;
}

int main() {
	int n;
    cin>>n;
    vector<int> arry(n);
    for (auto i = 0; i < n; i++){
        /* code */
        cin >> arry[i];
    }
    
    cout<<maximumLength(arry,n)<<endl;

	return 0;
}