#include <iostream>
#include <string>
#include "Fecha.h"
#include "RelojD.h"
using namespace std;

class Vuelo{
private:
    Fecha fecha;
    RelojD hora;
    int iPrecio;
    string sDestino;
    string sAerolinea;
    int iKm,iAsientos;
    int matPasajeros[30][4];
public:
    Vuelo();
    Vuelo();
};

Vuelo::Vuelo(/* args */)
{
}

Vuelo::~Vuelo()
{
}
