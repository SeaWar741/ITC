#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >>k;
    int r = n*2;
    int g = n*5;
    int b = n*8;
    int total = (r-1)/k+(g-1)/k+(b-1)/k+3;

    cout<<total<<endl;

    return 0;
}
