#include <iostream>
#include <fstream>
#include <ostream>
#include "Sobre.h"
#include "Paquete.h"

using namespace std;

int main(){
    char type;
    ifstream file;
    file.open("datosEnvios.txt");
    string destName, destState, destCity, destCp, remName, remState, remCity, remCp;
    double costo,largo,ancho,cargoAd,peso,costoKg,total;
    Envio *listaEnvios[20];
    int i = 0;
    while (file >> type){
        file >> remName >> remState >> remCity >> remCp >> destName >> destState >> destCity >> destCp >> costo;

        Persona rem(remName, remState, remCity, remCp);
        Persona dest(destName, destState, destCity, destCp);

        if (type == 'p'){
            file>>peso>>costoKg;
            listaEnvios[i]= new Paquete(rem,dest,costo,peso,costoKg);
        }else{
            file>>largo>>ancho>>cargoAd;
            listaEnvios[i]=new Sobre(rem,dest,costo,largo,ancho,cargoAd);
        }
        total += listaEnvios[i]->calculaCostoEnvio();
        cout<<"Remitente:"<<endl;rem.imprimir();
        cout<<"Destinatario:"<<endl;dest.imprimir();
        cout<<"Costo: "<<listaEnvios[i]->calculaCostoEnvio()<<endl;
        i++;
    }
    file.close();
    cout<<"Total envios: "<<total<<endl;
    return 0;
}
