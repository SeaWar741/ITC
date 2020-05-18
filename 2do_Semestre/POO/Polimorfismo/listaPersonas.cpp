
#include <iostream>
using namespace std;

#include "Estudiante.h"
#include "Maestro.h"

int main(){

    // COMPLETAR: Declara un arreglo de apuntadores a objeto de tipo Persona
    //Persona *Personas[10]; //se crea un arreglo de 10 apuntadores a personas en tiempo compilacion

    int cantPersonas;
    char opcionPersona, opcionMenu;
    int edad, edadIni, edadFin;
    string nombre, carrera, departamento;

    //ESTO NO JALA IMPORTANTE RECORDAR
    //Persona *listaPersonas = new Persona[10]; hace objeto pero no es de apuntadores

    //cout << "Cuantas personas hay? ";
    cin >> cantPersonas;

    Persona *Personas[cantPersonas]; //sucede en tiempo de ejecucion

    for (int c = 0; c < cantPersonas; c++){
        //cout << "a) Estudiante, b) Maestro y c) Ninguno de los dos" << endl;
        cin >> opcionPersona;

        //cout << "Nombre? ";
        cin >> nombre;

        //cout << "Edad? ";
        cin >> edad;

        if (opcionPersona == 'a'){
            //cout << "Carrera? ";
            cin >> carrera;

            // COMPLETAR: Agrega al estudiante a la lista de personas
            Personas[c] = new Estudiante(nombre, edad, carrera);
        }
        else if (opcionPersona == 'b'){
            //cout << "Departamento? ";
            cin >> departamento;

            // COMPLETAR: Agrega al maestro a la lista de personas
            Personas[c] = new Maestro(nombre, edad, departamento);
        }
        else{
            // COMPLETAR: Agrega a la persona a la lista de personas
            Personas[c] = new Persona(nombre, edad);
        }
    }
    do{
        //cout << "Menu de opciones " << endl;
        //cout << endl;
        //cout << "a) muestra todas las personas " << endl;
        //cout << "b) muestra personas en un rango de edad " << endl;
        //cout << "c) terminar " << endl;
        //cout << "opcion -> " << endl;
        cin >> opcionMenu;

        switch (opcionMenu){
            case 'a':{

                // COMPLETAR: Muestra la lista de personas
                // cada persona tiene que mostrarse usando su propia version del muestraDatos
                for (int i = 0; i < cantPersonas; i++){
                    Personas[i]->muestraDatos();
                }

                break;
            }
            case 'b':{
                int edadTmp;
                //cout << "edad inicial ";
                cin >> edadIni;
                //cout << "edad final? ";
                cin >> edadFin;

                // COMPLETAR: Muestra la lista de personas cuya edad cae en el rango especificado
                // cada persona tiene que mostrarse usando su propia version del muestraDatos
                for (int i = 0; i < cantPersonas; i++){
                    int age = Personas[i]->getEdad();
                    if (age >= edadIni && age <= edadFin){
                        Personas[i]->muestraDatos();
                    }
                }
            }
            break;
        }
    }while (opcionMenu != 'c');
    return 0;
}
