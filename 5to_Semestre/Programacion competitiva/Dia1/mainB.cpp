#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	int a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		a-=x;
	}

	int suma=a+b;
	if(suma<y){
		cout<<"NO"<<endl;
		return 0;
	}
	else suma-=y;
	suma+=c;

	if(suma<z){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}