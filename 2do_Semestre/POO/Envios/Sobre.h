#ifndef Sobre_h
#define Sobre_h
#include "Envio.h"
using namespace std;

class Sobre : public Envio
{
private:
    double largo, ancho, cargoAdicional;

public:
    Sobre();
    Sobre(Persona, Persona, double, double, double, double);
    void setLargo(double lar) { largo = lar; };
    void setAncho(double anch) { ancho = anch; };
    void setCargoAdicional(double ad) { cargoAdicional = ad; };
    double getLargo() { return largo; };
    double getAncho() { return ancho; };
    double getCargoAdicional() { return cargoAdicional; };
    double calculaCostoEnvio();
};

Sobre::Sobre()
{
    largo, ancho, cargoAdicional = 0;
}

Sobre::Sobre(Persona rem, Persona dest, double cost, double lar, double anch, double ad) : Envio(rem, dest, cost)
{
    largo = lar;
    ancho = anch;
    cargoAdicional = ad;
}

double Sobre::calculaCostoEnvio()
{
    if (largo > 25 && ancho > 30)
    {
        return costoEstandar + cargoAdicional;
    }
    else
    {
        return costoEstandar;
    }
}

#endif