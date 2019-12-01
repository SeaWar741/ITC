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
Fecha::setDia(int day){
    iDia = day;
}
Fecha::setMes(int month){
    iMes = month;
}
Fecha::setYear(int year){
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