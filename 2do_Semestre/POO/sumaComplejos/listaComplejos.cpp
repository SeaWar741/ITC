#include <iostream>
#include <fstream>
#include <iostream>

#include"Complejo.h"
using namespace std;

int main(){
    ifstream file;
    file.open("numerosComplejos.txt");
    Complejo listcomplex[20];

    int real,imag,lines;
    lines = 0;
    int i=0;
    while (file>>real>>imag){
        Complejo newComplex(real,imag);
        listcomplex[i] = newComplex;
        cout<<newComplex.getReal()<<" + "<<newComplex.getImagi()<<"i"<<endl;
        i++;
    }
    lines =i;
    file.close();
    Complejo total;
    for (int i = 0; i < lines; i++){
        total =total.suma(listcomplex[i]);
    }
    cout<<"Suma: "<<total.getReal()<<" + "<<total.getImagi()<<"i"<<endl;
}
