#ifndef Paquete_h
#define Paquete_h
#include "Envio.h"
class Paquete: public Envio{
private:
    double peso,costoKg;
public:
    Paquete();
    Paquete(Persona,Persona,double,double,double);
    void setPeso(double w){peso =w;};
    void setCostoKg(double ck){costoKg = ck;};
    double getPeso(){return peso;};
    double getCostoKg(){return costoKg;};
    double calculaCostoEnvio();
};

Paquete::Paquete(){
    peso,costoKg=0;
}

Paquete::Paquete(Persona rem,Persona dest,double cost,double w,double ck):Envio(rem,dest,cost){
    peso = w;
    costoKg = ck;
}
double Paquete::calculaCostoEnvio(){
    return costoEstandar +(peso*costoKg);
}
#endif