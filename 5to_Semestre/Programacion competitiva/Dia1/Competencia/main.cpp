#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    char m[15]={'0','1','2','3','4','5','6','7','8','9'};

    while(t--){
        int minn=100000000;
        int ch=0;
        string data;
        cin>>data;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ch=0;
                int flag=1;
                for(int k=0;k<data.length();k++){
                    if(data[k]==m[i]&&flag==1){
                        flag=0;
                        if(i==j) ch++;
                    }
                    else if(data[k]==m[j]&&flag==0){
                        flag=1;
                        if(i==j) ch++;
                        else ch=ch+2;
                    }
                }
                int len=data.length();
                minn=min(minn,len-ch);
            }
        }
        cout<<minn<<endl;
    }
}