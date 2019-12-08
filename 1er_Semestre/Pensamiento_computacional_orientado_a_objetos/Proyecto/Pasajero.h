//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 30/12/2019
//| Descripcion: Objeto Pasajero
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include <string>
using namespace std;

class Pasajero{
private:
    string sName,sCel,sEmail,sContra;//atributos privados
    int iKm;
public:
    Pasajero();//constructores
    Pasajero(string,string,string,string,int);

    void setName(string);//metodos set
    void setCel(string);
    void setEmail(string);
    void setPassword(string);
    void setKm(int);

    string getName();//metodos get
    string getCel();
    string getEmail();
    string getPassword();
    int getKm();

    string str();//otros metodos
    void incrementaKm();
    void decrementakm();
    bool validarCuenta(string,string);
    bool existeUsuario(string);
};

Pasajero::Pasajero(){
    this -> sName = "ND";
    this -> sCel = "ND";
    this -> sEmail = "ND";
    this -> sContra = "ND";
    this -> iKm = 0;
}

Pasajero::Pasajero(string sNamei,string sCeli,string sEmaili,string sContrai,int iKmi){
    sName = sNamei;
    sCel = sCeli;
    sEmail = sEmaili;
    sContra = sContrai;
    iKm = iKmi;
}
void Pasajero::setName(string sNamei){
    sName =sNamei;
}
void Pasajero::setCel(string sCeli){
    sCel = sCeli;
}
void Pasajero::setEmail(string sEmaili){
    sEmail = sEmaili;
}
void Pasajero::setPassword(string sContrai){
    sContra = sContrai;
}
void Pasajero::setKm(int iKmi){
    iKm = iKmi;
}

string Pasajero::getName(){
    return sName;
}
string Pasajero::getCel(){
    return sCel;
}
string Pasajero::getEmail(){
    return sEmail;
}
string Pasajero::getPassword(){
    return sContra;
}
int Pasajero::getKm(){
    return iKm;
}

string Pasajero::str(){
    //sName,sCel,sEmail,sContra;int iKm;
    return "|Pasajero: "+sName+" |Celular: "+sCel+" |Email: "+sEmail+" |Contrasena: "+sContra+" |Kilometros: "+to_string(iKm);
}
void Pasajero::incrementaKm(){
    iKm++;
}
void Pasajero::decrementakm(){
    int km = iKm;
    if (km > 0){
        iKm--;
    }
}
bool Pasajero::validarCuenta(string sEmaili,string sContrai){
    if(existeUsuario(sEmaili) && sContrai == sContra){
        return true;
    }
    else{
        return false;
    }
}

bool Pasajero::existeUsuario(string sEmaili){
    if (sEmaili == sEmail){
        return true;
    }
    else{
        return false;
    }
    
}