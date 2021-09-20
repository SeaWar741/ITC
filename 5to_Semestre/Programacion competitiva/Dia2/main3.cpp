#include <iostream>
using namespace std;

int main(){
    int t,l,r;
    cin>>t;

    while(t--){
        cin>>l>>r;
        int lsum,rsum;
        if (l & 1) lsum = l/2 ;
        else lsum = l/2 - l ;
        if (r & 1) rsum = r/2 - r;
        else rsum = r/2 ;
        cout << rsum - lsum << endl ;   
    }
    
    return 0;
}
