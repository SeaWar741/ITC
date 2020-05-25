#ifndef Persona_h
#define Persona_h
using namespace std;

class Persona{
private:
    string nombre, estado, ciudad, cp;

public:
    Persona();
    Persona(string, string, string, string);
    void imprimir();
};
Persona::Persona(){
    nombre,estado,ciudad,cp = "";
}
Persona::Persona(string name, string state, string city, string pc){
    nombre = name;
    estado = state;
    ciudad = city;
    cp = pc;
}
void Persona::imprimir(){
    cout << "Nombre: " << nombre << endl;
    cout << "Dirección: " << estado << " " << ciudad << " " << cp << endl;
}
#endif