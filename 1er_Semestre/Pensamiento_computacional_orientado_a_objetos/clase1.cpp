#include <iostream>
#include<math.h>
using namespace std;

int main(){
    float a,b,c,s,area;
    cout<<"Calcular el area de un truangulo a partir de 3 lados"<<endl;

    cout<<"lado1:";cin>>a;
    cout<<"lado2:";cin>>b;
    cout<<"lado3:";cin>>c;

    s = (a+b+c)/2.0;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"El area es: "<<area<<endl;
    return 0;
}