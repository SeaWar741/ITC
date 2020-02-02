#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

Persona personas[5];

int main(){
    for (int i = 0; i < 5; i++){
        cout<<personas[i].display()<<endl;
    }
    cout<<"Cambiando cumples"<<endl;
    for (int i = 0; i < 5; i++){
        Cumpleanios cumple(30,12);
        personas[i].setCumpleanios(cumple);
    }
    for (int i = 0; i < 5; i++){
        cout<<personas[i].display()<<endl;
    }
    return 0;
}
