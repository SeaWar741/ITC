#include<bits/stdc++.h>

using namespace std;

int t;
string s;
int a[100005];
int times, num;

int main(){
    cin>>t;
    while (t--){
        cin>>s;

        times = 0;
        num =0;

        for (int  i = 0; i < s.size(); i++){   
            /* code */
            if(s[i]=='o' && s[i+1] == 'n' && s[i+2]=='e'){
                times++;
                a[num++] = i+2;
                i = i+2;
            }else if (s[i]=='t' && s[i+1] == 'w' && s[i+2]=='o'){
                if(s[i+3]=='n' && s[i+4] =='e'){
                    times++;
                    a[num++]=i+3;
                    i=i+4;
                }else{
                    times++;
                    a[num++] = i+2;
                    i=i+2;
                }

            }
        }
        cout<<times<<endl;

        for (int i = 0; i < num; i++){
            /* code */
            cout<<a[i];
            if(i!=num-1){
                cout<<" ";
            }
        }
        cout<<endl;   
    }

    return 0;
}
