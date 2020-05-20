#include <iostream>
using namespace std;

#include "CtaComision.h"

int main(){
    CtaBanc *listaCtas[20];
    int sizeCtas;
    char tipoCta;
    int numCta;
    double saldoI, com, dinero;
    char opcion;

    cout << "Cuantas cuentas bancarias hay? ";
    cin >> sizeCtas;

    for (int c = 0; c < sizeCtas; c++){
        cout << "quieres una cuenta bancaria regular o con comision? (b/c) ";
        cin >> tipoCta;

        cout << "Numero de cuenta? ";
        cin >> numCta;

        cout << "Saldo inicial? ";
        cin >> saldoI;

        if (tipoCta == 'c'){
            cout << "Comision por hacer retiro? ";
            cin >> com;
            listaCtas[c] = new CtaComision(numCta,saldoI,com);
        }
        else{
            listaCtas[c] = new CtaBanc(numCta, saldoI);
        }
    
        // COMPLETA lo necesario para agregar los objetos en el arreglo listaCtas.
        // Crea cada objeto del tipo adecuado usando new

    }

    do{
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "a) depositar " << endl;
        cout << "b) retirar " << endl;
        cout << "c) consultar saldo " << endl;
        cout << "d) terminar " << endl;
        cout << "opcion ->";
        cin >> opcion;

        switch (opcion){
            case 'a':{
                cout << "teclea el numero de cuenta ";
                cin >> numCta;
                cout << "cuando vas a depositar? ";
                cin >> dinero;

                // COMPLETA
                for (int i = 0; i < 20; i++){
                    if (listaCtas[i]->getNumCuenta()==numCta){
                        listaCtas[i]->deposita(dinero);
                    }
                    
                }
                break;
            }

            case 'b':{
                cout << "teclea el numero de cuenta ";
                cin >> numCta;
                cout << "cuando vas a retirar? ";
                cin >> dinero;

                // COMPLETA
                for (int i = 0; i < 20; i++){
                    if (listaCtas[i]->getNumCuenta() == numCta){
                        bool retirado = listaCtas[i]->retira(dinero);
                        if (retirado!=true){
                            // usa este mensaje en caso de que no haya suficiente saldo para retirar
                            // no lo calcules aquí, el método retira te regresa un boleano que indica
                            // si se pudo o no realizar el retiro
                            cout << "No se pudo realizar el retiro " << endl;
                        }
                        
                    }
                } 
            }
            case 'c':{
                cout << "teclea el numero de cuenta ";
                cin >> numCta;

                // COMPLETA
                for (int i = 0; i < 20; i++){
                    if (listaCtas[i]->getNumCuenta() == numCta){
                        listaCtas[i]->getSaldo();
                    }
                }
                break;
            }
        }
    }while(opcion != 'd');
    return 0;
}

