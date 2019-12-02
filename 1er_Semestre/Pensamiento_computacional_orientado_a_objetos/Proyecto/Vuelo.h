#include <iostream>
#include <string>
#include "Fecha.h"
#include "RelojD.h"
#include "Pasajero.h"
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
    Vuelo(Fecha,RelojD,int,string,string,int);

    void setFecha(Fecha);
    void setHora(RelojD);
    void setPrecio(int);
    void setDestino(string);
    void setAerolinea(string);
    void setKilometros(int);
    void setReservaAsiento(int,int);

    Fecha getFecha();
    RelojD getHora();
    int getPrecio();
    string getDestino();
    string getAerolinea();
    int getKilometros();
    int getPasajero(int,int);

    string str();
    void muestraAsientosDisponibles();
    void incrementaAsientos();
    void derementaAsientos();
    void reservarAsiento(Pasajero,int,int);
    void muestraListaPasajeros();
    bool asientoDisponible(int,int);
};

Vuelo::Vuelo(){
   this -> iPrecio = 0;
   this -> sDestino = "ND";
   this -> sAerolinea = "ND";
   this -> iKm = 0;
   this -> iAsientos = 120;
}

Vuelo::Vuelo(Fecha date,RelojD clock,int iPrecioi,string sDestinoi,string sAerolineai,int iKmi){
    fecha = date;
    hora = clock;
    iPrecio = iPrecioi;
    sDestino = sDestinoi;
    sAerolinea = sAerolineai;
    iKm = iKmi;
}
void Vuelo::setFecha(Fecha date){
    fecha = date;
}
void Vuelo::setHora(RelojD clock){
    hora = clock;
}
void Vuelo::setPrecio(int iPrecioi){
    iPrecio = iPrecioi;
}
void Vuelo::setDestino(string sDestinoi){
    sDestino = sDestinoi;
}
void Vuelo::setAerolinea(string sAerolineai){
    sAerolinea = sAerolineai;
}
void Vuelo::setKilometros(int iKmi){
    iKm = iKmi;
}
void Vuelo::setReservaAsiento(int i,int j){
    matPasajeros[i][j] = 1000;
}

Fecha Vuelo::getFecha(){
    return fecha;
}
RelojD Vuelo::getHora(){
    return hora;
}
int Vuelo::getPrecio(){
    return iPrecio;
}
string Vuelo::getDestino(){
    return sDestino;
}
string Vuelo::getAerolinea(){
    return sAerolinea;
}
int Vuelo::getKilometros(){
    return iKm;
}
int Vuelo::getPasajero(int i,int j){
    return matPasajeros[i][j];
}

string Vuelo::str(){ /*Arreglar*/
    return"Vuelo de "+sAerolinea+"con destino a "+sDestino;
}
void Vuelo::muestraAsientosDisponibles(){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            if(matPasajeros[i][j] !=0){
                cout<<matPasajeros[i][j]<<"\t";
            }
            else{
                cout<<"ND"<<"\t";
            }
        }
        cout<<endl;  
    }
}
void Vuelo::incrementaAsientos(){
    iAsientos ++;
}
void Vuelo::derementaAsientos(){
    iAsientos --;
}
void Vuelo::reservarAsiento(Pasajero,int,int){

}
void Vuelo::muestraListaPasajeros(){ /*Arreglar*/
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            cout<<matPasajeros[i][j]<<"\t";
        }
        cout<<endl;  
    }
}
bool Vuelo::asientoDisponible(int i,int j){
    if (matPasajeros[i][j] == 0){
        cout<<"El asiento de la fila "<<i<<" columna "<<j<<" se encuentra ocupado"<<endl;
        return false;
    }
    else{
        cout<<"El asiento de la fila "<<i<<" columna "<<j<<" se encuentra libre"<<endl;
        return true;
    }
}