#include <iostream>
#include <string>
using namespace std;

class Cumpleanios{
	private:
	    int dia, mes;
	    string despliega;//<--
	public: //Metodo constructor
		Cumpleanios();
		Cumpleanios(int,int);
	//Metodos de modificadores
		void setDia(int);
		void setMes(int);
	//Metodos accesso
		int getDia();
		int getMes();
	//Otros metodos
		string display();//<--
};
//Constructor default
Cumpleanios::Cumpleanios(){
    dia = 1;
    mes = 1;
}
//Constructor con parametros
Cumpleanios::Cumpleanios(int diai, int mesi){
    this -> dia = diai;
    this -> mes=mesi;
}
//Metodos modificadores
void Cumpleanios::setDia(int diai){
    dia=diai;
}
void Cumpleanios::setMes(int mesi){
    mes=mesi;
}
//Metodos de accesso
int Cumpleanios::getDia(){
    return dia;
};
int Cumpleanios::getMes(){
    return mes;
};

//Otros metodos
string Cumpleanios::display(){
    return to_string(dia)+"/"+to_string(mes);//<--
}
