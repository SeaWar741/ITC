#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, length,hops = 0;
    string data;
    cin>>n>>length>>data;

    int position = 1;

    while(position<n){
        int i = min(n-1,position+length-1); //valor minimo comun

        while (data[i]=='0'){
            /* code */
            i--; //si salta 0 se acaba
        }
        if(i+1==position){
            cout<< -1 <<endl;
            return 0;
        }
        position = i+1; //se actualiza la posicion de la rana
        hops++; //crece el numero de saltos

    }

    cout<<hops<<endl;

	return 0;
}