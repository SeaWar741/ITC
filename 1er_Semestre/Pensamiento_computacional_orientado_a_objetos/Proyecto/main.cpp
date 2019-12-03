#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include "Vuelo.h"

using namespace std;

vector<Pasajero> Pasajeros;
vector<Vuelo> Vuelos;
string jump="\n";

void filldata(){
    //Variables Personas
    string myText;
    int km;
    int counter=0;
    Pasajero pasajero;
    //Variables Vuelo
    Vuelo Vuelo;
    Fecha Fecha;
    RelojD Hora;
    int iPrecio;
    string sDestino;
    string sAerolinea;
    int iKm,iAsientos;
    int counter2=0;
    int matPasajeros[30][4];
    Pasajero Pasajerosm[30][4];
    //Personas
        ifstream MyReadFile("pasajeros.txt");
        while (getline (MyReadFile, myText)) {
            istringstream ss(myText); 
            do { 
                string word; 
                ss >> word; 
                if(counter== 0){
                    pasajero.setName(word);
                }
                else if(counter== 1){
                    pasajero.setCel(word);
                }
                else if(counter== 2){
                    pasajero.setEmail(word);
                }
                else if(counter== 3){
                    pasajero.setPassword(word);
                }
                else if(counter== 4){
                    km = stoi(word);
                    pasajero.setKm(km);
                }
                counter++;
            } while (ss);
            Pasajeros.push_back(pasajero); 
            counter=0;
            cout<<jump;
        }
        MyReadFile.close();
    //Vuelos
        ifstream MyReadFile2("vuelos.txt");
        while (getline (MyReadFile2, myText)) {
            istringstream ss(myText); 
            do { 
                string word; 
                ss >> word; 
                if(counter== 0){//date
                    vector<int> vect;
                    stringstream ss(word);

                    for (int i; ss >> i;) {
                        vect.push_back(i);    
                        if (ss.peek() == '/')
                            ss.ignore();
                    }

                    for (size_t i = 0; i < vect.size(); i++){
                        if (counter ==0){
                            Fecha.setDia(vect[i]);
                        }
                        else if (counter ==1){
                            Fecha.setMes(vect[i]);
                        }
                        else if (counter ==3){
                            Fecha.setYear(vect[i]);
                        }
                    }
                    counter2=0;
                }
                else if(counter== 1){//hour
                    vector<int> vect;
                    stringstream ss(word);

                    for (int i; ss >> i;) {
                        vect.push_back(i);    
                        if (ss.peek() == ':')
                            ss.ignore();
                    }
                    for (size_t i = 0; i < vect.size(); i++){
                        if (counter ==0){
                            Hora.setHoras(vect[i]);
                        }
                        else if (counter ==1){
                            Hora.setMinutos(vect[i]);
                        }
                    }
                    counter2=0;
                }
                else if(counter== 2){//price
                    Vuelo.setPrecio(stoi(word));
                }
                else if(counter== 3){//destino
                    Vuelo.setDestino(word);
                }
                else if(counter== 4){//aerolina
                    Vuelo.setAerolinea(word);
                }
                else if(counter== 5){//km
                    Vuelo.setKilometros(stoi(word));
                }
                counter++;
            } while (ss);
            Vuelos.push_back(Vuelo); 
            counter=0;
            cout<<jump;
        }
        MyReadFile.close();
}

void printdata(){
    for(int i=0; i<Pasajeros.size(); ++i){
        cout << Pasajeros[i].str()<<endl;
    }
}
void printdata2(){
    for(int i=0; i<Vuelos.size(); ++i){
        cout << Vuelos[i].str()<<endl;
    }
}
//Funciones Pasajero
bool existeUsuario(string user){
    for(int i=0; i<Pasajeros.size(); ++i){
        if(Pasajeros[i].existeUsuario(user)){
            return true;
        }
    }
    return false;
}
void crearUsuario(){
    string sName,sCel,sEmail,sContra;
    int iKm;
    cout<<"Ingresar Nombre: >";cin>>sName;
    cout<<"Ingresar Email: >";cin>>sEmail;
    if (existeUsuario(sEmail)==false){
        cout<<"Ingresar Celular: >";cin>>sCel;
        cout<<"Ingresar Contrasena: >";cin>>sContra;
        Pasajero pasajero(sName,sCel,sEmail,sContra,0);
        Pasajeros.push_back(pasajero);
        cout<<"Usuario Creado exitosamente!"<<endl;
    }
    else{
        cout<<"Este usuario ya esta registrado!"<<endl;
    }
}
int login(){
    int userid;
    string user,password;
    cout<<"Ingresar email: >";cin>>user;
    if(existeUsuario(user)){
        cout<<"Ingresar contrasena: >";cin>>password;
        for(int i=0; i<Pasajeros.size(); ++i){
            if(Pasajeros[i].validarCuenta(user,password)){
                return i;
            }
        }
    }
    cout<<"Usuario no registrado"<<endl;
    return -1;
}

//Funciones Vuelos


