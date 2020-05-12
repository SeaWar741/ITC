#include <iostream>
using namespace std;

class Fraccion{
private:
    int numerador,denominador;
public:
    Fraccion(int numeradori,int denominadori);
    Fraccion();

    void setNumerador(int numeradori);
    void setDenominador(int denominadori);

    int getNumerador();
    int getDenominador();

    void simplificar();
    void muestra();

    Fraccion suma(Fraccion f2);
    Fraccion multiplica(Fraccion f2);
};

Fraccion::Fraccion(){
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int numeradori,int denominadori){
    if(numeradori<0&&denominadori<0){
        numerador = -numeradori;
        denominador = -denominadori;
    }
    else if (numeradori>0&&denominadori<0){
        numerador = -numeradori;
        denominador = -denominadori;
    }
    else{
        numerador = numeradori;
        denominador = denominadori;
    }
    simplificar();
}

void Fraccion::setNumerador(int numeradori){
    numerador = numeradori;
}
void Fraccion::setDenominador(int denominadori){
    denominador = denominadori;
}
int Fraccion::getNumerador(){
    return numerador;
}
int Fraccion::getDenominador(){
    return denominador;
}

void Fraccion::simplificar(){
    int divisor;
    if(numerador>denominador){
        divisor = denominador;
    }else{
        divisor = numerador;
    }
    while(divisor>1){
        if(numerador % divisor == 0 && denominador %divisor==0){
            numerador/=divisor;
            denominador/=divisor;
        }
        divisor--;
    }
}

void Fraccion::muestra(){
    cout<<numerador<<"/"<<denominador<<endl;
}

Fraccion Fraccion::suma(Fraccion f2){
    int num = numerador * f2.denominador + f2.numerador * denominador;
	int den  = denominador * f2.denominador;
	Fraccion result(num,den);
    result.simplificar();
    return result;
}
Fraccion Fraccion::multiplica(Fraccion f2){
    int num = numerador*f2.numerador;
    int den = denominador*f2.denominador;
    Fraccion result(num,den);
    result.simplificar();
    return result;
}
