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
    cout<<"8)salir"<<endl;
    cout<<"9)incrementar\n"<<endl;
}

int main(){
    int selection,hour,min;
    bool continueg = true;
    string separator = "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ al Reloj=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    //RelojD RelojD;
    RelojD RelojD;
    while (continueg){    
        menu();
        cout<<"Ingresa una opcion del menu: >";cin>>selection;
        if(selection==1){
            class RelojD RelojD1;
            cout<<"\nSe creo el objeto con exito!"<<endl;
            cout<<separator<<endl;
        }
        else if(selection ==2){
            cout<<"\nIngresa la hora: >";cin>>hour;
            RelojD.setHora(hour);
            cout<<separator<<endl;
        }
        else if(selection ==3){
                cout<<"\nIngresa los minutos: >";cin>>min;
                RelojD.setMin(min);
                cout<<separator<<endl;
        }
        else if(selection ==4){
                cout<<"\nLa hora es: "<<RelojD.getHora()<<endl;
                cout<<separator<<endl;
        }
        else if(selection ==5){
                cout<<"\nLos minutos son: "<<RelojD.getMin()<<endl;
                cout<<separator<<endl;
        }
        else if(selection ==6){
                RelojD.incrementaMinutos();
                cout<<"\nSe ha incrementado la hora en un minuto exitosamente!"<<endl;
                cout<<separator<<endl;
        }
        else if(selection ==7){
                RelojD.desplegar();
                cout<<separator<<endl;
        }
        else if(selection ==8){
                continueg = false;
                cout<<separator<<endl;
                cout<<"\nHasta luego!"<<endl;
        }
        else if(selection ==9){
            for (int iK = 0; iK <= 1000; iK++){
                RelojD.desplegar();
                RelojD.incrementaMinutos();
            }
        }
        else{
            cout<<"\nOpcion no valida, volver a intentar"<<endl;
            cout<<separator<<endl;
        }
    }
    return 0;
}
