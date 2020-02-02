#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, count = 0, num = 0;
	
	cin >> n;

	while(pow(2,count) <= n){
		num = num + n/pow(2,count);
		count = count + 1;
	}

	cout << num;

	return 0;
}