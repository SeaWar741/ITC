#include<iostream>
#include<string>
using namespace std;

class Rectangulo{
private:
    double dLargo,dAncho;
public:
    Rectangulo();
    Rectangulo(double dLa,double dAn);
    
    double calcArea();
    string imprime();

    void setLargo(double dLa);
    void setAncho(double dAn);

    double getLargo();
    double getAncho();
};

Rectangulo::Rectangulo(){
    dLargo = 0;
    dAncho = 0;
}

Rectangulo::Rectangulo(double dLargo,double dAncho){
    this->dLargo = dLargo;
    this->dAncho = dAncho;
}

double Rectangulo::calcArea(){
    return dLargo*dAncho;
}

void Rectangulo::setLargo(double dLa){
    dLargo = dLa;
}

void Rectangulo::setAncho(double dAn){
    dAncho = dAn;
}

double Rectangulo::getLargo(){
    return dLargo;
}

double Rectangulo::getAncho(){
    return dAncho;
}

string Rectangulo::imprime(){
    return"El area del rectangulo largo X ancho: "+
    to_string(dLargo)+" X "+to_string(dAncho)+" = "+to_string(calcArea());
}