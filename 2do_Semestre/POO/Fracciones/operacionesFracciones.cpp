#include <iostream>
#include <fstream>
#include"Fraccion.h"

using namespace std;

int main(){
    ifstream file;
    file.open("operaciones.txt");
    Fraccion arryF[10];
    int i; //cantidad de datos en el arreglo de objetos
    int size;

    int oper,num1,den1,num2,den2;

    file>>size;
    i = 0;
    while (file>>oper>>num1>>den1>>num2>>den2){
        Fraccion f1(num1,den1);
        Fraccion f2(num2,den2);
        Fraccion f3;
        if(oper==1){
            f3 = f1.suma(f2);
        }else{
            f3 = f1.multiplica(f2);
        }
        arryF[i] = f3;
        i++;
    }
    file.close();
    for (int i = 0; i < size; i++){
        arryF[i].muestra();
    }
    return 0;
}
