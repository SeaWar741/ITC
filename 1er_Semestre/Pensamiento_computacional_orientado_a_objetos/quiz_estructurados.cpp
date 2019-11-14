#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int miArreglo[10];
    double datos[10];
    int arreglo1[10], arreglo2[10];
    for (int iR = 0; iR <= 9; iR++)
    {
        datos[iR]=iR * iR;
        cout<<iR<<endl;
    }
    
    return 0;
}

