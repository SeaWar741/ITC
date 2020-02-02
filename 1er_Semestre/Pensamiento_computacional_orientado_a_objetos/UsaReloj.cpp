//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 21/11/2019
//| Descripcion: Programa para crear un reloj y relizar cambios en el mismo
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include"RelojD.h"
using namespace std;

//Nombre:menu
//Descripcion: Metodo para imprimir el menu
//              
//Entrada:
//          
//Salida:
//      Se despliega el menu          
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
    bool continueg = true;//variable para controlar el loop
    string separator = "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ al Reloj=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    //RelojD RelojD;
    RelojD RelojD; //se crea un objeto default
    while (continueg){    
        menu();//se imprime el menu
        cout<<"Ingresa una opcion del menu: >";cin>>selection; //se pide que el usuario ingrese una opcion
        if(selection==1){
            class RelojD RelojD1;//se crea un nuevo objeto 
            cout<<"\nSe creo el objeto con exito!"<<endl;
            cout<<separator<<endl;
        }
        else if(selection ==2){
            cout<<"\nIngresa la hora: >";cin>>hour;
            RelojD.setHora(hour);//se llama al objeto con el metodo y se asigna el valor de hour ingresado
            cout<<separator<<endl;
        }
        else if(selection ==3){
                cout<<"\nIngresa los minutos: >";cin>>min;
                RelojD.setMin(min);//se llama al objeto con el metodo y se asigna el valor de min ingresado
                cout<<separator<<endl;
        }
        else if(selection ==4){
                cout<<"\nLa hora es: "<<RelojD.getHora()<<endl;//se despliega la hora desde el metodo del objeto
                cout<<separator<<endl;
        }
        else if(selection ==5){
                cout<<"\nLos minutos son: "<<RelojD.getMin()<<endl;//se despliega los minutos desde el metodo del objeto
                cout<<separator<<endl;
        }
        else if(selection ==6){
                RelojD.incrementaMinutos();//se llama al objeto y se incrementa un minuto
                cout<<"\nSe ha incrementado la hora en un minuto exitosamente!"<<endl;
                cout<<separator<<endl;
        }
        else if(selection ==7){
                cout<<RelojD.muestra()<<endl;//se llama a la funcion del objeto que imprime la hora en formato especial
                cout<<separator<<endl;
        }
        else if(selection ==8){
                continueg = false; //se termina el loop
                cout<<separator<<endl;
                cout<<"\nHasta luego!"<<endl;
        }
        else{
            cout<<"\nOpcion no valida, volver a intentar"<<endl;
            cout<<separator<<endl;
        }
    }
    return 0;
}
