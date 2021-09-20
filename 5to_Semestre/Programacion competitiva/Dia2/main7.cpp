#include <iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>

using namespace std;

const int infinite = 1e9+7;
const int maxNumber=3e5+10;
const int mod=998244353;

long long int primes[maxNumber]; //primos
pair<int,int> p[maxNumber]; //pares
map<pair<int,int>,int>mp1; //numero de repeticiones

map<int,int> x;
map<int,int> y;

bool orderX(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first != b.first)
        return a.first < b.first;
    else    
        return a.second < b.second;
}


int main(){
    int n;
    cin>>n;

    x.clear();
    y.clear();
    mp1.clear();

    primes[0] = 1;

    for(auto i = 1; i<=n; i++){
        cin>>p[i].first>>p[i].second;
        primes[i]=primes[i-1]*i%mod; //almacenando factorial
        x[p[i].first]++;
        y[p[i].second]++;
        mp1[p[i]]++; //guardando repeticiones

    }

    sort(p+1,p+n+1,orderX);//clasificacion

    long long int flag= 1;

    for(int i=2;i<=n;i++){
        if(!(p[i-1].first<=p[i].first&&p[i-1].second<=p[i].second)){
            flag = 0; //no es compatible
            break;
        }
    }

    long long int result = 0;

    if(flag==1){ //aumento de x,y a la vez
        for(auto it=mp1.begin();it!=mp1.end();it++)
            flag=flag*primes[it->second]%mod;
        result=mod-flag;//duplicados restados
    }

    long long int res = 1;

    for(auto it=x.begin();it!=x.end();it++)//incrementar x
        res=res*primes[it->second]%mod;
    result = (result+res)%mod;

    res=1;

    for(auto it=y.begin();it!=y.end();it++)// incrementar y
        res=res*primes[it->second]%mod;
    result=(result+res)%mod;

    result=(primes[n]-result+mod)%mod;
    //se obtienen todas las permutaciones menos todos
    //los incrementos 


     cout<<result<<endl;


    return 0;
}
