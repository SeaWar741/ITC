#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vuelo.h"
using namespace std;

vector<Pasajero> Pasajeros;
vector<Vuelo> Vuelos;

void filldata(){
    string line;
    ifstream myfile;
    myfile.open("pasajeros.txt");
    while(getline(myfile, line)) {
     cout << line << endl;
    }
    myfile.close();
}

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
    "\n12) Validar Cuenta "<<
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

void pasajeros(int option){
    bool continueg =true;
    while (continueg){
        switch (option){
            case 1:
                filldata();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 0:
                continueg = false;
                cout<<"Hasta luego!"<<endl;
                break;
            default:
                cout<<"Opcion no valida, volver a intentar"<<endl;
                break;
        }
    }
}

void vuelos(int option){
    /*dasda*/
}

int main(){
    string jump="\n";
    bool continueg = true;
    int suboption1,suboption2;
    while(continueg){
        cout<<jump;
        int option1 = menuPrincipal();
        cout<<jump;
        switch (option1){
        case 1:
            suboption1 = menuPasajeros();
            pasajeros(suboption1);
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

