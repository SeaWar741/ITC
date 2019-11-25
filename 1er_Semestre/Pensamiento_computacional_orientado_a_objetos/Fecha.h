//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 24/11/2019
//| Descripcion: Objeto fecha
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include<iostream>
#include<string>
using namespace std;

class Fecha{
private:
    int dia,ms,year;
public:
    Fecha();
    Fecha(int diai,int msi,int yeari);

    int getDia();
    int getMes();
    int getYear();

    void setDia(int diai);
    void setMes(int mesi);
    void setYear(int yeari);

    void diaSiguiente();
    string imprime();
    int diasMes();
    string mes();
};
Fecha::Fecha(){
    dia=1;
    ms=1;
    year=1900;
}
Fecha::Fecha(int diai,int mesi,int yeari){
    dia = diai;
    ms=mesi;
    year=yeari;
}

void Fecha::setDia(int diai){
    dia=diai;
}

void Fecha::setMes(int mesi){
    ms=mesi;
}

void Fecha::setYear(int yeari){
    year=yeari;
}

int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return ms;
}
int Fecha::getYear(){
    return year;
}
void Fecha::diaSiguiente(){
    cout<<"LOL"<<endl;
}
string Fecha::imprime(){
    string date = to_string(dia)+"/"+to_string(ms)+"/"+to_string(year);
    return date;
}
int Fecha::diasMes(){
	int month = ms;
	if(month==2){
		if((year%400==0) || (year%4==0 && year%100!=0))	
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
    return meses[ms-1];
}

bool checkYear(int year) { 
    if (year % 400 == 0) 
        return true; 
    if (year % 100 == 0) 
        return false; 
    if (year % 4 == 0) 
        return true; 
    return false; 
} 