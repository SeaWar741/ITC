#include <iostream>
#include <string>
#include <vector>
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
    void setAsientos(int);
    void setReservaAsiento(int,int,int);

    Fecha getFecha();
    RelojD getHora();
    int getPrecio();
    string getDestino();
    string getAerolinea();
    int getKilometros();
    int getPasajero(int,int);
    int getAsientos();
    string getmatPasajeros();

    string str();
    void muestraAsientosDisponibles();
    void incrementaAsientos();
    void derementaAsientos();
    bool reservarAsiento(Pasajero,int,int,int);
    void muestraListaPasajeros(vector <Pasajero>);
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
void Vuelo::setAsientos(int asientos){
    iAsientos=asientos;
}
void Vuelo::setReservaAsiento(int i,int j,int id){
    matPasajeros[i][j] = id;
    if(id !=-1){
        iAsientos ++;
    }
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
int Vuelo::getAsientos(){
    return iAsientos;
}
string Vuelo::getmatPasajeros(){
    string word="";
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            if(j==3){
                word = word +to_string(matPasajeros[i][j])+"\n";
            }
            else{
                word = word +to_string(matPasajeros[i][j])+" ";
            }
        }
        
    }
    return word;
}

string Vuelo::str(){ 
    return fecha.str()+"|"+hora.str()+"|"+sAerolinea+"|"+sDestino+"|$"+to_string(iPrecio)+"|No. Pasajeros:"+to_string(iAsientos);
}
void Vuelo::muestraAsientosDisponibles(){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            if(matPasajeros[i][j] !=-1){
                cout<<"ND"<<"\t";
            }
            else{
                cout<<"--"<<"\t";
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
bool Vuelo::reservarAsiento(Pasajero pass, int id,int i,int j){
    if (asientoDisponible(i,j)){
        setReservaAsiento(i,j,id);
        cout<<pass.getName()<<", se reservo con exito el asiento!"<<endl;
        return true;
    }
    return false;
}
void Vuelo::muestraListaPasajeros(vector <Pasajero> Pasajeros){ /*Arreglar*/
    int counter = 0;
    string print="";
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            if(matPasajeros[i][j] !=-1){
                print += Pasajeros[matPasajeros[i][j]].getName()+"\n";
                counter++;
            }
        }
    }
    if(counter >0){
        cout<<"-*-*-*-*-*-*-=Pasajeros en el vuelo ("+to_string(counter)+")=-*-*-*-*-*-*-"<<endl;
        cout<<print<<endl;
    }
    else{
        cout<<"No hay pasajeros registrados para el vuelo"<<endl;
    }
}
bool Vuelo::asientoDisponible(int i,int j){
    if (matPasajeros[i][j] !=-1){
        cout<<"El asiento de la fila "<<i<<" columna "<<j<<" se encuentra ocupado"<<endl;
        return false;
    }
    else{
        cout<<"El asiento de la fila "<<i<<" columna "<<j<<" se encuentra libre"<<endl;
        return true;
    }
}
