#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[105];int cnt=0,i=0;bool flag=false;
    cin>>a;
    while(a[i]!='\0'){
        if(a[i]=='1'){while(a[i]=='1'){cnt++;i++;}}
        else{while(a[i]=='0'){cnt++;i++;}}
        if(cnt>=7){flag=true;break;}
        cnt=0;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}