
#include <iostream>
#include <cmath>

using namespace std;


int bacteria2(int n, int current, int bacterias){
    if (current == 0) {
        if(current != n) {
            return bacteria2(n,current+1,1);
        }
        else{
            return 1;
        }
    }
    else{
         bacterias = round(bacterias +(bacterias*3.78)-(bacterias*2.34));
         if(current !=n){
             return bacteria2(n,current+1,bacterias);
         }
         else{
             return bacterias;
         }
    }
}

int main(){
    
    cout<<bacteria2(5,0,0)<<endl;

    return 0;
}
