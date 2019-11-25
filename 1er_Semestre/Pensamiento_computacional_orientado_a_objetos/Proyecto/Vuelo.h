#include <iostream>
#include <string>
#include "Avion.h"
#include "Hora.h"
#include "Fecha.h"
using namespace std;

class Vuelo{
private:
    Avion avion;
    Fecha fsalida;
    Fecha fllegada;
    Hora hsalida;
    Hora hllegada;
    string nombre;
    double precio;
    double duracion;
    bool disponibilidad;

public:
    Vuelo();
    Vuelo(Avion,string,double,double);
};

Vuelo::Vuelo(){
    Avion avion;
    nombre = "Hawaii";
    precio= 11599.99;
    duracion = 12.30;
}

Vuelo::Vuelo(Avion avioni,string nombrei,double precioi,double duracioni){
    avion = avioni;
    nombre = nombrei;
    precio = precioi;
    duracion = duracioni;
}


