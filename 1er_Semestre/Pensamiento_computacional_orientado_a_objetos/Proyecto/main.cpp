#include <iostream>
#include <string>
#include "Vuelo.h"
using namespace std;

int menuPasajeros(){
    int iOpcion;
    cout<<"*** Menu de clientes ***"<<
    "\n1) Crear un nuevo usuario "<<
    "\n*** Metodos Modificadores ***"<<
    "\n2) Cambiar nombre "<<
    "\n3) Cambiar celular "<<
    "\n4) Cambiar contraseña "<<
    "\n*** Metodos de Acceso "<<
    "\n5) Obtener nombre "<<
    "\n6) Obtener celular "<<
    "\n7) Obtener Km "<<
    "\n8) Obtener email "<<
    "\n9) Obtener contraseña "<<
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

int main(){
    
    return 0;
}
