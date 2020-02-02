//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 24/11/2019
//| Descripcion: Objeto Evento
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include<iostream>
#include<string>
#include "RelojD.h"
using namespace std;

class Evento{
private:
    RelojD hora;
    int iDuracionMin;
    string sAsunto;
public:
    Evento();
    Evento(RelojD,int,string);

    void setHora(RelojD);
    void setDuracion(int);
    void setAsunto(string);

    RelojD getHora();
    int getDuracion();
    string getAsunto();

    string str();
};

Evento::Evento(){
    RelojD rolexOro;
    hora = rolexOro;
    iDuracionMin=100;
    sAsunto ="Fiesta Chava 19 XIX";
}
Evento::Evento(RelojD rolex,int iDuracion,string sAsunto){
    hora=rolex;
    iDuracion=iDuracion;
    this->sAsunto=sAsunto;
}
void Evento::setHora(RelojD rolex){
    hora = rolex;
}
void Evento::setDuracion(int iDuracion){
    iDuracion=iDuracion;
}
void Evento::setAsunto(string sAsunto){
    this->sAsunto=sAsunto;
}

RelojD Evento::getHora(){
    return hora;
}
int Evento::getDuracion(){
    return iDuracionMin;
}
string Evento::getAsunto(){
    return sAsunto;
}
string Evento::str(){
    string  a(30,'-');
    string all;
    a="\n"+a+"\n";
    return a+"Evento: "+a+"\nDuracion: "+to_string(iDuracionMin)+"\nAsunto"+sAsunto+a;

}