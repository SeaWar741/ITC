//
//  Estudiante.h
//  PolimPersonaMaestroEstudiante
//
//  Created by Yolanda Martinez on 17/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Estudiante_h
#define Estudiante_h

#include "Persona.h"

class Estudiante : public Persona{
public:
    Estudiante();
    Estudiante(string, int, string);
    string getCarrera() { return carrera; }
    void setCarrera(string ca) { carrera = ca; }
    void muestraDatos();

private:
    string carrera;
};

Estudiante::Estudiante() : Persona(){
    carrera = "N/A";
}

Estudiante::Estudiante(string nom, int ed, string ca) : Persona(nom, ed)
{
    carrera = ca;
}

void Estudiante::muestraDatos()
{
    cout << "Nombre: " << nombre << " Edad: " << edad << " Carrera: " << carrera << endl;
}

#endif /* Estudiante_h */
