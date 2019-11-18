#include <iostream>
#include"RelojD.h"
using namespace std;


void menu(){
    cout<<"\n1)Crear objeto"<<endl;
    cout<<"2)setHora"<<endl;
    cout<<"3)setMinutos"<<endl;
    cout<<"4)getHora"<<endl;
    cout<<"5)getMinutos"<<endl;
    cout<<"6)incrementaMinutos"<<endl;
    cout<<"7)desplegar"<<endl;
    cout<<"8)salir\n"<<endl;
}

int main(){
    int selection,hour,min;
    bool continueg = true;
    string separator = "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ al Reloj=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    while (continueg){    
        menu();
        cout<<"Ingresa una opcion del menu: >";cin>>selection;
        switch (selection){
        case 1:
            RelojD RelojD;
            cout<<"\nSe creo el objeto con exito!"<<endl;
            cout<<separator<<endl;
            break;
        case 2:
            cout<<"\nIngresa la hora: >";cin>>hour;
            RelojD.setHora(hour);
            cout<<separator<<endl;
            break;
        case 3:
            cout<<"\nIngresa los minutos: >";cin>>min;
            RelojD.setMin(min);
            cout<<separator<<endl;
            break;
        case 4:
            cout<<"\nLa hora es: "<<RelojD.getHora()<<endl;
            cout<<separator<<endl;
            break;
        case 5:
            cout<<"\nLos minutos son: "<<RelojD.getMin()<<endl;
            cout<<separator<<endl;
            break;
        case 6:
            RelojD.incrementaMinutos();
            cout<<"\nSe ha incrementado la hora en un minuto exitosamente!"<<endl;
            cout<<separator<<endl;
            break;
        case 7:
            RelojD.desplegar();
            cout<<separator<<endl;
            break;
        case 8:
            continueg = false;
            cout<<separator<<endl;
            break;
        default:
            cout<<"\nOpcion no valida, volver a intentar"<<endl;
            cout<<separator<<endl;
            break;
        }
    }
    return 0;
}
