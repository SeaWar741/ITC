#include "Cumpleanios.h"
using namespace std;

class Persona{
	private:
		string name,nation;
		int age;
		Cumpleanios cumple;
	public:
		Persona();
		//name, nation, age, cumple
		Persona(string,string,int);
		
		void setName(string);
		void setNation(string);
		void setAge(int);
		void setCumpleanios(Cumpleanios);

        string getName();
		string getNation();
		int getAge();
		string getCumpleanios();
        string display();
};

Persona::Persona(){
	this->name="ND";
    this->nation="ND";
	this->age = 0;
}
Persona::Persona(string namei,string nationi,int agei){
	name = namei;
	nation = nationi;
	age = agei;
}
void Persona::setName(string namei){
    name = namei;
}
void Persona::setNation(string nationi){
    nation=nationi;
}
void Persona::setAge(int agei){
    age=agei;
}
void Persona::setCumpleanios(Cumpleanios cumplei){
    cumple = cumplei;
}
string Persona::getName(){
    return name;
}
string Persona::getNation(){
    return nation;
}
int Persona::getAge(){
    return age;
}
string Persona::getCumpleanios(){
    return cumple.display();
}
string Persona::display(){
    return "Nombre: "+name+"/Nacionalidad: "+nation+"/Fecha nacimiento: "+getCumpleanios();
}
