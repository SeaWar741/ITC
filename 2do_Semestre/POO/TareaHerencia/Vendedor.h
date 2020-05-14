// Escribe aquí la clase Vendedor

// usa estos cout para mostrar los datos de un vendedor
//    cout << "Id de empleado " << ident;
//    cout << " sueldo $" << sueldo;
//    cout << " %comision " << porcentajeComision;
//    cout << " ventas " << ventas << endl;
#include <iostream>
#include "Empleado.h"
using namespace std;

class Vendedor:public Empleado{
private:
    /* data */
    double porcentajeComision;
    int ventas;
public:
    Vendedor();
    Vendedor(int ident,double sueldo,double p,int v);

    void setPorcentaje(double p);
    void setVentas(int v);

    double getPorcentaje();
    int getVentas();

    double calculaPago();
    void muestra();
};

Vendedor::Vendedor():Empleado(){
    porcentajeComision = 0;
    ventas = 0;
}

Vendedor::Vendedor(int ident,double sueldo,double p,int v):Empleado(ident,sueldo){
    porcentajeComision = p;
    ventas = v;
}

void Vendedor::setPorcentaje(double p){
    porcentajeComision = p;
}
void Vendedor::setVentas(int v){
    ventas = v;
}

double Vendedor::getPorcentaje(){
    return porcentajeComision;
}   
int Vendedor::getVentas(){
    return ventas;
}

double Vendedor::calculaPago(){
    return getSueldo()+(ventas*porcentajeComision);
}

void Vendedor::muestra(){
    cout << "Id de empleado " << ident;
    cout << " sueldo $" << sueldo;
    cout << " %comision " << porcentajeComision;
    cout << " ventas " << ventas << endl;
}