//Menus
    int menuPasajeros(){
        int iOpcion;
        cout<<"*** Menu de clientes ***"<<
        "\n1) Crear un nuevo usuario "<<
        "\n*** Metodos Modificadores ***"<<
        "\n2) Cambiar nombre "<<
        "\n3) Cambiar celular "<<
        "\n4) Cambiar contrasena "<<
        "\n*** Metodos de Acceso "<<
        "\n5) Obtener nombre "<<
        "\n6) Obtener celular "<<
        "\n7) Obtener Km "<<
        "\n8) Obtener email "<<
        "\n9) Obtener contrasena "<<
        "\n*** Otros Metodos *** "<<
        "\n10) Incrementa kilometros "<<
        "\n11) decrementa kilometros "<<
        //"\n12) Validar Cuenta "<<
        "\n12) Imprimir Cuentas "<<
        "\n0) Terminar "<<
        "\nTeclea la opcion: >";
        cin>>iOpcion;
        return iOpcion;
    }

    int menuVuelos(){
        int iOpcion;
        cout<<"*** Menu de vuelos ***"<<
        "\n1) Crear un nuevo vuelo "<<
        "\n*** Metodos Modificadores ***"<<
        "\n2) Establecer fecha "<<
        "\n3) Establecer hora "<<
        "\n4) Establecer precio "<<
        "\n5) Establecer destino "<<
        "\n6) Establecer aerolinea "<<
        "\n7) Establecer Km "<<
        "\n8) Establecer Asientos "<<
        "\n9) Dejar todos los asientos vacios "<<
        "\n*** Metodos de Acceso *** "<<
        "\n10) Obtener fecha "<<
        "\n11) Obtener hora "<<
        "\n12) Obtener precio "<<
        "\n13) Obtener destino "<<
        "\n14) Obtener aerolinea "<<
        "\n15) Obtener km "<<
        "\n16) Obtener asientos "<<
        "\n*** Otros Metodos *** "<<
        "\n17) Desplegar info vuelo "<<
        "\n18) Muestra asientos disponibles "<<
        "\n19) Incrementa Asientos "<<
        "\n20) Decrementa Asientos "<<
        "\n21) Reservar Asiento "<<
        "\n22) Muestra lista de pasajeros del vuelo"<<
        "\n23) Verificar disponibilidad asiento "<<
        "\n0) Terminar "<<
        "\nTeclea la opcion: >";
        cin>>iOpcion;
        return iOpcion;
    }

    int menuPrincipal(){
        int iOpcion;
        cout<<"*** Integrador TC1033 ***"<<
        "\n1) Clientes"<<
        "\n2) Vuelos"<<
        "\n0) Terminar"<<
        "\nTeclea la opcion: >";
        cin>>iOpcion;
        return iOpcion;
    }




void pasajeros(){
    bool continueg =true;
    int option;
    int userid;
    string nuser,celular,contrasena;
    while (continueg){
        option = menuPasajeros();
        cout<<jump;
        switch (option){
            case 1:
                crearUsuario();
                break;
            case 2:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nuevo nombre: >";
                    cin>>nuser;
                    Pasajeros[userid].setName(nuser);
                    cout<<"Nombre cambiado exitosamente!"<<endl;
                }
                break;
            case 3:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nuevo celular: >";
                    cin>>celular;
                    Pasajeros[userid].setName(celular);
                    cout<<"Celular cambiado exitosamente!"<<endl;
                }
                break;
            case 4:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nueva contrasena: >";
                    cin>>contrasena;
                    Pasajeros[userid].setName(contrasena);
                    cout<<"Contrasena cambiada exitosamente!"<<endl;
                }
                break;
            case 5:
                userid = login();
                if(userid!=-1){
                    cout<<"Nombre: "<<Pasajeros[userid].getName()<<endl;
                }
                break;
            case 6:
                userid = login();
                if(userid!=-1){
                    cout<<"Celular: "<<Pasajeros[userid].getCel()<<endl;
                }
                break;
            case 7:
                userid = login();
                if(userid!=-1){
                    cout<<"Km: "<<Pasajeros[userid].getKm()<<endl;
                }
                break;
            case 8:
                userid = login();
                if(userid!=-1){
                    cout<<"Email: "<<Pasajeros[userid].getEmail()<<endl;
                }
                break;
            case 9:
                userid = login();
                if(userid!=-1){
                    cout<<"Contrasena: "<<Pasajeros[userid].getPassword()<<endl;
                }
                break;
            case 10:
                userid = login();
                if(userid!=-1){
                    Pasajeros[userid].incrementaKm();
                    cout<<"Se han añadido km a su cuenta exitosamente!"<<endl;
                }
                break;
            case 11:
                    Pasajeros[userid].incrementaKm();
                    cout<<"Se han decrementado km a su cuenta exitosamente!"<<endl;
                break;
            case 12:
                printdata();
                break;
            case 0:
                continueg = false;
                cout<<"Hasta luego!"<<endl;
                break;
            default:
                cout<<"Opcion no valida, volver a intentar"<<endl;
                break;
        }
        cout<<jump;
    }
}

void vuelos(int option){
    /*dasda*/
}

int main(){
    bool continueg = true;
    int suboption2;

    filldata(); //se lee todos los usuarios,vuelos y se insertan en el vector

    while(continueg){
        cout<<jump;
        int option1 = menuPrincipal();
        cout<<jump;
        switch (option1){
        case 1:
            pasajeros();
            break;
        case 2:
            suboption2 = menuVuelos();
            break;
        case 0:
            continueg = false;
            cout<<jump;
            cout<<"Hasta luego!"<<endl;
            break;
        default:
            cout<<jump;
            cout<<"Opcion no valida, volver a intentar"<<endl;
            break;
        }
    }
    return 0;
}

