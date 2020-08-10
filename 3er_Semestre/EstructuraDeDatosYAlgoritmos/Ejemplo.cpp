#include <iostream>
#include<string>
#include<vector>

#include "Fraccion.h"

using namespace std;

//Template
template<class T>
T suma(T a, T b, T c){
    return a+b+c;
}

int sumaI(int a, int b, int c){
    return a+b+c;
}

double sumaD(double a, double b, double c){
    return a+b+c;
}

string sumaS(string a, string b, string c){
    return a+b+c;
}

Fraccion sumaF(Fraccion a, Fraccion b, Fraccion c){
    return a+b+c;
}

int main(){
    
    int a = 10;
    int b = 20;
    int c = 30;

    double ad = 10.33;
    double  bd = 20.33;
    double cd= 30.34;

    string as = "Hola ";
    string bs = "Crayola ";
    string cs = "Mi cajita de colores";

    Fraccion af = Fraccion(1,2);
    Fraccion bf = Fraccion(1,2);
    Fraccion cf = Fraccion(1,2);

    //int s = sumaI(a,b,c);
    //double sd = sumaD(ad,bd,cd);
    //string ss = sumaS(as,bs, cs);
    //Fraccion sf = sumaF(af,bf,cf);

    int s = suma(a,b,c);
    double sd = suma(ad,bd,cd);
    string ss = suma(as,bs, cs);
    Fraccion sf = suma(af,bf,cf);


    cout<<"Uso de funcion Template: "<<endl;
    cout<<"La suma de a+b+c = "<<s<<endl;
    cout<<"La suma de a+b+c = "<<sd<<endl;
    cout<<"La suma de a+b+c = "<<ss<<endl;
    cout<<"La suma de a+b+c = "<<ss<<endl;

    return 0;
}
