//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 21/11/2019
//| Descripcion: Objeto reloj
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include<iostream>
#include<string>
using namespace std;

//Nombre:RelojD
//Descripcion: Objeto reloj
class RelojD{
private:
    int iHr,iMin; //variables privadas para hora y minuto
public:
    RelojD();//inicializador del objeto vacio
    RelojD(int iHri,int iMini);//inicializador del objeto con parametros

    void setHora(int iHri);//metodo para establecer hora
    void setMin(int iMini);//metodo para establecer minutos
    
    int getHora();//metodo para obtener la hora
    int getMin();//metodo para obtener los minutos

    void desplegar();//metodo para desplegar la hora en formato especial
    void incrementaMinutos();//metodo para incrementar los minutos
};

//Nombre:RelojD
//Descripcion: Metodo para crear el objeto
//              
//Entrada:
//          
//Salida:
//      Se crea el objeto con valores 0 para hora y minuto    
RelojD::RelojD(){
    iHr = 0;
    iMin = 0;
}

//Nombre:RelojD
//Descripcion: Metodo para crear el objeto
//              
//Entrada:
//          hora y minuto
//Salida:
//      Se crea el objeto con valores ingresados por el usuario
RelojD::RelojD(int iHr,int iMin){
    this->iHr = iHr;
    this->iMin = iMin;
}

//Nombre:setHora
//Descripcion: Metodo para establecer la hora
//              
//Entrada:
//          hora
//Salida:
//      se establece el valor de hora del objeto con el ingresado por el usuario
void RelojD::setHora(int iHri){
    if(iHri >=0 && iHri<=23){//el valor tiene que estar en el rango de 0-23
        iHr =iHri;
    }
    else{
        cout<<"Valor no valido"<<endl;
    }
}

//Nombre:setMin
//Descripcion: Metodo para establecer los minutos
//              
//Entrada:
//          minutos
//Salida:
//      se establece el valor de los minutos
void RelojD::setMin(int iMini){
    if(iMini >=0 && iMini<=59){//valor entre 0 y 59
        iMin =iMini;
    }
    else{
        cout<<"Valor no valido"<<endl;
    }
}
int RelojD::getHora(){
    return iHr;
}
int RelojD::getMin(){
    return iMin;
}

void RelojD::desplegar(){
    string hour,minute;
    if(iHr<10){
        hour = "0"+to_string(iHr);
    }
    else{
        hour = to_string(iHr);
    }
    if(iMin<10){
        minute = "0"+to_string(iMin);
    }
    else{
        minute = to_string(iMin);
    }
    cout<<"\n"<<hour<<":"<<minute<<"\n"<<endl;
}
void RelojD::incrementaMinutos(){
    if(iMin==59){//si son las 11pm con 59min se cambia a las 0:0
        if(iHr ==23){
            iHr =0;
            iMin=0;
        }
        else{
            iHr++;
            iMin =0;
        }
    }
    else{
        iMin++;
    }
}

