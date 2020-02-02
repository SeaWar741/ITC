//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 30/12/2019
//| Descripcion: Objeto Fecha
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include <string>
using namespace std;

class Fecha{
private:
    int iDia,iMes,iYear;//Atributos privados
public:
    Fecha();//constructor
    Fecha(int,int,int);

    void setDia(int);//metodos set
    void setMes(int);
    void setYear(int);

    int getDia();//metodos get
    int getMes();
    int getYear();

    void diaSiguiente();//otros metodos
    string str();
    int diasMes();
    string mes();
};

Fecha::Fecha(){
    iDia = 0;
    iMes = 0;
    iYear = 0;
}
Fecha::Fecha(int iDiai,int iMesi,int iYeari){
    this ->iDia = iDiai;
    this ->iMes = iMesi;
    this ->iYear = iYeari;
}
void Fecha::setDia(int day){
    iDia = day;
}
void Fecha::setMes(int month){
    iMes = month;
}
void Fecha::setYear(int year){
    iYear = year;
}
int Fecha::getDia(){
    return iDia;
}
int Fecha::getMes(){
    return iMes;
}
int Fecha::getYear(){
    return iYear;
}
string Fecha::str(){
    string day,month;//variables para hora y minuto
    if(iDia<10){
        day = "0"+to_string(iDia);//hora concatenada con 0 en caso de que sea menor a 10
    }
    else{
        day = to_string(iDia);
    }
    if(iMes<10){
        month = "0"+to_string(iMes);//minutos concatenada con 0 en caso de que sea menor a 10
    }
    else{
        month = to_string(iMes);
    }
    return day+"/"+month+"/"+to_string(iYear);//se imprime la hora y minutos
}
void Fecha::diaSiguiente(){//incrementar dias
    while ((1 + iDia) > diasMes()){
        if (iMes == 12){
            iMes = 0;
            iYear++;
        }   
        iMes++;
    }
    iDia += 1;
}
int Fecha::diasMes(){//control de dias del mes
    int month = iMes;
	if(month==2){
		if((iYear%400==0) || (iYear%4==0 && iYear%100!=0))	
			return 29;
		else	
			return 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8||month == 10 || month==12){	
		return 31;
    }
	else{ 		
		return 30;
    }
}
string Fecha::mes(){
    string meses[12] ={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    return meses[iMes-1];
}
