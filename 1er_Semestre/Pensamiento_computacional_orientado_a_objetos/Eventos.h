#include <iostream>
#include"RelojD.h"
using namespace std;

class Eventos{
private:
    RelojD hr;
    int iDuracionMin;
    string sAsunto;
public:
    Eventos();
    Eventos(RelojD,int,string);

    void setHora(RelojD);
    void setDuracion(int);
    void setAsunto(string);

    RelojD getHora();//composicion
    int getDuracion();
    int getMin();
    string getAsunto();

    void incrementaMinutos();
    void print();
};

Eventos::Eventos(){
    RelojD rolex(0,0);

    hr=rolex;
    iDuracionMin = 100;
    sAsunto="Borregos Campeones";
}

Eventos::Eventos(RelojD rolex, int iDuracion,string sAsunto){
    hr=rolex;
    iDuracionMin=iDuracion;
    this->sAsunto=sAsunto;
}

void Eventos::setHora(RelojD rolex){
    hr = rolex;
}
void Eventos::setDuracion(int iDuracion){
    iDuracionMin=iDuracion;
}
void Eventos::setAsunto(string sAsunto){
    this->sAsunto=sAsunto;
}

RelojD Eventos::getHora(){
    return hr;
}
int Eventos::getDuracion(){
    return iDuracionMin;
}
string Eventos::getAsunto(){
    return sAsunto;
}
void Eventos::print(){
    hr.desplegar();
}