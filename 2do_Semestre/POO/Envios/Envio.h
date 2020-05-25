#ifndef Envio_h
#define Envio_h
#include "Persona.h"
using namespace std;

class Envio{
protected:
    Persona remitente, destinatario;
    double costoEstandar;

public:
    Envio();
    Envio(Persona, Persona, double);
    void setRemitente(Persona rem) { remitente = rem; };
    void setDestinatario(Persona dest) { destinatario = dest; };
    void setCostoEstandar(double cost) { costoEstandar = cost; };
    Persona getRemitente() { return remitente; };
    Persona getDestinatario() { return destinatario; };
    double getCostoEstandar() { return costoEstandar; };
    virtual double calculaCostoEnvio() = 0;
};

Envio::Envio(){
    remitente, destinatario = Persona();
    costoEstandar = 0;
}

Envio::Envio(Persona rem, Persona dest, double cost){
    remitente = rem;
    destinatario = dest;
    costoEstandar = cost;
}
#endif