#include <iostream>

using namespace std; 


int fibonacciRecursivo(int n){//esta mal, ahorita lo arreglo
    if(n <=2){
        return 1;
    }
    else{
        return ( fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2));
    }
}


int main() {
  for(int n = 1; n<=6;n++){
    cout<<"F("<<n<<")="<<fibonacciRecursivo(n)<<endl;
  }
}