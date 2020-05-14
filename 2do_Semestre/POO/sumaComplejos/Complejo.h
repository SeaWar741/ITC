#include <iostream>
using namespace std;

class Complejo{
private:
    /* data */
    double real,imaginaria;
public:
    Complejo(double reali,double imaginariai);
    Complejo();

    void setReal(double reali);
    void setImagi(double imaginariai);

    double getReal();
    double getImagi();

    Complejo suma(Complejo comp);

};

Complejo::Complejo(){
    real = 0;
    imaginaria = 0;
}

Complejo::Complejo(double reali,double imaginariai){
    real = reali;
    imaginaria = imaginariai;
}


void Complejo::setReal(double reali){
    real = reali;
}
void Complejo::setImagi(double imaginariai){
    imaginaria=imaginariai;
}

double Complejo::getReal(){
    return real;
}
double Complejo::getImagi(){
    return imaginaria;
}

Complejo Complejo::suma(Complejo comp){
    Complejo complex;
    complex.real = real+comp.real;
    complex.imaginaria = imaginaria +comp.imaginaria;
    return complex;
}