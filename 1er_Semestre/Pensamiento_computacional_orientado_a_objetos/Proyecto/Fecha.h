#include <iostream>
#include <string>
using namespace std;

class Fecha{
private:
    int iDia,iMes,iYear;
public:
    Fecha();
    Fecha(int,int,int);

    void setDia(int);
    void setMes(int);
    void setYear(int);

    int getDia();
    int getMes();
    int getYear();

    void diaSiguiente();
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
    return to_string(iDia)+"/"+to_string(iMes)+"/"+to_string(iYear);
}
void Fecha::diaSiguiente(){
    while ((1 + iDia) > diasMes()){
        if (iMes == 12){
            iMes = 0;
            iYear++;
        }   
        iMes++;
    }
    iDia += 1;
}
int Fecha::diasMes(){
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
