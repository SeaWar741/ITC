#include <iostream>

using namespace std;

int valor[1002][1002];
char dir[1002][1002];
int visitado[1002][1002];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> valor[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> dir[i][j];
        }
    }
    int ganancia = 0;
    int pf = 1;
    int pc = 1;
    while(pf >= 1 && pf <= n && pc >= 1 && pc <= m){
        if(visitado[pf][pc] == 1){
            pf = pc = 0;
            ganancia += 100;
        }else{
            visitado[pf][pc] = 1;
            ganancia += valor[pf][pc];
            switch(dir[pf][pc]){
            case 'A':
                pf--;
                break;
            case 'D':
                pc++;
                break;
            case 'B':
                pf++;
                break;
            case 'I':
                pc--;
                break;
            }
        }
    }
    cout << ganancia << endl;
    return 0;
}
