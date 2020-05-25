#ifndef Sobre_h
#define Sobre_h
#include "Envio.h"
class Sobre: public Envio{
private:
    double largo,ancho,cargoAdicional;
public:
    Sobre();
    Sobre(Persona,Persona,double,double,double,double);
    void setLargo(double lar){largo = lar;};
    void setAncho(double anch){ancho = anch;};
    void setCargoAdicional(double charge){cargoAdicional = charge;};
    double getLargo(){return largo;};
    double getAncho(){return ancho;};
    double getCargoAdicional(){return cargoAdicional;};
    double calculaCostoEnvio();
};

Sobre::Sobre(){
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}

Sobre::Sobre(Persona rem, Persona dest, double cost, double lar, double anch, double carg):Envio(rem,dest,cost){
    largo = lar;
    ancho = anch;
    cargoAdicional = carg;
}
/*
La clase derivada Sobre incluye atributos para el largo y ancho del sobre, así como para el cargo adicional.
Sobre debe redefinir el cálculo del método calculaCosto para que si el largo excede de 25 cms y el ancho
excede 30 cms el cálculo sea costoEstándar + cargoAdicional, si las dimensiones del sobre no exceden los
valores mencionados, entonces solo se cobrará el costo estándar.
*/
double Sobre::calculaCostoEnvio(){
    if(largo>25 && ancho >30){
        return costoEstandar + cargoAdicional;
    }else{
        return costoEstandar;
    }
}
#endif