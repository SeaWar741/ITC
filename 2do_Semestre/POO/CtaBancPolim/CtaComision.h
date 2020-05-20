// Escribe la clase CtaComision
// Usa estas líneas para mostrar los datos de una cuenta por comision.
// En la primera línea muestras los datos de la cuenta bancaria
// y en la línea de abajo muestras la comisión de la cuenta.
//    CtaBanc:: mostrar();
//    cout <<"Comision: " << comision << endl;

#ifndef CtaComision_h
#define CtaComision_h

#include "CtaBanc.h"

class CtaComision : public CtaBanc{
private:
    double comision;

public:
    CtaComision();
    CtaComision(int, double, double c);

    double getComision();

    void setComision(double c);

     void mostrar();

    bool retira(double);
};

CtaComision::CtaComision() : CtaBanc(){
    comision = 0;
}

CtaComision::CtaComision(int numCuenta, double saldo, double c) : CtaBanc(numCuenta, saldo){
    comision = c;
}

double CtaComision::getComision(){
    return comision;
}

void CtaComision::setComision(double c){
    comision = c;
}

bool CtaComision::retira(double cant){
    if (saldo >= cant){
        saldo -= (cant + comision);
        return true;
    }
    else{
        return false;
    }
}

void CtaComision::mostrar(){
    CtaBanc::mostrar();
    cout << "Comision: " << comision << endl;
}
#endif